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
	int j;
	va_list input_args;

	format_data format_types[] = {
		{ 'c', print_char },
		{ 's', print_string },
	};

	int no_printed_char = 0;

	if (format == NULL)
		return (-1);
	va_start(input_args, format);
	while (*format)
	{
		if (*format == '\0')
			break;
		if (*format != '%')
		{	write(1, format, 1);
			no_printed_char++;
		}
		else
		{	format++;
			if (*format == '%')
			{	write(1, format, 1);
				no_printed_char++;
			}
			for (j = 0; j < 2; j++)
			{
				if ((*format) == format_types[j].specifier)
					no_printed_char += format_types[j].func(input_args);
			}
		} format++;
	}
	va_end(input_args);
	return (no_printed_char);
}

/**
  * print_char - Prints a character to the standard output
  * @args: Input arguments
  *
  * Return: Lenght of characters
  */

int print_char(va_list args)
{
	char output = va_arg(args, int);

	write(1, &output, 1);
	return (1);
}


/**
  * print_string - Prints a string
  * @args: A list of variadic arguments
  *
  * Return: Length of string
  */

int print_string(va_list args)
{
	char *arg = va_arg(args, char *);
	int len_of_str = 0;

	while (arg[len_of_str] != '\0')
		len_of_str++;

	write(1, arg, len_of_str);
	return (len_of_str);
}
