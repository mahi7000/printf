#include "main.h"

/**
 * percent - print %
 * @specify: list
 * @buffer: array of characters
 * @flags: flags
 * @width: width
 * @precision: precision
 * @length: length modifier
 *
 * Return: 1
 */

int percent(va_list specify, char buffer[],
		int flags, int width, int precision, int length)
{
	UNUSED(specify);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(length);

	return (write(1, "%%", 1));
}
