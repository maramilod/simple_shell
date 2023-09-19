#include "main.h"

/**
 * main - entry function
 *
 * @argc: number of argument
 * @argv: string
 * Return: 0 on seccus
 */

int main(int argc, char **argv)
{
	env_l *list;
	char *lin = NULL;
	size_t l = 0;
	ssize_t r;
	int space = 0, er = 1, y, status = 0;

	y = atty();
	(void)argc;
	signal(SIGINT, sign);
	list = set_list();
	while (1)
	{
		if (y == 0)
			putss("<3 ");
		r = getline(&lin, &l, stdin);
		if (r == EOF)
		{
			if (y == 0)
				putss("\n");
			if (lin)
				free(lin);
			free_l(list);
			exit(status);
		}
		space = hand_space(lin, argv[0], &list, er, &status);
		if (space)
		{
			if (space != -1)
				er = space;
			else
			{
				er = ifnotexcv(lin, argv[0], er, &status);
				if (lin)
					free(lin);
				lin = NULL;
			}
		}
	}
	return (0);
}
