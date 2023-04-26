#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int main()
{
    char command[MAX_COMMAND_LENGTH];
    int status = 1;

    while(status)
    {
        printf("Simple_Shell$ ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove the trailing newline character
        strtok(command, "\n");

        pid_t pid = fork();

        if (pid < 0)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            char *args[] = {command, NULL};
            if (execve(args[0], args, NULL) == -1)
            {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(&status);
        }
    }

    return EXIT_SUCCESS;
}
