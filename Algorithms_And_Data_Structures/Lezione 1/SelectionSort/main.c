#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum{ORDINATO, QUASI_ORDINATO, INV_ORDINATO, CASUALE} inputType;
int *genera_array(int dimensione, inputType tipo_schema);
void selectionSort(int *array, int dimensione);
void swap(int *array, int i, int min);
void stampaVettore(int *array, int dimensione);
int inserisciDimensione(void);

static unsigned long long int confrontiIterativi = 0, scambiIterativi = 0;

int main()
{
    int dimensione;
    int *vettore = NULL;
    inputType tipo;
    clock_t start, end;
    double tempo;

    srand(time(NULL));

    dimensione = inserisciDimensione();

    printf("\nInserisci il tipo di schema di ordinamento del vettore. \n");
    printf("\nORDINATO - 0\nQUASI ORDINATO - 1\nINVERSAMENTE ORDINATO - 2\nCASUALE - 3\n");
    scanf("%d", &tipo);

    vettore = genera_array(dimensione, tipo);

    printf("\nVettore prima dell'ordinamento: ");
    stampaVettore(vettore, dimensione);

    printf("\nVettore dopo l'ordinamento...\n");

    start = clock();
    selectionSort(vettore, dimensione);
    end = clock();

    tempo = ((double) (end - start)) / CLOCKS_PER_SEC; //calcolo del tempo di esecuzione

    stampaVettore(vettore, dimensione);
    printf("\nTempo impiegato per l'ordinamento di un vettore di %d elementi: %lf secondi",dimensione, tempo);
    printf("\nConfronti effettuati: %llu", confrontiIterativi);
    printf("\nScambi effettuati: %llu", scambiIterativi);

    return 0;
}

int *genera_array(int dimensione, inputType tipo_schema)
{
    int *vettore = NULL;
    int i, j;

    vettore = (int *) malloc(dimensione * sizeof(int));

    switch (tipo_schema)
    {
        case ORDINATO: for(i = 0; i < dimensione; i++)
                        vettore[i] = i;
            break;

        case QUASI_ORDINATO: for(i = 0; i < dimensione; i++)
                                {
                                    if (i >= 0 && i <= ((dimensione/2)-1)) //fino a metà, elementi ordinati
                                        vettore[i] = i;
                                    else if(i >= (dimensione/2) && i <= dimensione - 1) //dalla metà alla fine elementi random
                                        vettore[i] = rand() % 101;
                                }
            break;

        case INV_ORDINATO: j = dimensione;
                           for(i = 0; i < dimensione; i++)
                              {
                                  vettore[i] = j;
                                  j--;
                              }
            break;

        case CASUALE: for(i = 0; i < dimensione; i++)
                         {
                            vettore[i] = rand() % 101;
                         }
            break;

    }

    return vettore;
}

void selectionSort(int *array, int dimensione)
{
    int i, j, min;
    for(i = 0; i <= dimensione - 2; i++)
    {
        min = i;
        for(j = i + 1; j <= dimensione - 1; j++)
        {
            confrontiIterativi++;
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        swap(array, i, min);
        scambiIterativi++;
    }
}

void swap(int *array, int i, int min)
{
    int temp;

    temp = array[i];
    array[i] = array[min];
    array[min] = temp;
}

void stampaVettore(int *array, int dimensione)
{
    int i, j = 0;

    printf("\n");

    for(i = 0; i < dimensione; i++)
    {
        printf("%d\t", array[i]);
        j++;

        if (j == 10)
        {
            printf("\n");
            j = 0;
        }
    }
}

int inserisciDimensione(void)
{
    bool flag = false;
    int scelta, dimensione;

    do
    {
        printf("\nInserisci la dimensione del vettore. \n");
        printf("\nDimensioni tra cui scegliere: \n");
        printf("1. 100\n2. 1000\n3. 10000\n4. 100000\n5. 200000\n6. 500000\n");
        scanf("%d", &scelta);

        switch (scelta)
        {
            case 1: dimensione = 100;
                flag = true;
                break;

            case 2: dimensione = 1000;
                flag = true;
                break;

            case 3: dimensione = 10000;
                flag = true;
                break;

            case 4: dimensione = 100000;
                flag = true;
                break;

            case 5: dimensione = 200000;
                flag = true;
                break;

            case 6: dimensione = 50000;
                flag = true;
                break;
        }
    }while (flag != true);

    return dimensione;
}