#include "shell.h"

int main(void)
{
    char *buffer = NULL;
    size_t bufsize = 0;

    while (1)
    {
        printf("$ ");
        if (getline(&buffer, &bufsize, stdin) == -1)
            break;

        if (fork() == 0)
        {
            /* child process */
            char **args = malloc(3 * sizeof(char *));
            args[0] = "/bin/sh";
            args[1] = "-c";
            args[2] = buffer;
            args[3] = NULL;
            execve(args[0], args, NULL);
            perror("execve failed");
            exit(EXIT_FAILURE);
        }
        else
        {
            /* parent process */
            wait(NULL);
        }
    }

    free(buffer);
    return EXIT_SUCCESS;
}
