#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

extern char **environ;

/**
 * struct list - struct for list
 *@s: char
 *@next: struct list
  */
typedef struct list
{
	char *s;
	struct list *next;
} list;

/**
 * struct builtin - struct for builtin
 *@command: char
 *@func: function pointer
 */

typedef struct builtin
{
	char *command;
	int (*func)(char *c, int args, list *path);
} builtin;


int _getn(char *name);
char *_getenv(char *name);
list *add_node(list **head, char *s);
int print_list(const list *h);
void free_list(list **head);
int _unsetenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
char *_strdup(char *str);
char *_strtok(char *str, char *delim);
char *strwhich(char *str, const char *delim);
int _strn(char *str);
char *_which(char *s, list *p);
int is_a(char *s);
list *getpath(void);
int built_in(char *s, list *env);
int _cd(char *s, int args, list *env);
int _ex(int exit_status, int args, char *s);
int _atoi(char *s);
int isnum(char *s);
int _e(char *s, int args, list *env);
int _set(char *s, int args, list *env);
int _unset(char *s, int args, list *env);
list *genv(void);
list *add_node_end(list **head, char *s);
void delete_node(list **head, unsigned int index);
int pathchecker(char *copy);
char *_strdup(char *str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
void sigHandler(int sig_num);
int _putchar(char c);
void _errors(char *argv[], char *first);

#endif
