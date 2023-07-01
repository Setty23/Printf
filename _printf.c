#include "main.h"

/**
 * _printf - Custom printf function.
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char specifier;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			specifier = *format;
			count += _format_out(specifier, args);
		}
		else
		{
			count += _putchar(*format);
		}

		format++;
	}

	va_end(args);
	return (count);
}


/**
 * _format_out - Handles the conversion specifiers and outputs the result.
 * @specifier: The conversion specifier character.
 * @args: The list of arguments.
 *
 * Return: The number of characters printed.
 */
int _format_out(char specifier, va_list args)
{
	switch (specifier)
	{
	case 'c':
		return (_putchar(va_arg(args, int)));
	case 's':
		return (_puts(va_arg(args, char *)));
	case 'd':
	case 'i':
		return (_print_decimal(args));
	case '%':
		return (_putchar('%'));
	case 'u':
		return (_print_Unsignd(args));
	default:
		return (_putchar('%') + _putchar(specifier));
	}
}
