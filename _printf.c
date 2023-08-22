#include "main.h"

void PrintBuffer(char buffer[], int *p_buff);

/**
 * _printf - formatted output function
 * @format: formattable string
 * @...: variable that replaces format specifiers
 *
 * Return: number of printed characters
 */

int _printf(const char *format, ...)
{
	int i;
	int nopr = 0, count = 0;
	int flags, width, precision, length, p_buff = 0;

	va_list specifiers;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(specifiers, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[p_buff++] = format[i];
			if (p_buff == BUFF_SIZE)
				PrintBuffer(buffer, &p_buff);
			/*write(1, &format[i], 1);*/
			count++;
		}
		else
		{
			PrintBuffer(buffer, &p_buff);
			flags = get_flags(format, &i);
			width = get_width(format, &i, specifiers);
			precision = get_precision(format, &i, specifiers);
			length = get_length(format, &i);
			++i;

			nopr = _print(format, &i, specifiers, buffer,
					flags, width, precision, length);
			if (nopr == -1)
				return (-1);
			count += nopr;
		}
	}

	PrintBuffer(buffer, &p_buff);

	va_end(specifiers);

	return (count);
}

/**
 * PrintBuffer - function of buffer
 * @buffer: array of characters (string)
 * @p_buff: pointer to integer which is index
 *
 * Return: void
 */

void PrintBuffer(char buffer[], int *p_buff)
{
	if (*p_buff > 0)
		write(1, &buffer[0], *p_buff);

	*p_buff = 0;
}
