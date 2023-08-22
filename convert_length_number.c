#include "main.h"

/**
 * convert_length_number - length
 * @num: number
 * @length: length modifier
 *
 * Return: num
 */

long int convert_length_number(long int num, int length)
{
	if (length == S_LONG)
		return (num);
	else if (length == S_SHORT)
		return ((short)num);

	return ((int)num);
}

