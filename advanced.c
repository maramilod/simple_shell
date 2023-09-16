#include "main.h"

/**
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
		if(is_d(*str,d))
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
	value = malloc(sizeof(lenght((h->env)) - i));
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
	char *pwd, *cat = NULL, *ocat = NULL;
	char pwdir[1024];
	char opwd[1024];

	i = find(*env, "PWD");
	if (i != -1)
	{
		getcwd(opwd, 1024);
		ocat = malloc(lenght(opwd) + 7);
		ocat = _strdup("OLDPWD=");
		_strcat(ocat, opwd);
	}
	if (!argv[1] || same(argv[1], "$HOME") == 0)
	{
		i = find(*env, "HOME");
		if (i != -1)
		{
			pwd = get_l(*env, i);
			chdir(pwd);
			cat = malloc(lenght(pwd) + 4);
			cat = _strdup("PWD=");
			_strcat(cat, pwd);
			i = find(*env, "PWD");
			if (i != -1)
			{
				delete_l(env, i);
				edit_l(env, cat, i);
			}
			else
				add_l(env, cat);
			free(cat);
			free(pwd);
		}
	}
	else if (same(argv[1], "-") == 0)
	{
		i = find(*env, "OLDPWD");
		if (i != -1)
		{
			pwd = get_l(*env, i);
			chdir(pwd);
			puts(pwd);
			cat = malloc(lenght(pwd) + 4);
			cat = _strdup("PWD=");
			_strcat(cat, pwd);
			i = find(*env, "PWD");
			if (i != -1)
			{
				delete_l(env, i);
				edit_l(env, cat, i);
			}
			else
				add_l(env, cat);
			free(cat);
			free(pwd);
		}
	}
	else
	{
		i = chdir(argv[1]);
		if (i == -1)
			puts("can't cd\n");
		else
		{
			getcwd(pwdir, 1024);
			cat = malloc(lenght(pwdir) + 4);
			cat = _strdup("PWD=");
			_strcat(cat, pwdir);
			i = find(*env, "PWD");
			if (i != -1)
			{
				delete_l(env, i);
				edit_l(env, cat, i);
			}
			else
				add_l(env, cat);
			free(cat);
		}
	}
	i = find(*env, "OLDPWD");
	if (i != -1)
	{
		delete_l(env, i);
		edit_l(env, ocat, i);
	}
	else
		add_l(env, ocat);
	free(ocat);
	chdir(argv[1]);
	return (0);
}
