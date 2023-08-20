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
	int buff, width, precision, flags;
	buff = 0;
	va_list format_specifiers;

	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(format_specifiers, format);

	count_char = 0;
	while (format && *format != '\0')
	{
		if (*format != '%')
		{
			buffer[buff++] = *format;
			if (buff == BUFF_SIZE)
				buffer_print(buffer, &buff);
			count_char++;
		}
		else
		{
			print_buffer(buffer, &buff);
			flags = get
		}
		format++;
	}

	va_end(format_specifiers);
	return (count_char);
}
