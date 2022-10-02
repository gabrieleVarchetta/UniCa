#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t process;
    process = 777;

    printf("prefork: %d\t", process);

    process = fork();

    printf("postfork: %d\t", process);

    process = 777;

    printf("\n");

    if (process < 0)
    {
        fprintf(stderr, "process generating failed\n");
        return 1;
    }
    else
    {
        wait(NULL);
        printf("subprocess finished\n");
    }
    
    

    return 0;
}