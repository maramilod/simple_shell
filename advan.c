#include "main.h"

/**
 * cd_h - f
 * @i: i
 * @env: e
 * @j: j
 * @cat: c
 */
void cd_h(int i, env_l **env, int j, char *cat)
{
	char *pwd = NULL;

	if (j != 3)
	{
		pwd = get_l(*env, i);
		chdir(pwd);
		if (j == 2)
			puts(pwd);
		cat = malloc(lenght(pwd) + 5);
		_strcopy(cat, "PWD=");
		_strcat(cat, pwd);
		i = find(*env, "PWD");
	}
	if (i != -1)
	{
		delete_l(env, i);
		edit_l(env, cat, i);
	}
	else
		add_l(env, cat);
	free(cat);
	if (j == 3)
		return;
	free(pwd);
}
/**
 * same - function
 * @w: first
 * @m: second
 * Return: true or false
 */

int same(char *w, char *m)
{
	size_t lw = 0, lm = 0;

	if (w == NULL || m == NULL)
	{
		return (-1);
	}
	lw = lenght(w);
	lm = lenght(m);

	if (lw != lm)
	{
		return (-1);
	}
	if (_strncm(w, m, lw) == 0)
	{
		return (0);
	}

	return (-1);
}
