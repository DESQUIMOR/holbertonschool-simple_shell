#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;
    int status;

    printf("$ ");
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        /* Este es el proceso hijo */
        char *argv[] = {"/bin/ls", NULL};
        if (execve(argv[0], argv, NULL) == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* Este es el proceso padre */
        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
        {
            printf("Program exited with status %d\n", WEXITSTATUS(status));
        }
    }
    return EXIT_SUCCESS;
}
