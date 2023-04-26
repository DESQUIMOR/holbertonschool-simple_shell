#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    char *command = NULL;
    size_t bufsize = 0;
    ssize_t characters_read;

    while (1) {
        printf("$ ");
        characters_read = getline(&command, &bufsize, stdin);

        if (characters_read == -1) {
            break;
        }

        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            if (execve(command, &command, NULL) == -1) {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        } else {
            waitpid(pid, NULL, 0);
        }

        free(command);
        command = NULL;
    }

    return 0;
}
