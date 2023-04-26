#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;

    pid = fork();
    if (pid == -1)
    {
        perror("Error:");
        exit(EXIT_FAILURE);
    }
    if (pid == 0)
    {
        execve("/bin/ls", NULL, NULL);
        perror("Error:");
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(NULL);
        printf("Child exited\n");
    }
    return (EXIT_SUCCESS);
}
