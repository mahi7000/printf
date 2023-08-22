#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int _printf(const char *format, ...);
void PrintBuffer(char buffer[], int *p_buff);
int get_width(const char *format, int *i, va_list specifiers);
int get_length(const char *format, int *i);
int character(va_list specify, char buffer[],
		int flags, int width, int precision, int length);
int percent(va_list specify, char buffer[],
		int flags, int width, int precision, int length);
int string(va_list specifier, char buffer[],
		int flags, int width, int precision, int length);
int get_precision(const char *format, int *i, va_list specifiers);
int get_flags(const char *format, int *i);

int is_digit(char c);
int _write_char(char c, char buffer[],
		int flags, int width, int precision, int size);

#endif
