#include "main.h"


char format_string(va_list specifiers, int count_str);

/**
 * choice - the function produce the out put
 * @format: formattable string
 * @count_char: count character
 *
 * Return: count char
 */
int choice(const char *format, int count_char)
{
	switch
	{
		case 'c':
			_putchar(va_arg(specifiers, int));
			count_char++;
			break;
		case 's':
			format_string(specifiers, count_char);
		count_char += format_string(specifers, count_char);
			break;
		case '%':
			_putchar('%');
			break;
		default;
			break;
	}
	return (count_char);
}

/**
 * format_string - proudce the out put
 * @specifiers: list
 * @count_str: count string
 * Return: count_str
 */

int format_string(va_list specifiers, int count_str)
{
	int i;
	char *str;

	str = va_arg(specifiers, char *);

	i = 0;
	while (str[i] != '\0')
	{
		if (*str == NULL)
			return ("");
		_putchar(str[i]);
		i++;
		count_str++;
	}
	return (count_str);
}
