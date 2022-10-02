#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <semaphore.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t job_counter;

int value = 0, counter = 0;
char* dati[10];

void* delete();
void init_queue();
void add_job(char* job);

int main(int argc, char const *argv[])
{
    int i;
    pthread_t threads[3];
    srand(time(NULL));

    init_queue();

    add_job("rosso");
    add_job("verde");
    add_job("giallo");
    add_job("blu");

    for(i = 0; i < 3; i++)
        pthread_create(&threads[i], NULL, &delete, NULL);

    add_job("nero");
    add_job("grigio");
    add_job("porcodio");

    for(i = 0; i < 3; i++)
        pthread_join(threads[i], NULL);

    return 0;
}

void* delete() {
    int i, j;
    pthread_t th;
    char name[100];

    while(1) {
        sem_wait(&job_counter); //nessun job: wait
        pthread_mutex_lock(&mutex);

        strcpy(name, dati[counter - 1]);
        dati[counter - 1] = NULL;

        th = pthread_self();
        sleep((int) (5.0 * rand() / (RAND_MAX + 1.0)));
        printf("Deleted %s by thread %lu \n", name, (unsigned long)th);

        counter--;
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

void init_queue() {
    counter = 0;
    sem_init(&job_counter, 0, 0);
}

void add_job(char* job) {
    pthread_mutex_lock(&mutex);

    if(counter < 10) {
        dati[counter] = job;
        counter++;
        sem_post(&job_counter);
    }

    pthread_mutex_unlock(&mutex);
}