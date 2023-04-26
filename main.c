#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    pid_t pid;

    printf("Antes del fork\n");

    pid = fork();

    if (pid == -1)
    {
        perror("Error al crear el proceso hijo\n");
        return (1);
    }
    else if (pid == 0)
    {
        char *argv[] = {"/bin/ls", NULL};

        printf("Proceso hijo: PID=%d\n", getpid());

        execve(argv[0], argv, NULL);

        perror("Error en execve\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Proceso padre: PID=%d\n", getpid());
    }

    return (0);
}
