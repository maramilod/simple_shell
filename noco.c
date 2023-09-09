#include "main.h"
/**
 * ifnotexcv - function handle space
 *
 * @st: string
 * Return: 0 or -1
 */
char *ifnotexcv(char *st)
{
	char *new;
	int ln;

	ln = lenght(st);
	new = malloc((sizeof(char *) * ln) + 1);
	new = strtok(st, " ");
	new = strtok(new, "\n");
	return (new);
}
