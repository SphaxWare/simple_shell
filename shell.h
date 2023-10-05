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

void print_prompt(void);
void get_in(char **buffer, size_t *size, char *argv[]);
void tokenize_in(char *buffer, char *args[], char *argv[]);
void executer(char *args[], char *argv[]);
#endif
