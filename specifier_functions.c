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
	int i = 0, j;
	char buffer[20];

	int int_value_d = va_arg(args, int);

	if (int_value_d < 0)
	{
		write(1, "-", 1);
		int_value_d = -int_value_d;
	}

	do {
		buffer[i++] = (int_value_d % 10) + '0';
		int_value_d /= 10;
	} while (int_value_d > 0);

	for (j = 0; j < (i / 2); j++)
	{
		char tmp;

		tmp = buffer[j];
		buffer[j] = buffer[i - j - 1];
		buffer[i - j - 1] = tmp;
	}
	write(1, buffer, i);
	return (i);
}

/*PRINT I*/

/**
 * print_mod - Prints the output for an unknown specifier.
 * @arg: The input argument.
 *
 * Return: Number of characters printed.
 */

int print_mod(const char *arg)
{
	write(1, "%", 1);
	write(1, arg, 1);

	return (2);
}


/**
 * print_i - Prints an integer.
 * @args: Input arguments.
 *
 * Return: Zero.
 */

int print_i(va_list args)
{
	int i = 0, j;
	char buffer[20];

	int value_i = va_arg(args, int);

	do {
		buffer[i++] = (value_i % 10) + '0';
		value_i /= 10;
	} while (value_i > 0);

	for (j = 0; j < (i / 2); j++)
	{
		char tmp;

		tmp = buffer[j];
		buffer[j] = buffer[i - j - 1];
		buffer[i - j - 1] = tmp;
	}
	write(1, buffer, i);

	return (i);
}
