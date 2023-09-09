#include "main.h"
/**
 * putss - function print after the ^C
 *
 * @string: string that i need to print
 */
void putss(char *string)
{
	int i = 0;

	while (string[i])
	{
		write(1, &string[i], 1);
		i++;
	}
}
/**
 * sign - handling the si signal
 *
 * @si: ^C
 */
void sign(int si)
{
	if (si == SIGINT)
		putss("\n<3");
}
/**
 * same - function
 *
 * @w: first string
 * @m: second string
 * Return: 0 or -1
 */

int same(const char *w, char *m)
{
	int a = 0, b = 0, i = 0;

	if (w == NULL || m == NULL)
		return (-1);
	while (w[a] != '\n')
		a++;
	while (m[b])
		b++;
	if (a == b)
	{
		while (w[i] == m[i] && w[i] != '\0' && m[i] != '\0')
			i++;
	}
	else
		return (-1);
	if (i == a && i == b)
		return (0);
	return (-1);
}
/**
 * main - entry function
 *
 * @argc: number of argument
 * @argv: string
 * Return: 0 on seccus
 */

int main(int argc, char **argv)
{
	char *lin = NULL;
	size_t l = 0;
	ssize_t r;
	int space = 0;
	int er = 0;
	char *li;
	int y;

	y = atty();
	(void)argv;
	signal(SIGINT, sign);
	if (argc == 1)
	while (1)
	{
		if (y == 0)
		printf("<3 ");
		r = getline(&lin, &l, stdin);
		if (r == EOF && y == 0)
		{
			printf("\n");
			free(lin);
			return (-1);
		}
		else if (r == EOF && y == -1)
		{
			free(lin);
			return (-1);
		}
		space = hand_space(lin);
		if (space == -1)
			if (y == 0)
			{
				li = ifnotexcv(lin);
				printf("%s: %d: %s: not found\n", argv[0], er, li);
				er++;
			}
	}
	free(lin);
	return (0);
}
