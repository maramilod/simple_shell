#include "main.h"

/**
 * hand_space - function to call
 * @k: the line i well check
 * @argv: second
 * @env: env
 * @er: errors
 * @status: exit with
 * Return: always 0 or 1
 */

int hand_space(char *k, char *argv, env_l **env, int er, int *status)
{
	int o, u = 0, i = 0, x, numtoken;
	char **new = NULL;
	char *neww = NULL;

	numtoken = countTokens(k, " \n");
	new = malloc(sizeof(char *) * (numtoken + 1));

	if (!new)
		return (-1);
	new[i] = mystrtok(k, " \n");
	while (new[i])
	{
		if (new[i][0] == '#')
		{
			break;
		}
		i++;
		new[i] = mystrtok(NULL, " \n");
	}

	new[i] = NULL;

	if (same(new[0], "exit") == 0)
	{
		x = _exxit(new, argv, er, env, status);
		return (x);
	}
	neww = _strdup(new[0]);
	o = excv(neww, new, env, status);
	u = our(neww, new, env);
	if (o == -1 && u == -1)
	{
		free(neww);
		return (-1);
	}
	free(neww);
	return (0);
}
/**
 * countTokens - function to coubt
 * @str: first
 * @delim: second
 * Return: count
 */

int countTokens(char *str, char *delim)
{
	int c = 0;
	char *s, *t;

	s = _strdup(str);
	t = mystrtok(s, delim);
	while (t)
	{
		c++;
		t = mystrtok(NULL, delim);
	}
	free(s);
	return (c);
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
 * @argv: arg
 * @er: num
 * @status: s
 * Return: always
 */

int ifnotexcv(char *st, char *argv, int er, int *status)
{
	char *new[2];

	if (new == NULL)
	{
		return (-1);
	}
	new[0] = mystrtok(st, " ");
	new[1] = mystrtok(new[0], "\n");

	st = new[1];
	_printf("ccdccc", argv, ": ", er, ": ", st, ": not found\n");
	er++;
	*status = 127;
	return (er);
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
