#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: constant character string
 * @...: variable format specifier
 * Author: Mahlet Belay and Mahlet Masresha
 *
 * Return: the number of characters printed, excluding the null byte
 */

int _printf(const char *format, ...)
{
	int count_char;
	va_list format_specifiers;

	if (format == NULL)
		return (-1);

	va_start(format_specifiers, format);

	count_char = 0;
	while (format && *format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count_char = The_chosen(format, format_specifiers, count_char);
			format++;
		}
		else
		{
			_putchar(*format);
			count_char++;
			format++;
		}
	}

	va_end(format_specifiers);
	return (count_char);
}
