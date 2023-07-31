#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_char(const char c);
int print_str(const char *str);
int binary(int num);
int octal(int num);

#endif
