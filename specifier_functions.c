#include "main.h"

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
