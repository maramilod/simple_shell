#include "main.h"
/**
 * set_list - function to set the real envi
 * Return: all environ
 */
env_l *set_list()
{
	int i;
	env_l *en = NULL;

	for (i = 0; environ[i] ; i++)
		add_l(&en, environ[i]);
	return (en);
}
/**
 * add_l - function add the node at the end
 * @list: header
 * @enron: the new node
 * Return: new header that include the node
 */
env_l *add_l(env_l **list, char *enron)
{
	env_l *temp;
	env_l *h;

	if (list == NULL)
		return (NULL);
	h = *list;
	temp = malloc(sizeof(env_l));
	if (temp == NULL || list == NULL)
		return (NULL);
	temp->next = NULL;
	if (enron)
	{
		temp->env = _strdup(enron);
		if (!temp->env)
		{
			free(temp);
			return (NULL);
		}
	}
	if (*list != NULL)
	{
		while (h->next != NULL)
			h = h->next;
		h->next = temp;
	}
	else
		*list = temp;
	return (temp);
}
/**
 * samenv - function check if the var exist
 * @en: environ
 * @arg: arg
 * Return: 0 if exist
 */
int samenv(char *en, char *arg)
{
	int i = 0;

	while (en[i] != '=')
	{
		if (en[i] != arg[i])
			return (-1);
		i++;
	}
	return (0);
}
/**
 * print_l - function print the all list
 *
 * @arg: not used
 * @list: to print
 * Return: 0
 */
int print_l(char **arg, env_l **list)
{
	env_l *plist;

	(void)**arg;
	if (list == NULL)
		return (-1);
	plist = *list;
	while (plist != NULL)
	{
		if (plist->env == NULL)
			puts("(nil)");
		else
			puts(plist->env);
		plist = plist->next;
	}
	return (0);
}
