#include "main.h"

/**
 * envo - function
 *
 * Return: 0 or -1
 */
int envo(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
		printf("%s\n", environ[i]);
	return (0);
}

/**
 * our - function
 *
 * @lin: string
 * Return: 0 or -1
 */
int our(char *lin)
{
	ourc array[] = { {"env", envo}, {NULL, NULL}};
	int i;

	for (i = 0; array[i].com != NULL; i++)
		if (same(lin, array[i].com) == 0)
		{
			array[i].fn();
			return (0);
		}

	return (-1);
}
