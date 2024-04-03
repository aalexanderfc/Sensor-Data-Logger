#ifndef SERIAL_H
#define SERIAL_H

#include <avr/io.h>

void uart_init();
void uart_putchar(char data);
void uart_putstr(const char* str);
char uart_getchar();
void uart_echo();
void uart_rec_str(char *str, uint8_t max_length);
uint8_t uart_available();
char uart_readchar();

#endif // SERIAL_H
