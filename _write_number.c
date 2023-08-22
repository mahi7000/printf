#include "main.h"

/**
 * _write_number - Prints a string
 * @is_negative: Lista of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @length: length specifier
 *
 * Return: Number of chars printed
 */
int _write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int length)
{
	int l = BUFF_SIZE - ind - 1;
	char p = ' ', extra_ch = 0;

	UNUSED(length);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		p = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (_write_num(ind, buffer, flags, width, precision,
		length, p, extra_ch));
}

