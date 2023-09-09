#include "main.h"

/**
 * excv - function to excute
 * @str: value
 * Return: always 0 | -1
 */

int excv(char *str)
{
	int i;
	pid_t pid;
	char *test[] = {"/bin/ls", "ls", NULL};
	char *const arg[] = {NULL};


	if (!str)
		write(STDOUT_FILENO, "file not open", 13);
	if (same(str, "ls") == 0)
	{
		if (getenv("PATH") == NULL || strcmp(getenv("PATH"), "") == 0)
		{
			write(STDOUT_FILENO, "ls: command not found\n", 22);
			return (0);
		}
	}
	for (i = 0; test[i] != NULL; i++)
	{
		if (same(str, test[i])  == 0)
		{
			pid = fork();
			if (pid == 0)
			{
				execve("/bin/ls", arg, NULL);
			}
			else if (pid > 0)
			{
				wait(NULL);
				return (0);
			}
		}
	}
	return (-1);
}

/**
 * atty - function
 * Return: always
 */

int atty(void)
{
	if (isatty(STDIN_FILENO))
		return (0);
	return (-1);
}
