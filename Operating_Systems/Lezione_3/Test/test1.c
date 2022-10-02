#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    pid_t pid = fork();

    switch(pid)
    {
        case -1:
            printf("fork error.\n");
            break;

        case 0:
            execl("/bin/ls", "ls", "-l", NULL);
            printf("execl error.\n"); //di solito non viene mai stampato
            break;

        default:
            wait(NULL);
            fflush(stdin);
            printf("ls command completed.\n");
            _exit(0);
    }

    return 0;
}

