#include "main.h"

/**
 * excv - function to excute
 * @str: value
 * @argv: string
 * Return: always 0 | -1
 */

int excv(char *str, char **argv)
{
	pid_t pid;

	if (!str)
	{
		return (0);
	}
	str = pathy(str);
	if (str)
	{
		pid = fork();
		if (pid == 0)
		{
			execve(str, argv, NULL);
		}
		else if (pid > 0)
		{
			wait(NULL);
			return (0);
		}
	}
	return (-1);
}

/**
 * moge - my own get env function
 * @path: PATH
 * Return: the path
 */

char *moge(char *path)
{
	int l = 0, lco = 0, s;
	char **pathy;
	char *copy, *new;

	l = lenght(path);
	pathy = environ;
	while (*pathy)
	{
		s = _strncm(path, *pathy, l);
		if (s == 0 && (*pathy)[l] == '=')
		{
			copy = (*pathy) + l + 1;
			lco = lenght(copy);
			new = malloc(sizeof(char) * (lco + 1));
			_strcopy(new, copy);
			return (new);
		}
		pathy++;
	}
	return (NULL);
}

/**
 * pathy - function handle the path
 * @arg: string say if it's a ath or not
 * Return: importnt
 */

char *pathy(char *arg)
{
	char *bigpath = NULL, *or = NULL;
	char *path = NULL, *buff = NULL;

	if (access(arg, F_OK) != -1)
	{
		return (arg);
	}
	buff = malloc(sizeof(char) * 1024);
	bigpath = moge("PATH");

	if (bigpath != NULL && same(bigpath, "") != 0)
	{
		or = strdup(bigpath);
		path = strtok(or, ":");
		while (path)
		{
			strncpy(buff, path, 1024);
			_strcat(buff, "/");
			_strcat(buff, arg);

			if (access(buff, F_OK) != -1)
			{
				free(or);
				return (buff);
			}
			path = strtok(NULL, ":");
		}
	}
	free(or);
	return (NULL);
}
