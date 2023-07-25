#include "main.h"

static int printChar(char item);
static int printString(char *str);
static int printIntValue(int value);
int printBinary(unsigned int num);

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

			switch (s)
			{
				case 'c':
				{
					char ch = va_arg(args, int);

					noPrintedChar += printChar(ch);
					break;
				}
				case 's':
				{
					char *str = va_arg(args, char*);

					noPrintedChar += printString(str);
					break;
				}
				case 'd':
				case 'i':

				{
					int num = va_arg(args, int);

					noPrintedChar += printIntValue(num);
					break;
				}
				case 'b':
				{
					unsigned int val = va_arg(args, unsigned int);

					noPrintedChar += printBinary(val);
					break;
				}
				case '%':
				{
					noPrintedChar += printChar('%');
					break;
				}
				default:
				{
					noPrintedChar += printChar('%');
					noPrintedChar += printChar(format[i]);
					break;
				}
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
		digits++;
	}
	if (value < 10)
	{
		printChar('0' + value);
		return (1);
	}
	digits = printIntValue(value / 10);
	printChar('0' + value % 10);
	return (digits);
}
/**
 * printBinary - Function that handles binary conversion
 * @num: The integer to be printed
 * Return: The number of digits printed
 */

int printBinary(unsigned int num)
{
	int count = 0;

	if (num == 0)
	{
		return (1);
	}
	count = printBinary(num / 2);
	printChar('0' + num % 2);

	return (count);
}
