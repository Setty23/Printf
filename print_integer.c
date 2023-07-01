#include "main.h"

/**
 * _print_decimal - Prints a decimal number %d and %i
 * @args: The list of arguments
 * Return: Number of characters printed
 */
int _print_decimal(va_list args)
{
	int num;
	int count = 0;
	int div = 1;


	num = va_arg(args, int);

	if (num == 0)
	{
		count += _putchar('0');
		return (count);
	}
	if (num < 0)
	{
		num = -num;
		count += _putchar('-');
	}

	while (num / div > 9)
		divisor *= 10;

	while (div != 0)
	{
		count += _putchar('0' + (num / div));
		num %= div;
		div /= 10;
	}

	return (count);
}

/**
 * spec_format - Handles the conversion specifiers of "d" and "i"
 * @format: the format string
 * @args: the list of arguments
 * Return: number of characters printed
 */
int spec_format(const char *format, va_list args)
{
	int count = 0;
	int i = 0;

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'd' || format[i] == 'i')
				count += _print_decimal(args);
			else
			{
				count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		else
			count += _putchar(format[i]);
		i++;
	}

	return (count);
}
