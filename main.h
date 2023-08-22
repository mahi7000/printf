#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - struct function
 * @fmt: format
 * @fn: function
 */

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - struct
 * @fmt: format
 * @fm_t: function format
 */

typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int get_width(const char *format, int *i, va_list specifiers);
int get_length(const char *format, int *i);
int character(va_list specify, char buffer[],
		int flags, int width, int precision, int length);
int percent(va_list specify, char buffer[],
		int flags, int width, int precision, int length);
int string(va_list specify, char buffer[],
		int flags, int width, int precision, int length);
int get_precision(const char *format, int *i, va_list specifiers);
int get_flags(const char *format, int *i);

int is_digit(char c);
int is_printable(char c);
int _write_char(char c, char buffer[],
		int flags, int width, int precision, int size);
int _print(const char *fmt, int *ind, va_list specifiers, char buffer[],
	int flags, int width, int precision, int length);
int _write_num(int ind, char buffer[],
	int flags, int width, int precision,
	int length, char padd, char extra_c);
int integer(va_list specify, char buffer[],
		int flags, int width, int precision, int length);
long int convert_length_number(long int num, int length);
int _write_number(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int length);

#endif
