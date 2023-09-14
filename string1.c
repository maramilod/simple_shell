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
 * same - function say if equals
 * @w: first
 * @m: second
 * Return: 1| 0
 */

int samey(const char *w, char *m)
{
	size_t  a = 0, b = 0, i = 0;

	if (w == NULL || m == NULL)
	{
		return (-1);
	}
	while (w[a] != '\n' && w[a])
	{
		a++;
	}
	while (m[b])
	{
		b++;
	}
	if (a == b)
	{
		while (w[i] == m[i] && w[i] != '\0' && m[i] != '\0')
		{
			i++;
		}
	}
	else
	{
		return (-1);
	}
	if (i == a && i == b)
	{
		return (0);
	}
	return (-1);
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

	while (k[i] != '\0')
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

	while (newcopy[i] && newcopy[i] != '\n')
	{
		buffer[i] = newcopy[i];
		i++;
	}
	newcopy[i] = '\0';
	return (newcopy);
}

