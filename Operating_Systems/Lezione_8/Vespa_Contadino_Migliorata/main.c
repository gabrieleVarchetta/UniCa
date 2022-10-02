#include <curses.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define PASSO 1
#define N_TRAPS 3
#define READ_END 0
#define WRITE_END 1
#define DELAY 90000


typedef struct
{
    char c; //oggetto che invia i dati: guardia o ladro
    int x; 
    int y;
}posizione;

void vespa(int pipeOut);
void contadino(int pipeOut);
void areaGioco(int pipeIn);

int MAX_X, MAX_Y;
char spriteContadino[5] = {"|-o-|"};

int main(int argc, char const *argv[])
{
    int fd[2];
    pid_t vespa_pid, contadino_pid;
    
    srand(time(NULL));
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, true);

    getmaxyx(stdscr, MAX_Y, MAX_X);
    //distacco dal bordo di un carattere
    MAX_X -= 1;
    MAX_Y -= 1;

    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK); //colore vespa
    init_pair(2, COLOR_WHITE, COLOR_BLACK); //colore contadino
    init_pair(3, COLOR_RED, COLOR_BLACK); //colore trappole
    init_pair(4, COLOR_BLACK, COLOR_BLACK); //colore per cancellare

    bkgd(COLOR_PAIR(1));

    if (pipe(fd) == -1)
    {
        perror("Errore nella creazione della pipe.");
        _exit(1);
    }
    
    fflush(stdin);

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
            mvprintw(MAX_Y / 2, MAX_X / 2, "%s", spriteContadino);
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

        if (pos_vespa.y + dy < 1 || pos_vespa.y + dy > MAX_Y)
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
        int keyPressed = getch();

        switch (keyPressed)
        {
        case KEY_UP:
            if (pos_contadino.y > 0)
                pos_contadino.y -= 1;

            break;
        
        case KEY_DOWN:
            if (pos_contadino.y < MAX_Y)
                pos_contadino.y += 1;

            break;

        case KEY_LEFT:
            if (pos_contadino.x > 0)
                pos_contadino.x -= 1;
            
            break;
        
        case KEY_RIGHT:
            if (pos_contadino.x < MAX_X - sizeof(spriteContadino))
                pos_contadino.x += 1;
            
            break;
        }

        write(pipeOut, &pos_contadino, sizeof(pos_contadino));
    }  
}

void areaGioco(int pipeIn)
{
    posizione vespa, contadino, trappole[N_TRAPS], valoreLetto;
    bool flag = true;
    int lifePoints = 3, counter = 0;

    do
    {
        read(pipeIn, &valoreLetto, sizeof(valoreLetto));

        if (valoreLetto.c == 'v')
        {   
            //cancella vecchio oggetto
            attron(COLOR_PAIR(4)); 
            mvprintw(vespa.y, vespa.x, " ");

            //disegna nuovo oggetto            
            attron(COLOR_PAIR(1)); //colore vespa

            bool flagVespa = !flagVespa;

            if(flagVespa)
                mvprintw(valoreLetto.y, valoreLetto.x, "v");
            else
                mvprintw(valoreLetto.y, valoreLetto.x, "^");

            vespa = valoreLetto;          
        }
        else
        {
            attron(COLOR_PAIR(4)); //cancella vecchio oggetto
            mvprintw(contadino.y, contadino.x, "%s", spriteContadino);
            attron(COLOR_PAIR(2)); //colore contadino
            mvprintw(valoreLetto.y, valoreLetto.x, "%s", spriteContadino);
           
            contadino = valoreLetto;    
        }

        if (counter == 25)
        {
            counter = 0;

            attron(COLOR_PAIR(3));

            for (int i = 0; i < N_TRAPS; i++)
                mvaddch(trappole[i].y, trappole[i].x, ' ');
            
            for (int i = 0; i < N_TRAPS; i++)
            {
                trappole[i].x = rand() % MAX_X;
                trappole[i].y = rand() % MAX_Y;
            }

            for (int i = 0; i < N_TRAPS; i++)
                mvaddch(trappole[i].y, trappole[i].x, 'X');
        }
        
        for (int i = 0; i < N_TRAPS; i++)
        {
            if (vespa.x == trappole[i].x && vespa.y == trappole[i].y)
                if (lifePoints < 6)
                {
                    if(vespa.x < MAX_X)
                        vespa.x += 1;
                    else
                        vespa.x -= 1;

                    if(vespa.y < MAX_Y)
                        vespa.y += 1;
                    else
                        vespa.y -= 1;
                    
                    lifePoints++;
                }
                    
        }

        for (int i = 0; i < sizeof(spriteContadino); i++)
        {
            if (vespa.x == (contadino.x + i) && vespa.y == contadino.y)
            {
                if(contadino.y < MAX_Y)
                    contadino.y += 1;
                else
                    contadino.y -= 1;

                lifePoints--;
            }
        }
        
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