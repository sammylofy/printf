#include "main.h"

static int printChar(char item);
static int printString(char *str);

/**
 * _printf - a custom implementation of printf
 * @format: input string
 *
 * Return: number of characters to be printed
 */
int _printf(const char *format, ...)
{

	int noPrintedChar = 0;
	int i = 0;
	char s;

	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (0);

	while (format[i] != '\0')
	{
		s = format[i];

		if (s == '%')
		{
			++i;

			s = format[i];

			if (s == 'c')
			{
				char ch = va_arg(args, int);

				noPrintedChar += printChar(ch);
			}
			else if (s == 's')
			{
				char *str = va_arg(args, char*);

				noPrintedChar += printString(str);
			}
			else if (s == '%')
			{
				noPrintedChar += printChar('%');
			}
			else
			{
				noPrintedChar += printChar('%');
				noPrintedChar += printChar(format[i]);
			}
		}
		else
		{
			noPrintedChar += printChar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (noPrintedChar);
}

/**
 * printChar - sub-function to print characters
 * @item : item or character to print
 * Return: 1 else 0
 */

static int printChar(char item)
{
	return (write(1, &item, 1));
}


/**
 * printString - sub-function to print string
 * @str : string to be printed
 * Return: the number of char printed
 */

static int printString(char *str)
{
	int noOfCharPrinted = 0;

	if (str == NULL)
	{
		return (0);
	}
	else
	{
		do {
			noOfCharPrinted += printChar(*str);
			str++;
		} while (*str);
	}

	return (noOfCharPrinted);
}
