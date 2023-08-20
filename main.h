#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int _putchar(char c);
int _printf(const char *format, ...);
int The_chosen(const char *format, va_list format_specifiers, int count_char);
int string_print(va_list format_specifiers, int count_char);

#endif
