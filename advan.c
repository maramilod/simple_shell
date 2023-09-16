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
 * excute - function
 * @file: filename
 * @argv: string
 * @list: the env list
 * Return: void
 */

void excute(char *file, char **argv, env_l *list)
{
	int fd = -1, space = 0, er = 0, le = 0;
	size_t  l = 1024;
	char *li = NULL, *lin = NULL;
	ssize_t r;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(file);
		return;
	}


	while ((r = _getline(&lin, l, fd)) != -1)
	{
		space = hand_space(lin, argv[0], &list, er);
		if (space == -1)
		{
			le = lenght(lin);
			li = malloc(sizeof(char) * le);
			li = ifnotexcv(lin);
			_printf("ccdccc", argv[0], ": ", er, ": ", li, ": not found\n");
			free(li);
			er++;
		}
	}
	close(fd);
}
