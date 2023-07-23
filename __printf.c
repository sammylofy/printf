#include "main.h"

static int printChar(char item);
static int printString(char* str);

/**
 * _printf - Function to print values according to specifiers
 * @format: the format received
 * Return: The number of character printed excluding the null byte
 */
int _printf(const char *format, ...)
{
	int noPrintedChar = 0;
	int i = 0;
	char s;

	va_list args;

	va_start(args, format);

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
 * printChar - helper function to print a char
 * @item : item or character to print
 * Return: 1 else 0
 */

static int printChar(char item)
{
	return (write(1, &item, 1));
}


/**
 * printString - Helper function to print string
 * @str : String to be printed
 * Return: the number of char printed
 */

static int printString(char* str)
{
	int noOfCharPrinted = 0;

	do {
		noOfCharPrinted += printChar(*str);
		str++;
	} while (*str);

	return (noOfCharPrinted);
}
