#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int _printf(const char *format, ...);
void print_char(va_list args, int *no_char_printed);
void print_string(va_list args, int *no_char_printed);


/**
 * struct format_types - Struct format_types
 * @identifier: The conversion specifier
 * @f: The function pointer
 */

typedef struct formattings
{
	char specifier;
	void (*func)(va_list args, int* no_printed_char);
} format_data;



#endif
