#include "main.h"

/**
 * string - prtints string
 * @specify: list
 * @buffer: array of characters
 * @flags: flags
 * @width: width
 * @precision: precision
 * @length: length modifiers
 *
 * Return: number of character in string
 */

int string(va_list specify, char buffer[],
		int flags, int width, int precision, int length)
{
	int l = 0;
	int i;
	char *str = va_arg(specify, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(length);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[l] != '\0')
		l++;
	if (precision >= 0 && precision < l)
		l = precision;
	if (width > l)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], l);

			for (i = width - l; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - l; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], l);
			return (width);
		}
	}
	return (write(1, str, length));
}
