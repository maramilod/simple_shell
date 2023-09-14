#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>

extern char **environ;

/**
 * struct ourcommand - structure
 * @com: the name of co
 * @fn: the function
 */

typedef struct ourcommand
{
	char *com;
	int (*fn)();
} ourc;

void puti(int num);
int _printf(char *arg, ...);
void putss(char *string);
int lenght(char *k);
int same(char *w, char *m);
int hand_space(char *k, char *argv);
int excv(char *str, char **argv);
char *ifnotexcv(char *st);
int our(char *lin, char **argv);
int atty(void);
char *pathy(char *arg);
char *moge(char *path);
int _strncm(char *s1, char *s2, int t);
char *_strcat(char *buffer, char *add);
void sign(int si);
int _exxit(char **str, char *argv);
char *_strcopy(char *buffer, char *newcopy);
char *_strncpy(char *str2, char *str, int n);
char *_strdup(char *str);
ssize_t _getline(char **lin, size_t l, int fn);


#endif
