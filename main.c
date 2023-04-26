#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char *command;
    size_t bufsize = 0;

    while (1) {
        printf("$ ");
        getline(&command, &bufsize, stdin);

        if (feof(stdin)) {
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
