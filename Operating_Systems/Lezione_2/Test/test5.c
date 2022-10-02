#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();
    fork();
    fork();
    
    printf("Ciao con PID %d", pid);
    printf("\n");
    
    return 0;
}