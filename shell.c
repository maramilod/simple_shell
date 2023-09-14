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
	char *lin = NULL, *li = NULL;
	size_t l = 1024;
	ssize_t r;
	int space = 0, er = 0, y, le = 0;

	y = atty();
	(void)argc;
	signal(SIGINT, sign);
	while (1)
	{
		if (y == 0)
			putss("<3 ");
		r = _getline(&lin, l, STDIN_FILENO);
		if (r == EOF)
		{
			if (y == 0)
				putss("\n");
			return (0);
		}
		space = hand_space(lin, argv[0]);
		if (space == -1)
		{
			le = lenght(lin);
			li = malloc(sizeof(char) * le);
			li = ifnotexcv(lin);
			_printf("ccdccc", argv[0], ": ", er, ": ", li, ": not found\n");
			free(lin);
			free(li);
			er++;
		}
	}
	free(lin);
	return (0);
}
