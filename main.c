#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
    char *args[] = {"/bin/ls", "-l", "/usr/", NULL};
    char buffer[100];

    pid_t pid = fork();

    if (pid == 0)
    {
        if (execve(args[0], args, NULL) == -1)
        {
            perror("Error executing command");
            exit(EXIT_FAILURE);
        }
    }
    else if (pid > 0)
    {
        wait(NULL);
        printf("Child exited\n");
    }
    else
    {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}
