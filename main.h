#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

typedef struct ourcommand
{
	char *com;
	int (*fn)();
} ourc;

void putss(char *string);
int lenght(char *k);
int same(const char *w, char *m);
int hand_space(char *k);
int excv(char *str);
char *ifnotexcv(char *st);
int our(char *lin);
int atty(void);

#endif
