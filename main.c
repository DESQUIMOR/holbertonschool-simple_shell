#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(void)
{
    char buffer[BUFFER_SIZE];
    pid_t pid;
    int status;

    while (1)
    {
        printf("$ ");
        fflush(stdout);

        if (!fgets(buffer, BUFFER_SIZE, stdin))
            break;

        pid = fork();

        if (pid < 0)
        {
            perror("Fork error");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            char *args[] = { "/bin/sh", "-c", buffer, NULL };
            execve(args[0], args, NULL);
            exit(EXIT_FAILURE);
        }
        else
        {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}
