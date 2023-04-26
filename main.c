#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
        char *buffer;
        size_t bufsize = 0;
        pid_t pid;

        while (1)
        {
                printf("$ ");
                if (getline(&buffer, &bufsize, stdin) == -1)
                        break;
                pid = fork();
                if (pid == -1)
                {
                        perror("Error");
                        exit(EXIT_FAILURE);
                }
                else if (pid == 0)
                {
                        execve(buffer, NULL, environ);
                        perror("Error");
                        exit(EXIT_FAILURE);
                }
                else
                        wait(NULL);
        }

        free(buffer);
        exit(EXIT_SUCCESS);
}
