#include "main.h"

/**
 * hand_space - function to call
 * @k: the line i well check
 * Return: always 0 or 1
 */

int hand_space(char *k, char *argv, env_l **env)
{
	int o, u = 0, i = 0;
	char **new;

	new = malloc(sizeof(char *) * 1024);

	if (!new)
		return (-1);
	new[i] = mystrtok(k, " \"\n");

	while (new[i])
	{
		i++;
		new[i] = mystrtok(NULL, " \n");
	}
	new[i] = NULL;
	o = excv(new[0], new, env);
	u = our(new[0], new, env);
	if (same(new[0], "exit") == 0)
	{
		_exxit(new, argv);
		free(new);
		return (0);
	}
	else if (o == -1 && u == -1)
	{
		free(new);
		return (-1);
	}
	free(new);
	return (0);
}

/**
 * atty - function to check isatty
 * Return: 0 || -1
 */

int atty(void)
{
	if (isatty(STDIN_FILENO))
	{
		return (0);
	}
	return (-1);
}

/**
 * ifnotexcv - function
 * @st: string to check
 * Return: always
 */

char *ifnotexcv(char *st)
{
	char *new;
	int ln;

	ln = lenght(st);
	new = malloc((sizeof(char *) * ln) + 1);
	if (new == NULL)
	{
		return (NULL);
	}
	_strcopy(new, st);
	new = strtok(new, " ");
	new = strtok(new, "\n");

	return (new);
}

/**
 * sign - function signal use
 * @si: the signall passed
 * Return: void
 */

void sign(int si)
{
	if (si == SIGINT)
		putss("\n<3 ");
}
