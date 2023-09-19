#include "main.h"

/**
 * is_d - fun
 * @s: s
 * @d: d
 * Return: num
 */
unsigned int is_d(char s, char *d)
{
	while (*d)
	{
		if (s == *d)
			return (1);
		d++;
	}
	return (0);
}
/**
 * mystrtok - fun
 * @str: s
 * @d: d
 * Return: char
 */
char *mystrtok(char *str, char *d)
{
	static char *input;
	char *end;

	if (!str)
		str = input;
	if (!str)
		return (NULL);

	while (1)
	{
		if (is_d(*str, d))
		{
			str++;
			continue;
		}
		if (*str == '\0')
			return (NULL);
		break;
	}

	end = str;
	while (1)
	{
		if (*str == '\0')
		{
			input = str;
			return (end);
		}
		if (is_d(*str, d))
		{
			*str = '\0';
			input = str + 1;
			return (end);
		}
		str++;
	}
}
/**
 * get_l - function
 * @head: list
 * @index: i
 * Return: the value
 */
char *get_l(env_l *head, int index)
{
	int i, j;
	env_l *h;
	char *value;

	for (i = 0; i < index && head; i++)
		head = head->next;
	if (!head || i != index)
		return (NULL);
	h = head;
	for (i = 0; (h->env)[i] != '='; i++)
		;
	i++;
	j = 0;
	value = malloc(sizeof(char) * (lenght(h->env) + i));
	while ((h->env)[i])
	{
		value[j] = (h->env)[i];
		i++;
		j++;
	}
	value[j] = '\0';
	return (value);
}
/**
 * cd - function
 * @argv: arg
 * @env: environ list
 * Return: 0
 */
int cd(char **argv, env_l **env)
{
	int i;
	char *cat = NULL, *ocat = NULL, pwdir[1024], opwd[1024];

	i = find(*env, "PWD");
	if (i != -1)
	{
		getcwd(opwd, 1024);
		ocat = malloc(lenght(opwd) + 8);
		_strcopy(ocat, "OLDPWD=");
		_strcat(ocat, opwd);
	}
	if (!argv[1] || same(argv[1], "$HOME") == 0)
	{
		i = find(*env, "HOME");
		if (i != -1)
			cd_h(i, env, 1, NULL);
	}
	else if (same(argv[1], "-") == 0)
	{
		i = find(*env, "OLDPWD");
		if (i != -1)
			cd_h(i, env, 2, NULL);
	}
	else
	{
		i = chdir(argv[1]);
		if (i != -1)
		{
			getcwd(pwdir, 1024);
			cat = malloc(lenght(pwdir) + 5);
			_strcopy(cat, "PWD=");
			_strcat(cat, pwdir);
			i = find(*env, "PWD");
			cd_h(i, env, 3, cat);
		}
	}
	i = find(*env, "OLDPWD");
	cd_h(i, env, 3, ocat);
	return (0);
}
