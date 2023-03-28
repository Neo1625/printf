#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int _printc(va_list c);
int _prints(va_list s);
int _printl(void);
int _printf(const char *format, ...);

/**
 * _printc - Prints a character
 * @c: Argument list.
 *
 * Return: Returns the number of characters printed.
 */
int _printc(va_list c)
{
	char ret;

	ret = va_arg(c, int);

	write(STDOUT_FILENO, &ret, 1);

	return (1);
}

/**
 * _printl - Function that prints '%'.
 *
 * Return: Return number of characters printed.
 */
int _printl(void)
{
	char per;

	per = '%';

	write(STDOUT_FILENO, &per, 1);

	return (1);
}

/**
 * _prints - Function that prints a string
 * @s: Argument list
 *
 * Return: Returns the number of characters printed.
 */
int _prints(va_list s)
{
	char *str;

	str = va_arg(s, char *);

	if (str == NULL)
	{
		write(STDOUT_FILENO, "(null)", strlen("(null)"));
	}

	write(STDOUT_FILENO, str, strlen(str));

	return (strlen(str));
}



/**
 * _printf - Function that produces output accordong to a format.
 * @format: Character string.
 *
 * Return: Returns the number of characters printed
 */
int _printf(const char *format, ...)
{

	int i, total_chars_printed = 0;

	va_list a_list;

	va_start(a_list, format);

	if (format == NULL)
	{
		return (-1);
	}

	i = 0;
	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				total_chars_printed += _printc(a_list);
			}
			else if (format[i] == 's')
			{
				total_chars_printed += _prints(a_list);
			}
			else if (format[i] == '%')
			{
				total_chars_printed += _printl();
			}
			else
			{
				i--;
				write(STDOUT_FILENO, "%", 1);
				total_chars_printed++;
			}
		}
		else
		{
			write(STDOUT_FILENO, &format[i], 1);
			total_chars_printed++;
		}
		i++;
	}

	va_end(a_list);

	return (total_chars_printed);
}


