#include <avr/io.h>
#include <util/delay.h>
#include "serial.h"

int main() {
    // Set pin 8 (PB0) as output for LED
    DDRB |= (1 << DDB0);

    // Set pin 9 (PB1) as input for button
    DDRB &= ~(1 << DDB1);
    PORTB |= (1 << PORTB1); // Enable pull-up resistor

    uart_init(); // Initialize UART

    while (true) {
        // Check if button is pressed
        if (!(PINB & (1 << PINB1))) {
            // Toggle LED
            PORTB ^= (1 << PORTB0);
            _delay_ms(200); // Delay to avoid bouncing
        }

        // Test uart_putstr function
        uart_putstr("Hello, world!");
        _delay_ms(1000); // Delay 1 second
    }

    return 0;
}
