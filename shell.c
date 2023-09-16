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
	size_t l = 1024;
	ssize_t r;
	int space = 0, er = 1, y, le = 0;

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
		r = _getline(&lin, l, STDIN_FILENO);
		if (r == EOF)
		{
			if (y == 0)
				putss("\n");
	/*		free(lin);
			free_l(&list);*/
			return (0);
		}
		space = hand_space(lin, argv[0], &list, er);
		if (space)
		{
			if (space != -1)
			{
				er = space;
			}
			else
			{
				le = lenght(lin);
				li = malloc(sizeof(char) * le);
				li = ifnotexcv(lin);
				_printf("ccdccc", argv[0], ": ", er, ": ",
						li, ": not found\n");
				free(lin);
				free(li);
				er++;
			}
		}
	}
	free(lin);
	free_l(&list);
	return (0);
}
