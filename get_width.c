#include "main.h"
/**
 * get_width - function that gets the width
 * @format: formattable string
 * @i: integer
 * @specifiers: list of specifiers
 *
 * Return: width
 */

int get_width(const char *format, int *i, va_list specifiers)
{
	int j;
	int width = 0;

	for (j = 1 + *i; format[j] != '\0'; j++)
	{
		if (is_digit(format[j]))
		{
			width = width * 10;
			width = width + (format[j] - '0');
		}
		else if (format[j] == '*')
		{
			j++;
			width = va_arg(specifiers, int);
			break;
		}
		else
			break;
	}
	*i = j - 1;
	return (width);
}
