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
	char *lin = NULL, *li;
	size_t l = 0;
	ssize_t r;
	int space = 0, er = 0, y;

	y = atty();
	(void)argc;
	signal(SIGINT, sign);
	while (1)
	{
		if (y == 0)
			putss("<3 ");
		r = getline(&lin, &l, stdin);
		if (r == EOF)
		{
			if (y == 0)
				putss("\n");
			free(lin);
			return (0);
		}
		space = hand_space(lin, argv[0]);
		if (space == -1)
		{
			li = ifnotexcv(lin);
			printf("%s: %d: %s: not found\n", argv[0],  er, li);
			er++;
		}
	}
	free(lin);
	return (0);
}
