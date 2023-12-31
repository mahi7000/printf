#include "main.h"

/**
 * get_precision - calculate the precision for printing
 * @format: Formattable string
 * @i: list of arguments
 * @specifiers:
 *
 * Return: precision
 */

int get_precision(const char *format, int *i, va_list specifiers)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
				}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(specifiers, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}

