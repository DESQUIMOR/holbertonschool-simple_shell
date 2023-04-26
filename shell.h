#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

/* Function prototypes */
char **split_line(char *line, const char *delim);
void free_args(char **args);
int execute(char **args);

#endif /* SHELL_H */
