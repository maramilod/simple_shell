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
	char *lin = NULL, *li = NULL;
	size_t l = 0;
	ssize_t r;
	int space = 0, er = 1, y, status = 0;

	y = atty();
	(void)argc;
	signal(SIGINT, sign);
	list = set_list();
	if (argc == 2)
	{
		excute(argv[1], argv, list);
		return (0);
	}
	while (1)
	{
		if (y == 0)
			putss("<3 ");
		r = getline(&lin, &l, stdin);/* STDIN_FILENO);*/
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
				li = ifnotexcv(lin);
				_printf("ccdccc", argv[0], ": ", er, ": ",
						li, ": not found\n");
				er++;
				status = 127;
				free(lin);
			}
		}
	}
	free(lin);
	free_l(list);
	return (0);
}
