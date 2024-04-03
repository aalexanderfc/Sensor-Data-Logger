#include "serial.h"

#define UART_BUFFER_SIZE 64

char uart_buffer[UART_BUFFER_SIZE];
uint8_t uart_buffer_index = 0;

void uart_init() {
    // Set baud rate to 9600
    UBRR0H = (unsigned char)(103 >> 8);
    UBRR0L = (unsigned char)(103);
    // Enable transmitter and receiver
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);
    // Set frame format: 8 data bits, 1 stop bit, no parity
    UCSR0C = (3 << UCSZ00);
}

void uart_putchar(char data) {
    // Wait for empty transmit buffer
    while (!(UCSR0A & (1 << UDRE0)));
    // Put data into buffer, sends the data
    UDR0 = data;
}

void uart_putstr(const char* str) {
    // Loop through each character in the string
    while (*str != '\0') {
        // Send each character
        uart_putchar(*str);
        str++;
    }
    // Send newline character
    uart_putchar('\n');
}

char uart_getchar() {
    // Wait for data to be received
    while (!(UCSR0A & (1 << RXC0)));
    // Get and return received data from buffer
    return UDR0;
}

void uart_echo() {
    char received_char = uart_getchar();
    // Echo back the received character
    uart_putchar(received_char);
}

void uart_rec_str(char *str, uint8_t max_length) {
    uint8_t i = 0;
    while (1) {
        if (uart_available()) {
            char c = uart_readchar();
            if (c == '\n' || i == max_length - 1) {
                str[i] = '\0'; // Null terminate the string
                return;
            } else {
                str[i++] = c;
            }
        }
    }
}

uint8_t uart_available() {
    return (UCSR0A & (1 << RXC0));
}

char uart_readchar() {
    while (!uart_available()); // Wait until a character is available
    return UDR0;
}
