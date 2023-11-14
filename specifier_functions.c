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
  * print_str - Prints a string
  * @args: Input arguments
  *
  * Return: Length of string
  */

int print_str(va_list args)
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

/*PRINT D*/

/**
 * print_d - Prints an integer.
 * @args: Input arguments.
 *
 * Return: Zero.
 */

int print_d(va_list args)
{
	int i, j;
	char buffer[20];

	int int_value_d = va_arg(args, int);

	if (int_value_d < 0)
	{
		write(1, "-", 1);
		int_value_d = -int_value_d;
	}

	i = 0;

	while (int_value_d > 0)
	{
		buffer[i++] = (int_value_d % 10) + '0';
		int_value_d /= 10;
	}

	for (j = 0; j < i / 2; j++)
	{
		char tmp = buffer[j];

		buffer[j] = buffer[i - j - 1];
		buffer[i - j - 1] = tmp;
	}

	write(1, buffer, i);

	return (0);
}
