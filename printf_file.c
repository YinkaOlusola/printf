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
	int j, char_printed;
	va_list input_args;

	format_data format_types[] = {
		{ "c", print_char },
		{ "s", print_string },
	};

	int *no_printed_char = NULL;

	no_printed_char = (int *)malloc(sizeof(int));
	*no_printed_char = 0;
	if (format == NULL)
		return (-1);
	va_start(input_args, format);
	while (*format)
	{
		if (*format == '\0')
			break;
		if (*format != '%')
		{	write(1, format, 1);
			(*no_printed_char)++;
		}
		else
		{	format++;
			if (*format == '%')
			{	write(1, format, 1);
				(*no_printed_char)++;
			}
			for (j = 0; j < 2; j++)
			{
				if (format == format_types[j].specifier)
					format_types[j].func(input_args, no_printed_char);
			}
		} format++;
	}
	va_end(input_args);
	char_printed = *no_printed_char;
	free(no_printed_char);
	return (char_printed);
}

/**
  * print_char - Prints a character to the standard output
  * @args: Input arguments
  * @no_char_printed: Number of characters printed so far.
  *
  * Return: Nothing
  */

void print_char(va_list args, int *no_char_printed)
{
	char output = va_arg(args, int);

	write(1, &output, 1);
	(*no_char_printed)++;
}


/**
  * print_string - Prints a string
  * @args: A list of variadic arguments
  * @no_char_printed: Number of characters printed so far.
  *
  * Return: Nothing
  */

void print_string(va_list args, int *no_char_printed)
{
	char *arg = va_arg(args, char *);
	int len_of_str = 0;

	while (arg[len_of_str] != '\0')
		len_of_str++;

	write(1, arg, len_of_str);
	*no_char_printed += len_of_str;
}
