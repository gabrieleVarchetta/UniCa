#include <curses.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define PASSO 1
#define UP_KEY 65
#define DOWN_KEY 66
#define RIGHT_KEY 67
#define LEFT_KEY 68
#define MAX_X 80
#define MAX_Y 20
#define READ_END 0
#define WRITE_END 1
#define DELAY 80000


typedef struct
{
    char c; //oggetto che invia i dati: guardia o ladro
    int x; 
    int y;
}posizione;

void vespa(int pipeOut);
void contadino(int pipeOut);
void areaGioco(int pipeIn);

int main(int argc, char const *argv[])
{
    int fd[2];
    pid_t vespa_pid, contadino_pid;

    srand(time(NULL));
    initscr();
    noecho();
    curs_set(0);

    if (pipe(fd) == -1)
    {
        perror("Errore nella creazione della pipe.");
        _exit(1);
    }
    
    vespa_pid = fork();

    switch (vespa_pid)
    {
    case -1:
        perror("Errore nell'esecuzione della fork.");
        _exit(1);
    
    case 0:
        close(fd[READ_END]);
        vespa(fd[WRITE_END]);

    default:
        contadino_pid = fork();

        switch (contadino_pid)
        {
        case -1:
            perror("Errore nell'esecuzione della fork.");
            _exit(1);
        
        case 0:
            mvprintw(MAX_Y / 2, MAX_X / 2, "#");
            close(fd[READ_END]);
            contadino(fd[WRITE_END]);

        default:
            close(fd[WRITE_END]);
            areaGioco(fd[READ_END]);
            close(fd[READ_END]);

            break;
        }
        break;
    }

    kill(vespa_pid, 1);
    kill(contadino_pid, 1);

    endwin();

    printf("\n\n\n");

    printf("  /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$        /$$$$$$  /$$    /$$ /$$$$$$$$ /$$$$$$$       \n"
           " /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/       /$$__  $$| $$   | $$| $$_____/| $$__  $$      \n"
           "| $$  \\__/| $$  \\ $$| $$$$  /$$$$| $$            | $$  \\ $$| $$   | $$| $$      | $$  \\ $$      \n"
           "| $$ /$$$$| $$$$$$$$| $$ $$/$$ $$| $$$$$         | $$  | $$|  $$ / $$/| $$$$$   | $$$$$$$/      \n"
           "| $$|_  $$| $$__  $$| $$  $$$| $$| $$__/         | $$  | $$ \\  $$ $$/ | $$__/   | $$__  $$      \n"
           "| $$  \\ $$| $$  | $$| $$\\  $ | $$| $$            | $$  | $$  \\  $$$/  | $$      | $$  \\ $$      \n"
           "|  $$$$$$/| $$  | $$| $$ \\/  | $$| $$$$$$$$      |  $$$$$$/   \\  $/   | $$$$$$$$| $$  | $$      \n"
           " \\______/ |__/  |__/|__/     |__/|________/       \\______/     \\_/    |________/|__/  |__/      \n"
           "                                                                                                \n"
           "                                                                                                \n"
           "                                                                                                ");

    printf("\n\n\n");

    return 0;
}

void vespa(int pipeOut)
{
    posizione pos_vespa;
    int dx, dy;

    pos_vespa.x = 1;
    pos_vespa.y = 1;
    pos_vespa.c = 'v';

    write(pipeOut, &pos_vespa, sizeof(pos_vespa));

    while (true)
    {
        //generazione coordinate asse x

        if (random() < RAND_MAX / 2)
            dx = PASSO;
        else
            dx = -PASSO;

        if (pos_vespa.x + dx < 1 || pos_vespa.x + dx > MAX_X)
            dx *= -1;

        pos_vespa.x += dx;

        //generazione coordinate asse y

        if (random() < RAND_MAX / 2)
            dy = PASSO;
        else
            dy = -PASSO;

        if (pos_vespa.y + dy < 2 || pos_vespa.y + dy > MAX_Y)
            dy *= -1;

        pos_vespa.y += dy;

        write(pipeOut, &pos_vespa, sizeof(pos_vespa));

        usleep(DELAY);
    }
}

void contadino(int pipeOut)
{
    posizione pos_contadino;
    pos_contadino.x = MAX_X / 2;
    pos_contadino.y = MAX_Y / 2;
    pos_contadino.c = '#';

    write(pipeOut, &pos_contadino, sizeof(pos_contadino));

    while (true)
    {
        char keyPressed = getch();

        switch (keyPressed)
        {
        case UP_KEY:
            if (pos_contadino.y > 1)
                pos_contadino.y -= 1;

            break;
        
        case DOWN_KEY:
            if (pos_contadino.y < MAX_Y - 1)
                pos_contadino.y += 1;

            break;

        case LEFT_KEY:
            if (pos_contadino.x > 0)
                pos_contadino.x -= 1;
            
            break;
        
        case RIGHT_KEY:
            if (pos_contadino.x < MAX_X - 1)
                pos_contadino.x += 1;
            
            break;
        }

        write(pipeOut, &pos_contadino, sizeof(pos_contadino));
    }  
}

void areaGioco(int pipeIn)
{
    posizione vespa, contadino, trappole[3], prevTraps[3], valoreLetto;
    bool flag = true;
    int lifePoints = 3, counter = 0;

    mvprintw(0, 1, "%3d", lifePoints);

    do
    {
        read(pipeIn, &valoreLetto, sizeof(valoreLetto));

        if (valoreLetto.c == 'v')
        {
            mvaddch(vespa.y, vespa.x, ' ');
            
            vespa = valoreLetto;          
        }
        else
        {
            mvaddch(contadino.y, contadino.x, ' ');
           
            contadino = valoreLetto;    
        }

        mvaddch(valoreLetto.y, valoreLetto.x, valoreLetto.c);

        if (counter == 25)
        {
            counter = 0;

            for (int i = 0; i < 3; i++)
                mvaddch(prevTraps[i].y, prevTraps[i].x, ' ');
            
            for (int i = 0; i < 3; i++)
            {
                trappole[i].x = rand() % MAX_X;
                trappole[i].y = rand() % (MAX_Y - 1);
            }

            for (int i = 0; i < 3; i++)
                mvaddch(trappole[i].y, trappole[i].x, 'X');
            
            for (int i = 0; i < 3; i++)
                prevTraps[i] = trappole[i];
        }
        
        for (int i = 0; i < 3; i++)
        {
            if (vespa.x == trappole[i].x && vespa.y == trappole[i].y)
                if (lifePoints < 6)
                    lifePoints++;
                    
        }

        if (vespa.x == contadino.x && vespa.y == contadino.y)
            lifePoints--;
        
        mvprintw(0, 1, "%d", lifePoints);
        refresh();    

        if (valoreLetto.c == 'v')
            counter++;  

         if(lifePoints == 0)
        {
            flag = false;
            flash();
            beep();
        }
    } while (flag);
}