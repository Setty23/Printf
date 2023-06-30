#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

int _printf(const char *format, ...);
int _putchar(int c);
int _puts(char *str);
int _print_decimal(va_list args);
int spec_format(const char *format, va_list args);
int _print_Unsignd(va_list args);
int _format_out(char specifier, va_list args);
int _handle_custom_specifier(char specifier, va_list args);


#endif /* MAIN_H */
