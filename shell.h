#ifndef SHELL_H
#define SHELL_H

/* Libraries */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

/* Global Variables */
extern char **environ;

/* Functions */
char *_strdup(char *str);
char **_splitline(char *line, const char *delim);
int _execute(char **args);

#endif /* SHELL_H */
