#include "main.h"

/**
 * excv - function to excute
 * @str: value
 * @argv: string
 * Return: always 0 | -1
 */

int excv(char *str, char **argv, env_l **env)
{
	pid_t pid;

	if (!str)
	{
		return (0);
	}
	str = pathy(str, env);
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
	free(str);
	return (-1);
}

/**
 * moge - my own get env function
 * @path: PATH
 * Return: the path
 */

char *moge(char *path, env_l **env)
{
	int l = 0, lco = 0, s;
	env_l *pathy;
	char *copy, *new;

	l = lenght(path);
	pathy = *env;
	while (pathy)
	{
		s = _strncm(path, pathy->env, l);
		if (s == 0 && (pathy->env)[l] == '=')
		{
			copy = (pathy->env) + l + 1;
			lco = lenght(copy);
			new = malloc(sizeof(char) * (lco + 1));
			_strcopy(new, copy);
			return (new);
		}
		pathy = pathy->next;
	}
	return (NULL);
}

/**
 * pathy - function handle the path
 * @arg: string say if it's a ath or not
 * Return: importnt
 */

char *pathy(char *arg, env_l **env)
{
	char *bigpath = NULL, *or = NULL;
	char *path = NULL, *buff = NULL;
	char *res = NULL;

	if (!arg)
	{
		return (NULL);
	}
	if (arg[0] == '/')
	if (access(arg, F_OK) != -1)
	{
		return (arg);
	}
	buff = malloc(sizeof(char) * 1024);
	if (buff == NULL)
	{
		return (NULL);
	}
	bigpath = malloc(sizeof(char) * 1024);
	bigpath = moge("PATH", env);

	if (bigpath != NULL)
	{
		or = malloc(sizeof(char) * 1024);
		or = _strdup(bigpath);
		free(bigpath);
		if (or == NULL)
		{
			free(buff);
			return (NULL);
		}
		path = strtok(or, ":");
		while (path)
		{
			_strncpy(buff, path, 1024);
			_strcat(buff, "/");
			_strcat(buff, arg);

			if (access(buff, F_OK) != -1)
			{
				res = _strdup(buff);
				break;
			}
			path = strtok(NULL, ":");
		}
	}
	free(or);
	free(buff);
	return (res);
}
