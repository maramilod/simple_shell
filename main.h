#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>
#include <signal.h>

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
/**
 * struct env_list - fun
 * @env:e
 * @next: point to next node
 */
typedef struct env_list
{
	char *env;
	struct env_list *next;
} env_l;

int samenv(char *en, char *arg);
int print_l(char **arg, env_l **list);
env_l *add_l(env_l **list, char *enron);
env_l *set_list();
int find(env_l *head, char *word);
int delete_l(env_l **head, int index);
int unset(char **arg, env_l **list);
env_l *edit_l(env_l **list, char *buffer, int idx);
int _setenv(char **arg, env_l **list);
void free_l(env_l *h);

unsigned int is_d(char s, char *d);
char *mystrtok(char *str, char *d);
void puti(int num);
int _printf(char *arg, ...);
void putss(char *string);
int lenght(char *k);
int same(char *w, char *m);
int hand_space(char *k, char *argv, env_l **env, int er, int *status);
int excv(char *str, char **argv, env_l **env, int *status);
int ifnotexcv(char *st, char *argv, int er, int *status);
int our(char *lin, char **argv, env_l **env);
int atty(void);
char *pathy(char *arg, env_l **env);
char *moge(char *path, env_l **env);
int _strncm(char *s1, char *s2, int t);
char *_strcat(char *buffer, char *add);
void sign(int si);
int _exxit(char **str, char *argv, int er, env_l **env, int *status);
char *_strcopy(char *buffer, char *newcopy);
char *_strncpy(char *str2, char *str, int n);
char *_strdup(char *str);

char *get_l(env_l *head, int index);
void cd_h(int i, env_l **env, int j, char *cat);
int cd(char **argv, env_l **env);
void excute(char *file, char **argv, env_l *list);
int countTokens(char *str, char *delim);
#endif
