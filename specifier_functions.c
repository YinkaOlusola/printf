#include "main.h"

/*PRINT C*/

/**
  * print_char - Prints a character to the standard output
  * @args: Input arguments
  *
  * Return: Lenght of characters
  */

int print_char(va_list args)
{
	char output = va_arg(args, int);

	if (sizeof(output) != sizeof(char))
		output = (char)output;

	write(1, &output, 1);
	return (1);
}

/*PRINT S*/

/**
  * print_string - Prints a string
  * @args: Input arguments
  *
  * Return: Length of string
  */

int print_string(va_list args)
{
	char *arg = va_arg(args, char *);
	int len_of_str = 0;

	if (arg == NULL)
	{
		char *str;

		str = "(null)";
		while (str[len_of_str] != '\0')
			len_of_str++;
		write(1, str, len_of_str);
	}
	else
	{
		while (arg[len_of_str] != '\0')
			len_of_str++;
		write(1, arg, len_of_str);
	}
	return (len_of_str);
}
