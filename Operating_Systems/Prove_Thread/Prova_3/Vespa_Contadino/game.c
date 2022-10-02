#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define	UP	 	 65						/* Cursore sopra */
#define DW	 	 66						/* Cursore sotto */
#define	SX 		 68						/* Cursore sinistra */
#define DX	 	 67						/* Cursore destra */
#define	MAXX	 100						/* Dimensione dello schermo di output (colonne) */
#define MAXY	 25					/* Dimensione dello schermo di output (righe)   */
#define DELAY 250000  /* Ritardo nel movimento delle vespe (da adattare) */
#define DIM_BUFFER 10

/* Struttura adoperata per veicolare le coordinate */
struct position {
  int  x;	 /* Coordinata X */
  int  y;	 /* Coordinata Y */
  int id;
};

/* Prototipi delle funzioni adoperate */
void* vespa();
void* contadino();
void area_gioco();
void produce(struct position pos);
void consume();

/* Variabili globali per passaggio dati tra threads e segnalazione collisione */
struct position pVespa;	
struct position pContadino;	
int collision = 0, count = 0;
struct position buffer[DIM_BUFFER];
struct position consumed;

pthread_mutex_t mutex_buffer, mutex_print;
sem_t full, empty;

int main(int argc, char const *argv[])
{
    pthread_t th_player, th_vespa;

    srand(time(NULL));
    initscr();
    noecho();
    curs_set(0);

    pthread_mutex_init(&mutex_buffer, NULL);
    pthread_mutex_init(&mutex_print, NULL);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, DIM_BUFFER);

    if(pthread_create(&th_vespa, NULL, &vespa, NULL) != 0) {
        perror("Error creating the thread.");
        exit(1);
    }

    if(pthread_create(&th_player, NULL, &contadino, NULL) != 0) {
        perror("Error creating the thread.");
        exit(1);
    }

    area_gioco();

    if(pthread_join(th_vespa, NULL) != 0) {
        perror("Error joining the thread.");
        exit(1);
    }

    if(pthread_join(th_player, NULL) != 0) {
        perror("Error joining the thread.");
        exit(1);
    }

    pthread_mutex_destroy(&mutex_buffer);
    pthread_mutex_destroy(&mutex_print);
    sem_destroy(&full);
    sem_destroy(&empty);

    endwin();
    
    printf("GAME OVER\n");

    return 0;
}

void* vespa() {
    int dx, dy;

    pVespa.x = 10;
    pVespa.y = 10;
    pVespa.id = 0;

    while(!collision) {
   

        if(random() < RAND_MAX / 2)
            dx = 1;
        else
            dx = -1;

        if(random() < RAND_MAX / 2)
            dy = 1;
        else
            dy = -1;

        if(pVespa.x + dx < 1 || pVespa.x +dx > MAXX)
            dx *= -1;
        
        if(pVespa.y + dy < 1 || pVespa.y + dy > MAXY)
            dy *= -1;

        pVespa.x += dx;
        pVespa.y += dy;

        produce(pVespa);

        usleep(DELAY);
    }

    return NULL;
}

void* contadino() {
    pContadino.x = MAXX / 2;
    pContadino.y = MAXY / 2;
    pContadino.id = 1;

    char keyPressed;

    while(!collision) {
        keyPressed = getch();

        switch(keyPressed) {
            case UP:
                pContadino.y--;
                break;
            
            case DW:
                pContadino.y++;
                break;

            case SX:
                pContadino.x--;
                break;

            case DX:
                pContadino.x++;
                break;
            
            default:
                continue;
        }

        produce(pContadino);
    }

    return NULL;
}

void area_gioco() {
    struct position contadino, vespa;

    while (!collision) {
        consume();
        
        if(consumed.id == 0) {
            pthread_mutex_lock(&mutex_print);
                if(vespa.x >= 0)
                    mvaddch(vespa.y, vespa.x, ' ');

                refresh();

                vespa = consumed;

                mvaddch(vespa.y, vespa.x, '#');
                refresh();
            pthread_mutex_unlock(&mutex_print);
        }
        else {
                pthread_mutex_lock(&mutex_print);
                    if(contadino.x >= 0)
                        mvaddch(contadino.y, contadino.x, ' ');

                    refresh();

                    contadino = consumed;

                    mvaddch(contadino.y, contadino.x, '#');
                    refresh();
                pthread_mutex_unlock(&mutex_print);
        }

        if(vespa.x == contadino.x && vespa.y == contadino.y)
            collision = 1;
    }
}

void produce(struct position pos) {
    sem_wait(&empty);
    pthread_mutex_lock(&mutex_buffer);
        buffer[count] = pos;
        count++;
    pthread_mutex_unlock(&mutex_buffer);
    sem_post(&full);
}

void consume() {
    sem_wait(&full);
    pthread_mutex_lock(&mutex_buffer);
        consumed = buffer[count - 1];
        count--;
    pthread_mutex_unlock(&mutex_buffer);
    sem_post(&empty);
}
