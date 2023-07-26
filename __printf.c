#include "main.h"

static int printChar(char item);
static int printString(char *str);
static int printIntValue(int value, int base);
int printBinary(unsigned int num);

/**
 * _printf - print input to standard output
 * @format: character string to be printed
 *
 * Return: int
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

					noPrintedChar += printIntValue(num, 10);
					break;
				}
				case 'b':
				{
					unsigned int val = va_arg(args, unsigned int);

					noPrintedChar += printIntValue(val, 2);
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
 * printChar - prints a character to standard output
 * @item : Item or character to print
 * Return: 1 else then 0
 */

static int printChar(char item)
{
	return (write(1, &item, 1));
}


/**
 * printString - Sub-function to print string
 * @str : String to be printed
 * Return: The number of char printed
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
 * printIntValue - function that handles ptinting int
 * @value: The integer to be printed
 * @base: the base value to convert to
 * Return: Return the number of digits printed
 */
static int printIntValue(int value, int base)
{
	int temp = 0;
	unsigned int digits = 0, pow = 0, count = 0, i = 0;

	if (value < 0)
	{
		char c = '-';

		write(1, &c, 1);
		value = -value;
		count++;
	}
	temp = value;
	do {
		digits++;
		temp = temp / base;
	} while (temp != 0);

	while (digits > 0)
	{
		char c;

		pow = 1;
		for (i = 1; i < digits; i++)
			pow *= base;
		count++;
		c = '0' + (int)(value / pow);
		write(1, &c, 1);
		value = value - (value / pow) * pow;
		digits--;
	}
	return (count);
}
/**
 * printBinary - function that handles binary conversion
 * @num: The integer to be printed
 * Return: Return the number of digits printed
 */

int printBinary(unsigned int num)
{
	int count = 0;
	char c;

	if (num == 0)
	{
		return (1);
	}
	count = printBinary(num / 2);
	c = '0' + (num % 2);
	write(1, &c, 1);

	return (count);
}
