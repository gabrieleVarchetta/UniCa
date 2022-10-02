#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MSG_SIZE 64
#define READ_END 0
#define WRITE_END 1

int main(int argc, char const *argv[])
{
    //buffer in cui salvare i messaggi letti dalla pipe
    char inbuf[MSG_SIZE]; 

    //messaggi da scrivere sulla pipe
    char msg1[MSG_SIZE] = "ettando, saia cane di merda 1";
    char msg2[MSG_SIZE] = "ettando, saia cane di merda 2";
    char msg3[MSG_SIZE] = "ettando, saia cane di merda 3";

    //file descriptor per la pipe
    int fd[2];

    pid_t pid;

    //creazione della pipe
    if(pipe(fd) == -1)
    {
        perror("pipe call");
        _exit(1);
    }

    pid = fork();

    switch (pid)
    {
    case -1:
        perror("fork call");
        _exit(2);

        break;
    
    case 0:
        close(fd[READ_END]);

        write(fd[1], msg1, MSG_SIZE);
        write(fd[1], msg2, MSG_SIZE);
        write(fd[1], msg3, MSG_SIZE);

        close(fd[WRITE_END]);
        break;

    default:
        close(fd[WRITE_END]);

        for (int i = 0; i < 3; i++)
        {
            read(fd[READ_END], inbuf, MSG_SIZE);
            printf("%s\n", inbuf);
        }

        close(fd[READ_END]);
        wait(NULL);
        _exit(0);
    }
    
    return 0;
}
