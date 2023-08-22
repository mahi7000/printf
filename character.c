#include "main.h"

/**
 * character - prints a character
 * @specify: list of character
 * @buffer: Buffer
 * @flags: calculates flags
 * @length: length modifier
 * @precision: precision
 * @width: width
 *
 * Return: number of character printed
 */

int character(va_list specify, char buffer[],
		int flags, int width, int precision, int length)
{
	char c = va_arg(specify, int);

	return (_write_char(c, buffer, flags, width, precision, length));
}
