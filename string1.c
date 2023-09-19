#include "main.h"

/**
 * _strncm - strncmp function
 * @s1: fisrt str
 * @s2: sec
 * @t: num
 * Return: 0 if same the sub if not
 */

int _strncm(char *s1, char *s2, int t)
{
	int i = 0;

	while (i < t)
	{
		if (!s1[i] && !s2[i])
			return (0);
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/**
 * lenght - strlen function
 * @k: the string
 * Return: int
 */

int lenght(char *k)
{
	int i = 0;

	if (k == NULL)
	{
		return (0);
	}

	while (*k++)
	{
		i++;
	}
	return (i);
}

/**
 * _strcat - smae strcat function
 * @buffer: the storage
 * @add: the string
 * Return: the buffer
 */

char *_strcat(char *buffer, char *add)
{
	int i, j;

	for (i = 0; buffer[i] &&
			buffer[i] != '\n'; i++)
		;
	for (j = 0; j < lenght(add); j++)
	{
		buffer[i] = add[j];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

/**
 * _strcopy - like strcpy fun
 * @buffer: first
 * @newcopy: second
 * Return: the new vircon
 */

char *_strcopy(char *buffer, char *newcopy)
{
	int i = 0;

	while (buffer == newcopy || newcopy == 0)
	{
		return (buffer);
	}
	while (newcopy[i])
	{
		buffer[i] = newcopy[i];
		i++;
	}
	buffer[i] = 0;
	return (buffer);
}

