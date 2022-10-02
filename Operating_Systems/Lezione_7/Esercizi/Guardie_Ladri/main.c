#include <curses.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <stdbool.h>

#define PASSO 1
#define UP_KEY 65
#define DOWN_KEY 66
#define RIGHT_KEY 67
#define LEFT_KEY 68
#define MAX_X 80
#define MAX_Y 24
#define READ_END 0
#define WRITE_END 1


typedef struct
{
    char c; //oggetto che invia i dati: guardia o ladro
    int x; 
    int y;
}posizione;

void ladro(int pipeOut);
void guardia(int pipeOut);
void controllo(int pipeIn);

int main(int argc, char const *argv[])
{
    int fd[2];
    pid_t pid_ladro, pid_guardia;

    srand(time(NULL));
    initscr();
    noecho();
    curs_set(0);

    if(pipe(fd) == -1)
    {
        perror("Errore nella creazione della pipe.");
        _exit(1);
    }

    pid_ladro = fork();

    switch (pid_ladro)
    {
    case -1:
        perror("Errore nell'esecuzione della fork.");
        _exit(1);

        break;
    
    case 0:
        close(fd[READ_END]);
        ladro(fd[WRITE_END]);
        close(fd[WRITE_END]);

        break;
    
    default:
        pid_guardia = fork();

        switch (pid_guardia)
        {
        case -1:
            perror("Errore nell'esecuzione della fork.");
            _exit(1);
            
            break;
        
        case 0:
            close(fd[READ_END]);
            guardia(fd[WRITE_END]);
            close(fd[WRITE_END]);

            break;

        default:
            close(fd[WRITE_END]);
            controllo(fd[READ_END]);
            close(fd[READ_END]);
            break;
        }
        break;
    }

    kill(pid_ladro, 1);
    kill(pid_guardia, 1);

    endwin();
    return 0;
}

void ladro (int pipeOut)
{
    posizione pos_ladro;
    long int r;
    int dx, dy;

    pos_ladro.x = 1;
    pos_ladro.y = 1;
    pos_ladro.c = '$';

    write(pipeOut, &pos_ladro, sizeof(pos_ladro));

    while (true)
    {
        //generazione coordinate asse x
        r = random();

        if (r < RAND_MAX / 2)
            dx = PASSO;
        else
            dx = -PASSO;

        if (pos_ladro.x + dx < 1 || pos_ladro.x + dx >= MAX_X)
            dx *= -1;

        pos_ladro.x += dx;

        //generazione coordinate asse y
        r = random();

        if (r < RAND_MAX / 2)
            dy = PASSO;
        else
            dy = -PASSO;

        if (pos_ladro.y + dy < 1 || pos_ladro.y + dy >= MAX_Y)
            dy *= -1;

        pos_ladro.y += dy;

        write(pipeOut, &pos_ladro, sizeof(pos_ladro));

        usleep(100000);
    }
}

void guardia(int pipeOut)
{
    posizione pos_guardia;
    pos_guardia.x = MAX_X - 1;
    pos_guardia.y = MAX_Y - 1;
    pos_guardia.c = '#';

    write(pipeOut, &pos_guardia, sizeof(pos_guardia));

    while (true)
    {
        char keyPressed;

        switch (keyPressed = getch())
        {
        case UP_KEY:
            if (pos_guardia.y > 0)
                pos_guardia.y -= 1;

            break;
        
        case DOWN_KEY:
            if (pos_guardia.y < MAX_Y - 1)
                pos_guardia.y += 1;

            break;

        case LEFT_KEY:
            if (pos_guardia.x > 0)
                pos_guardia.x -= 1;
            
            break;
        
        case RIGHT_KEY:
            if (pos_guardia.x < MAX_X - 1)
                pos_guardia.x += 1;
            
            break;
        }

        write(pipeOut, &pos_guardia, sizeof(pos_guardia));
    }  
}

void controllo(int pipeIn)
{
    posizione ladro, guardia, valoreLetto;
    bool flag = true;
    ladro.x = -1;
    guardia.x = -1;

    do
    {
        read(pipeIn, &valoreLetto, sizeof(valoreLetto));

        if (valoreLetto.c == '$')
        {
            if (ladro.x >= 0)
                mvaddch(ladro.y, ladro.x, ' ');
            
            ladro = valoreLetto;          
        }
        else
        {
            if (guardia.x >= 0)
                mvaddch(guardia.y, guardia.x, ' ');
           
            guardia = valoreLetto;    
        }

        mvaddch(valoreLetto.y, valoreLetto.x, valoreLetto.c);

        curs_set(0);
        refresh();    

        if(guardia.x == ladro.x && guardia.y == ladro.y)
        {
            flag = false;
            flash();
            beep();
        }
    } while (flag);
}