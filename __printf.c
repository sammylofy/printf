#include "main.h"

static int printChar(char item);
static int printString(char *str);
static int printIntValue(int value);

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
		return (-1);

	while (*format && format[i] != '\0')
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
			else if (s == 'd')
			{
				int num = va_arg(args, int);

				noPrintedChar += printIntValue(num);
			}
			else if (s == 'i')
			{
				int val = va_arg(args, int);
				noPrintedChar += printIntValue(val);
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
		return (-1);
	}
	else
	{
		while (*str)
		{
			noOfCharPrinted += printChar(*str);
			str++;
		}
	}

	return (noOfCharPrinted);
}
/**
 * printIntValue - Function that handles ptinting int
 * @value: The integer to be printed
 * Return: The number of digits printed
 */
static int printIntValue(int value)
{
	int digits = 0;

	if (value < 0)
	{
		printChar('-');
		value = -value;
	}
	if (value < 10)
	{
		printChar('0' + value);
		return (1);
	}
	digits = printIntValue(value / 10);
	printChar('0' + value % 10);
	return (digits + 1);
}
