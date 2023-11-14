#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int _printf(const char *format, ...);
int print_char(va_list args);
int print_str(va_list args);
int print_i(va_list args);
int print_d(va_list args);
int print_mod(const char *arg);


/**
 * struct formattings - Struct format_types
 * @specifier: The conversion specifier
 * @func: The function pointer
 */

typedef struct formattings
{
	char specifier;
	int (*func)(va_list args);
} format_data;



#endif
