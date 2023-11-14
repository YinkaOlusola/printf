#include "main.h"

/**
 * _printf - Writes a function that produces output according to a format.
 * @format: The formatting to apply to the input
 *
 * Return: The number of characters printed.
 *
 */

int _printf(const char *format, ...)
{
	int j, no_printed_char = 0;
	va_list input_args;

	format_data format_types[] = {
		{ 'c', print_char }, { 's', print_string }
	};
	va_start(input_args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && (format[1] == ' ') && !format[2])
		return (-1);
	while (*format)
	{
		if (*format == '\0')
			break;
		if (*format != '%')
		{	write(1, format, 1);
			no_printed_char++; }
		else
		{	format++;
			if (*format == '%')
			{	write(1, format, 1);
				no_printed_char++; }
			else
			{
				for (j = 0; j < 3; j++)
				{
					if ((*format) == format_types[j].specifier)
					{	no_printed_char += format_types[j].func(input_args);
						break; }
					else if (((*format) != format_types[j].specifier) && (j >= 1))
					{	write(1, "%", 1);
						write(1, format, 1);
						no_printed_char += 2; }
				}
			}
		} format++;
	}
	va_end(input_args);
	return (no_printed_char);
}
