#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent();


/**
 * struct format_types - Struct format_types
 * @identifier: The conversion specifier
 * @f: The function pointer
 */

typedef struct formattings
{
	char specifier;
	int (*func)(va_list args);
} format_data;



#endif
