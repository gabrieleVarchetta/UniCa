#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    int n;

    if (pid == 0)
        n = 1;
    else
        n = 6;

    if (pid != 0)
    {
        wait(NULL);
    }
    
    int i;

    printf("Numeri stampati dal processo con PID %d: ", pid);
    for (i = n; i < n + 5; i++)
    {
        printf("%d ", i);
        fflush(stdout);
    }

    printf("\n");

    return 0;
}