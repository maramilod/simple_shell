#include "main.h"

/**
 * _exxit - function to exit the rog
 * @str: value we well check
 * Return: -1 if false
 */

int _exxit(char **str, char *argv)
{
	int i = 0, j, mul = 1, u = 0;
	static int f = 1;

	if (str[1] == NULL)
	{
		free(str);
		if (f != 1)
		{
			exit(2);
		}
		exit(0);
	}
	if (str[1][i])
	{
		for (j = 0; str[1][j]; j++)
		{
			if (str[1][j] >= '0' && str[1][j] <= '9')
				u++;
		}
		if (u == lenght(str[1]))
		{
			f = 1;
			u--;
			for (j = u; j >= 0; j--)
			{
				if (str[1][j] >= '0' && str[1][j] <= '9')
				{
					f += (str[1][j] - '0') * mul;
					mul *= 10;
				}
			}
		}
		else
		{
			_printf("ccdccc", argv,": ", f,": exit: Illegal number: ", str[1], "\n");
			f++;
			return (0);
		}
	}
	exit(f - 1);
	return (0);
}
/**
 * our - function
 * @argv: function dit
 * @lin: string
 * Return: 0 or -1
 */
int our(char *lin, char **argv, env_l **env)
{
	ourc array[] = {{"env", print_l}, {"unsetenv", unset}, {"setenv", _setenv}, {NULL, NULL}};
	int i;

	for (i = 0; array[i].com != NULL; i++)
	{
		if (same(lin, array[i].com) == 0)
		{
			array[i].fn(argv, env);
			return (0);
		}
	}
	return (-1);
}
