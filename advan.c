#include "main.h"

/**
 * _getline - function
 * @lin: the line well read
 * @l: the memory
 * @fn: the stdin
 * Return: the new line
 */

ssize_t _getline(char **lin, size_t l, int fn)
{
	ssize_t br, tr = 0;

	if (lin == NULL || l == 0 || fn < 0)
		return (-1);

	*lin = malloc(l * sizeof(char));

	if (*lin == NULL)
	{
		return (-1);
	}

	while ((br = read(fn, *lin + tr, 1)) > 0)
	{
		tr += br;
		if (tr >= (ssize_t)l || (*lin)[tr -1] == '\n')
		{
			break;
		}
	}

	if (tr == 0 || tr >= (ssize_t)l)
	{
		free(*lin);
		return (-1);
	}

	(*lin)[tr] = '\0';

	return (tr);
}

/**
 * same - function
 */

int same(char *w, char *m)
{
	size_t lw = 0, lm = 0;
	
	if (w == NULL || m == NULL)
	{
		return (-1);
	}
	lw = lenght(w);
	lm = lenght(m);
	
	if (lw != lm)
	{
		return (-1);
	}
	if (_strncm(w, m, lw) == 0)
	{
		return (0);
	}
	
	return (-1);
}

/**
 * cd - function to change directory
 * @env: the path
 * @str: the second value to
 * Return: 0
 */

int cd(char *str)
{
	if (str)
	{
		chdir(str);
	}
	return (0);

}
