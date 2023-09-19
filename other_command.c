#include "main.h"

/**
 * _exxit - function to exit the rog
 * @str: value we well check
 * @argv: arg
 * @env: environ -_-
 * @er: r
 * @status: s
 * Return: -1 if false
 */

int _exxit(char **str, char *argv, int er, env_l **env, int *status)
{
	int j = 0, mul = 1, u = 0, f = 0;

	if (str[1] == NULL)
	{
		free(str[0]);
		free(str);
		free_l(*env);
		if (*status)
			exit(2);
		exit(0);
	}
	for (j = 0; str[1][j]; j++)
		if (str[1][j] >= '0' && str[1][j] <= '9')
			u++;
	if (u == lenght(str[1]))
	{
		for (j = --u; j >= 0; j--)
			if (str[1][j] >= '0' && str[1][j] <= '9')
			{
				f += (str[1][j] - '0') * mul;
				mul *= 10;
			}
	}
	else
	{
		_printf("ccdccc", argv, ": ", er,
				": exit: Illegal number: ", str[1], "\n");
		free(str);
		er++;
		*status = 2;
		return (er);
	}
	free_l(*env);
	free(str[0]);
	free(str);
	exit(f);
	return (0);
}
/**
 * our - function
 * @argv: function dit
 * @lin: string
 * @argv: arg
 * @env: environ
 * Return: 0 or -1
 */
int our(char *lin, char **argv, env_l **env)
{
	ourc array[] = {{"env", print_l}, {"unsetenv", unset},
		{"cd", cd}, {"setenv", _setenv}, {NULL, NULL}};
	int i;

	for (i = 0; array[i].com != NULL; i++)
	{
		if (same(lin, array[i].com) == 0)
		{
			array[i].fn(argv, env);
			free(argv);
			return (0);
		}
	}
	free(argv);
	return (-1);
}
