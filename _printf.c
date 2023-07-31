#include "main.h"

/**
 * print_char - Prints a character to the standard output
 * @c: The character to be printed
 *
 * Return: The number of characters printed (always 1)
 */

int print_char(const char *c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * print_str - Prints a string to the standard output
 * @str: The string to be printed
 *
 * Return: The number of characters printed
 */

int print_str(const char *str)
{
	int str_len = 0;

	while (str[str_len] != '\0')
		str_len++;

	write(1, str, str_len);
	return (str_len);
}

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed
 */

int _printf(const char *format, ...)
{
	int chara_print = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			chara_print += print_char(*format);
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				chara_print += print_char(*format);
			}
			else if (*format == 'c')
			{
				char c = va_arg(args, int);

				chara_print += print_char(c);
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				chara_print += print_str(str);
			}
		}
		format++;
	}
	va_end(args);
	return (chara_print);
}
