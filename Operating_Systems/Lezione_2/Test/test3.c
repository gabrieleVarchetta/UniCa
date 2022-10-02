#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();    
    
    //printf("Sono il processo con PID %d\n", pid);

    if (pid)
    {
        wait(NULL);
        printf("Parent process with PID %d", pid);
    }
    else
        printf("Child process with PID %d", pid);

    printf("\n");
    
    /** per avere solo tre processi anziché 4, controlliamo che l'id del processo sia diverso da 0,
     * così duplichiamo solo il processo padre che avrà id != 0, mentre il primo processo figlio
     * non verrà duplicato
     * pid_t pid = fork();
    
       if (pid != 0)
        {
            fork();
        }
    */
    
    return 0;
}