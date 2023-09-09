#include "main.h"

int lenght(char *k);
/**
 * hand_space - function handling speaces
 * @k: the line i well sea
 * Return: always int
 */

int hand_space(char *k)
{
	int i = 0, o, j = 0, n = 0, last = 0, t = 0, u;
	char *new;
	char *ou;

	o = lenght(k);
	ou = malloc(sizeof(char *) * o);
	new = malloc(sizeof(char *) * o);
	while (k[i] != '\0')
	{
		if (k[i] ==   ' ')
		{
			j++;
		}
		if (k[i] != ' ')
			break;
		i++;
	}
	if (o == j)
	{
		free(ou);
		free(new);
		return (0);
	}
	i = 0;
	while (k[j])
	{
		if (k[j] != ' ')
		{
			ou[i] = k[j];
			new[i] = k[j];
			if (last == 1)
				t--;
		}
		else
		{
			n--;
			t--;
			last = 1;
		}
		i++;
		j++;
		n++;
		t++;
	}
	n--;
	ou[t] = '\n';
	u = our(ou);
	new[n] = '\n';
	o = check(new);
	o = excv(new);
	if (o == -1 && u == 1)
	{
		free(new);
		return (-1);
	}
	free(new);
	return (0);
}

/**
 * lenght - function to se the strlen
 * @k: string
 * Return: always int
 */

int lenght(char *k)
{
	int i = 0;
	int ad = 0;

	while (k[i] != '\0')
	{
		i++;
		ad++;
	}
	i--;
	return (i);
}
