#include "main.h"

/**
 * get_length - function that gets the length modifier
 * @format: formattable string
 * @i: printed arguments
 *
 * Return: length
 */

int get_length(const char *format, int *i)
{
	int j;
	int length = 0;

	j = *i + 1;
	if (format[j] == 'l')
		length = S_LONG;
	else if (format[j] == 'h')
		length = S_SHORT;

	if (length == 0)
		*i = j - 1;
	else
		*i = j;

	return (length);
}
