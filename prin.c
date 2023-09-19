#include "main.h"
/**
 * puti - function
 *
 * @num: integer
 */
void puti(int num)
{
	int j, i = 0;
	char number[20];
	char temp;

	do {
		number[i++] = '0' + (num % 10);
		num /= 10;
	} while (num > 0);

	for (j = 0; j < i / 2; j++)
	{
		temp = number[j];
		number[j] = number[i - j - 1];
		number[i - j - 1] = temp;
	}
	write(STDERR_FILENO, number, i);
}
/**
 * putsss - function
 * @string: s
 */
void putsss(char *string)
{
	int i = 0;

	while (string[i])
	{
		write(STDERR_FILENO, &string[i], 1);
		i++;
	}
}
/**
 * putss - function
 * @string: string!
 * Return: prints return void
 */

void putss(char *string)
{
	int i = 0;

	while (string[i])
	{
		write(STDOUT_FILENO, &string[i], 1);
		i++;
	}
}
/**
 * _printf - function
 * @arg: argument
 * Return: 0
 */
int _printf(char *arg, ...)
{
	va_list args;
	int i, num_arg;
	char *x;
	int j;

	num_arg = lenght(arg);
	va_start(args, arg);

	for (i = 0; i < num_arg; i++)
	{
		if (arg[i] == 'd')
		{
			j = va_arg(args, int);
			puti(j);
		}
		else
		{
			x = va_arg(args, char *);
			putsss(x);
		}
	}
	va_end(args);
	return (0);
}
