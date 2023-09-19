#include "main.h"
/**
 * find - function that searcing for word
 * in linked list
 * @head: the list
 * @word: the word -__-
 * Return: -1 if its not exist
 */
int find(env_l *head, char *word)
{
	env_l *current = head;
	int index = 0;

	while (current != NULL)
	{
		if (samenv(current->env, word) == 0)
			return (index);
		index++;
		current = current->next;
	}
	return (-1);
}
/**
 * delete_l - function
 * @head: list
 * @index: i
 * Return: 0
 */
int delete_l(env_l **head, int index)
{
	int i;
	env_l *a, *b;

	if (!head || !*head)
		return (-1);
	if (index == 0)
	{
		a = *head;
		*head = (*head)->next;
		free(a);
		return (1);
	}
	a = *head;
	for (i = 0; i < index && a; i++)
	{
		b = a;
		a = a->next;
	}
	if (i == index)
	{
		b->next = a->next;
		free(a->env);
		free(a);
		return (1);
	}
	return (-1);
}
/**
 * unset - function
 * @arg: unused
 * @list: list
 * Return: 0
 */
int unset(char **arg, env_l **list)
{
	int i, j;

	j = 1;
	if (arg[1] == NULL)
	{
		write(STDERR_FILENO, "Too few argu -_-\n", 17);
		return (0);
	}
	while (arg[j] != NULL)
	{
		i = find(*list, arg[j]);
		if (i != -1)
			delete_l(list, i);
		j++;
	}
	return (0);
}
/**
 * edit_l - function
 *
 * @list: header
 * @buffer: new node to add in idx place
 * @idx: place
 * Return: new list
 */
env_l *edit_l(env_l **list, char *buffer, int idx)
{
	int i;
	env_l *fh;
	env_l *t;

	t = *list;
	fh = malloc(sizeof(env_l));
	if (fh == NULL || list == NULL)
		return (NULL);
	if (list && fh)
	{
		fh->env = _strdup(buffer);
		fh->next = NULL;
		if (idx == 0)
		{
			fh->next = *list;
			*list = fh;
			return (fh);
		}
		for (i = 0; i < (idx - 1) && t; i++)
			t = t->next;
		if (i == (idx - 1))
		{
			fh->next = t->next;
			t->next = fh;
			return (fh);
		}
	}
	free(fh);
	return (NULL);
}
/**
 * _setenv - function to set a new var or
 * edit an old one
 * @arg: new var
 * @list: list of var
 * Return: 0
 */
int _setenv(char **arg, env_l **list)
{
	int i = 0, j = 0;
	char *buf = NULL;

	while (arg[j])
		j++;
	if (j != 3)
	{
		write(STDERR_FILENO, "Incorrect num of argu\n", 22);
		return (0);
	}
	buf = malloc(lenght(arg[1]) + lenght(arg[2]) + 2);
	if (!buf)
		return (0);
	_strcopy(buf, arg[1]);
	_strcat(buf, "=");
	_strcat(buf, arg[2]);
	i = find(*list, arg[1]);
	if (i != -1)
	{
		delete_l(list, i);
		edit_l(list, buf, i);
		free(buf);
		return (0);
	}
	add_l(list, buf);
	free(buf);
	return (0);
}
