#include "main.h"

/**
 * integer - Prints integer
 * @specify: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @length: length modifier
 *
 * Return: Number of characters printed
 */
int integer(va_list specify, char buffer[],
	int flags, int width, int precision, int length)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int j = va_arg(types, long int);
	unsigned long int num;

	j = convert_length_number(j, length);

	if (j == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)j;

	if (j < 0)
	{
		num = (unsigned long int)((-1) * j);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (_write_number(is_negative, i, buffer,
				flags, width, precision, length));
}
