#include "main.h"

/**
 * _strdup - function like strdup
 * @str: string
 * Return: the new vercion
 */

char *_strdup(char *str)
{
	int i = 0;
	char *str2;

	str2 = malloc(sizeof(char) * (lenght(str)));
	while (str[i])
	{
		str2[i] = str[i];
		i++;
	}
	return (str2);
}

/**
 * _strncpy - function like strncpy
 * @str2: the new one
 * @str: the string
 * @n: the num
 * Return: new copy
 */

char *_strncpy(char *str2, char *str, int n)
{
	int i = 0;

	while (i != n)
	{
		str2[i] = str[i];
		i++;
	}
	return (str2);
}
