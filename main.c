#include "shell.h"

int main(void)
{
    char *line = NULL;
    char **args = NULL;
    size_t len = 0;
    ssize_t nread;
    pid_t pid;
    int status;

    while (1)
    {
        printf("$ ");

        nread = getline(&line, &len, stdin);

        if (nread == -1)
        {
            putchar('\n');
            break;
        }

        line[nread - 1] = '\0';
        args = split_line(line, " ");

        if (args == NULL || args[0] == NULL)
        {
            free_args(args);
            continue;
        }

        pid = fork();

        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0)
        {
            if (execute(args) == -1)
            {
                free_args(args);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(&status);
        }

        free_args(args);
    }

    free(line);

    return 0;
}

char **split_line(char *line, const char *delim)
{
    char *token = NULL;
    char **tokens = NULL;
    size_t i, ntokens = 0;

    token = strtok(line, delim);

    while (token != NULL)
    {
        tokens = realloc(tokens, sizeof(char *) * (ntokens + 1));

        if (tokens == NULL)
        {
            perror("realloc");
            exit(EXIT_FAILURE);
        }

        tokens[ntokens] = token;
        ntokens++;

        token = strtok(NULL, delim);
    }

    tokens = realloc(tokens, sizeof(char *) * (ntokens + 1));

    if (tokens == NULL)
    {
        perror("realloc");
        exit(EXIT_FAILURE);
    }

    tokens[ntokens] = NULL;

    return tokens;
}

void free_args(char **args)
{
    size_t i;

    if (args == NULL)
        return;

    for (i = 0; args[i] != NULL; i++)
        free(args[i]);

    free(args);
}

int execute(char **args)
{
    char *buffer = NULL;

    buffer = malloc(sizeof(char) * 1024);

    if (buffer == NULL)
    {
        perror("malloc");
        return -1;
    }

    sprintf(buffer, "%s %s", args[0], args[1]);

    if (execve("/bin/sh", (char *[]){"/bin/sh", "-c", buffer, NULL}, NULL) == -1)
    {
        perror("execve");
        free(buffer);
        return -1;
    }

    return 0;
}
