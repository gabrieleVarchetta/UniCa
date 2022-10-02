#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int status;

    pid = fork();
    
    if (pid)
    {
        sleep(20);
        pid = wait(&status);

        if (WIFEXITED(status))
            printf("Stato %d.\n", WEXITSTATUS(status));
    }
    else
    {
        printf("Processo figlio con PID %d.\n", getpid());
        _exit(69);
    }
    

    return 0;
}