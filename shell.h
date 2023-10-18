#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
extern char **environ;
#include "main.h"

void print_prompt(void);
void get_in(char **buffer, size_t *size, char *argv[], char *args[]);
void tokenize_in(char *buffer, char *args[], char *argv[]);
void executer(char *args[], char *argv[]);
char *_getenv(const char *name);
char *check_path(char *cmd);
void pathfinder(char *args[], char *argv[]);
void printenv(void);
int _atoi(char *s);
int myexit(int status);
void cmdexe(char *args[], char *argv[], int i, int count);
int _setenv(const char *name, const char *value);

/*strings*/

int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
int _strlen(char *s);
char *_strdup(char *str);

/*free args*/
void freeargs(char *args[]);
#endif
