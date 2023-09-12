#include "main.h"

/**
 * hand_space - function to call
 * @k: the line i well check
 * Return: always 0 or 1
 */

int hand_space(char *k, char *argv)
{
	int o, u = 0, i = 0;
	char **new;

	new = malloc(sizeof(char *));
	new[i] = strtok(k, " \"\n");

	while (new[i])
	{
		i++;
		new[i] = strtok(NULL, " \n");
	}
	new[i] = NULL;
	o = excv(new[0], new);
	u = our(new[0], new);
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
	new = malloc((sizeof(char *) * ln));
	new = strtok(st, " ");
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
