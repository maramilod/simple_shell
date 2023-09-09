#include "main.h"

/**
 * check - function to exit
 * @x: string
 * Return: 1 || 0
 */

int check(char *x)
{
	char ex[] = {"exit"};

	if (same(x, ex) == 0)
	{
		free(x);
		exit(0);
	}
	return (-1);
}
