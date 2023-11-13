#include "main.h"

/*PRINT C*/

/**
  * print_char - Prints a character to the standard output
  * @args: Input arguments
  *
  * Return: Length of characters
  */

int print_char(va_list args, int flags, int width, int precision)
{
	char output = va_arg(args, int);

	write(1, &output, 1);
	return (1);
}

/*PRINT S*/

/**
  * print_string - Prints a string
  * @args: A list of variadic arguments
  *
  * @precision: Precision specification
  * @flags: Calculates active flags
  * @width: get width.
  * Return: Length of string
  */

int print_string(va_list args, int flags, int width, int precision)
{
	char *arg = va_arg(args, char *);
	int len_of_str = 0;

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (len_of_str != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
	if (flags & F_MINUS)
	{
		write(1, &str[0], length);
		for (i = width - length; i > 0; i--)
		write(1, " ", 1);
		return (width);
	}
		else
		{
		for (i = width - length; i > 0; i--)
		write(1, " ", 1);
		write(1, &str[0], length);
		return (width);
		}
	}
}

/*PRINT PERCENTAGE SIGN*/

/**
  * print_percent - Prints a percentage sign
  * @args: Input arguments
  *
  * @precision: Precision specification
  * @flags: Calculates active flags
  * @width: get width.
  * Return: Number of chars printed
  */

int print_percent(va_list args, int flags, int width, int precision)
{
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	return (write(1, "%%", 1));
}
