#include <stdio.h>
#include <pthread.h>
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_X 100
#define MAX_Y 25

pthread_mutex_t print_mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct {
    char character; //character to print
    int count; //number of times to print 
} charPrintParams;

void* print(void* args);

int main(int argc, char const *argv[]) {
    pthread_t threadId_1, threadId_2;

    charPrintParams threadArgs_1, threadArgs_2;

    initscr();
    noecho();
    curs_set(0);

    //creation of the first thread, wich print 'x' 30000 times
    threadArgs_1.character = 'x';
    threadArgs_1.count = 30000;
    pthread_create(&threadId_1, NULL, &print, &threadArgs_1);

    //creation of the second thread, wich print 'o' 20000 times
    threadArgs_2.character = 'o';
    threadArgs_2.count = 20000;
    pthread_create(&threadId_2, NULL, &print, &threadArgs_2);

    //wait for the threads to finish their executions
    pthread_join(threadId_1, NULL);
    pthread_join(threadId_2, NULL);

    endwin();
    return 0;
}

void* print(void* args) {
    charPrintParams* params;
    int i, x, y;

    //casting to the correct type
    params = (charPrintParams*) args;
    
    for (i = 0; i < params->count; i++) {
        pthread_mutex_lock(&print_mutex);
        /* Start of the critic section */
        x = rand() % MAX_X;
        y = rand() % MAX_Y;

        mvaddch(y, x, params->character);
     

        curs_set(0);

        refresh();

        usleep(10000);
        /* End of the critic section */
        pthread_mutex_unlock(&print_mutex);
    }
    
    return NULL;
}