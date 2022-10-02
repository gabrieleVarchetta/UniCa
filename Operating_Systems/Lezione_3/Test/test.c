#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t pid;

    pid = fork();

    if (pid)
        fork();
    
    printf("Sono il processo %d, figlio di %d\n", getpid(), getppid());

    
    return 0;
}
