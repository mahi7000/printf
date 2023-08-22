#include "main.h"

/**
 * _print - Print an argument based on its type
 * @fmt: Formattable string
 * @specifier: List
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @length: length specifier
 * Return: 1 or 2
 */

int _print(const char *fmt, int *ind, va_list specifier, char buffer[],
		int flags, int width, int precision, int length)
{
	int i, unknow_len = 0, count_char = -1;
	fmt_t fmt_types[] = {
		{'c', character}, {'s', string}, {'%', percent},
		{'i', integer}, {'d', integer}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	{
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(specifier, buffer,
						flags, width, precision, length));
	}

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (count_char);
}
