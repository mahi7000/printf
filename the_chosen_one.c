#include "main.h"

int string_print(va_list format_specifiers, int count_char);

/**
 * The_chosen - function that matches the format specifiers
 * with parameters of varadic function
 * @format: constant formatable string
 * @format_specifiers: list name
 * @count_char: count of characters
 *
 * Return: count_char
 */

int The_chosen(const char *format, va_list format_specifiers, int count_char)
{
	switch (*format)
	{
		case 'c':
			_putchar(va_arg(format_specifiers, int));
			count_char++;
			break;
		case 's':
			count_char = string_print(format_specifiers, count_char);
			break;
		case '%':
			_putchar('%');
			count_char++;
			break;
		default:
			break;
	}

	return (count_char);
}

/**
 * string_print - function that prints the string and counts the characters
 * @format_specifiers: list
 * @count_char: counts characters
 *
 * Return: count_char
 */

int string_print(va_list format_specifiers, int count_char)
{
	int i;
	char *str = va_arg(format_specifiers, char *);

	i = 0;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
		count_char++;
	}
	return (count_char);
}
