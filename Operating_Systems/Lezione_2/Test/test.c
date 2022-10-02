#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    
    pid = fork();
   
    printf("Ciao, il processo che ha scritto questo ha PID %d", pid);
    printf("\n");
}