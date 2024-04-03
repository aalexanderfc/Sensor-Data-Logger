#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h> // Include for sscanf
#include <stdlib.h> // Include for atoi function
#include <string.h> // Include for string manipulation functions
#include "serial.h"

#define LED_PIN PB0
#define BUTTON_PIN PB1

int main() {
    DDRB |= (1 << LED_PIN);        // Set LED pin as output
    DDRB &= ~(1 << BUTTON_PIN);    // Set button pin as input
    PORTB |= (1 << BUTTON_PIN);    // Enable pull-up resistor on button pin 

    uart_init();                   // Initialize UART

    while (1) {
        // Read button state
        uint8_t buttonState = (PINB & (1 << BUTTON_PIN));

        // If button is pressed (logic LOW)
        if (!(buttonState)) {
            // Toggle LED
            PORTB ^= (1 << LED_PIN);
            
            // Print LED status to UART
            if (PORTB & (1 << LED_PIN)) {
                uart_putstr("LED turned on.\n");
            } else {
                uart_putstr("LED turned off.\n");
            }
            
            // Delay for debounce
            _delay_ms(200);
        }

        // Read a string from UART until '\n'
        char received_str[64];
        uart_rec_str(received_str, sizeof(received_str));
        
        // Parse the received string for LED power command
        if (strncmp(received_str, "ledpower", 8) == 0) {
            // Extract the power value from the string
            int power = atoi(received_str + 8);

            // Print the received command and parsed power value
            uart_putstr("Received command: ");
            uart_putstr(received_str);
            uart_putstr("Parsed power value: ");
            uart_putchar(power + '0');
            uart_putstr("\n");

            // Check the range of power value
            if (power >= 0 && power <= 255) {
                // Control LED brightness based on power value
                if (power > 127) {
                    PORTB |= (1 << LED_PIN); // Turn on LED
                } else {
                    PORTB &= ~(1 << LED_PIN); // Turn off LED
                }
                
                // Print the power value to UART
                char power_str[16];
                snprintf(power_str, sizeof(power_str), "LED power set to %d.\n", power);
                uart_putstr(power_str);
            } else {
                uart_putstr("Invalid LED power value. Please enter a value between 0 and 255.\n");
            }
        } else {
            uart_putstr("Invalid command. Please enter 'ledpower <value>'.\n");
        }
    }

    return 0;
}
