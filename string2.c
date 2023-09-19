#include "main.h"

/**
 * _strdup - function like strdup
 * @str: string
 * Return: the new vercion
 */

char *_strdup(char *str)
{
	int lenght = 0;
	char *res;

	if (str == NULL)
	{
		return (NULL);
	}
	while (*str++)
	{
		lenght++;
	}
	res = malloc(sizeof(char) * (lenght + 1));
	if (!res)
	{
		return (NULL);
	}
	for (lenght++; lenght--;)
	{
		res[lenght] = *--str;
	}
	return (res);
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

	while (i < n && str[i] != '\0')
	{
		str2[i] = str[i];
		i++;
	}
	while (i < n)
	{
		str2[i] = '\0';
		i++;
	}

	return (str2);
}
