#include <pthread.h>
#include <stdio.h>

typedef struct
{
    char character;
    int count;
}char_print_parms;

void* char_print(void *parameters);

int main(int argc, char const *argv[])
{
    pthread_t thread1_id, thread2_id;

    char_print_parms thread1_args, thread2_args;

    thread1_args.character = 'x';
    thread1_args.count = 30000;
    pthread_create(&thread1_id, NULL, &char_print, &thread1_args);

    thread2_args.character = 'o';
    thread2_args.count = 20000;
    pthread_create(&thread2_id, NULL, &char_print, &thread2_args);

    pthread_join(thread1_id, NULL);
    pthread_join(thread2_id, NULL);

    return 0;
}

void* char_print(void *parameters)
{
    char_print_parms *p;
    p = (char_print_parms*) parameters;

    for (int i = 0; i < p->count; i++)
        fputc(p->character, stderr);

    return NULL;
}