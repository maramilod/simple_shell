#include "main.h"

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
		write(1, &string[i], 1);
		i++;
	}
}
