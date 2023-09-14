#include "main.h"

/**
 * _strdup - function like strdup
 * @str: string
 * Return: the new vercion
 */

char *_strdup(char *str)
{
	int i = 0, l;
	char *str2;

	if (str == NULL)
	{
		return (NULL);
	}
	l = lenght(str);
	str2 = malloc(sizeof(char) * (l + 1));

	if (!str2)
	{
		return (NULL);
	}
	else
	{
		while (i <= l)
		{
			str2[i] = str[i];
			i++;
		}
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
