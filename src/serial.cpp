#include <avr/io.h>
#include "serial.h"

void uart_init() {
    // Set baud rate to 9600
    UBRR0 = 103;

    // Enable transmitter
    UCSR0B |= (1 << TXEN0);

    // Set frame format: 8data, 1stop bit
    UCSR0C = (3 << UCSZ00);
}

void uart_putchar(char c) {
    // Wait for empty transmit buffer
    while (!(UCSR0A & (1 << UDRE0)))
        ;
    // Put data into buffer, sends the data
    UDR0 = c;
}

void uart_putstr(const char* str) {
    while (*str != '\0') {
        uart_putchar(*str);
        str++;
    }
    uart_putchar('\n'); // Add newline at the end
}
