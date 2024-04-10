#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "serial.h"

#define BUTTON_PIN PB1
#define LED_PIN PB0

int main() {
    // Set pin 8 (PB0) as output (LED pin)
    DDRB |= (1 << DDB0);

    // Set pin 9 (PB1) as input(button pin)
    DDRB &= ~(1 << DDB1);
    PORTB |= (1 << PORTB1); // Enable pull-up resistor

    // Initialize UART
    uart_init();

    // Send a test message over UART
    uart_putstr("UART test message\n");

    char command[64];

    while (1) {
        // Read button state
        uint8_t buttonState = (PINB & (1 << BUTTON_PIN));

        // If button is pressed (logic LOW)
        if (!buttonState) {
            // Toggle LED
            PORTB ^= (1 << LED_PIN);
            uart_putstr("Button pressed, toggling LED.\n");
        }

        // Check if there's a command available over UART
        if (uart_available()) {
            uart_rec_str(command, sizeof(command));
            uart_putstr("Received command: ");
            uart_putstr(command);
            uart_putstr("\n");
                       // Check if the command is "ledpower"
            if (strncmp(command, "ledpower ", 9) == 0) {
                // Parse the power level from the command
                int power = -1;
                sscanf(command + 9, "%d", &power);
                // Check if the power level is within the valid range
                if (power < 0 || power > 255) {
                    uart_putstr("Invalid power level. It should be between 0 and 255.\n");
                    continue;
                }
                char powerStr[4]; // Buffer to hold the power value as a string
                itoa(power, powerStr, 10); // Convert the power value to a string
                uart_putstr("Power level: ");
                uart_putstr(powerStr); // Print the power value
                uart_putstr("\n");
                
                // Set the LED power
                bool ledOn = power > 127;
                if (ledOn) {
                    PORTB |= (1 << LED_PIN); // Turn on LED
                } else {
                    PORTB &= ~(1 << LED_PIN); // Turn off LED
                }
                        }
                    }
                }
            }