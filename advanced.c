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

