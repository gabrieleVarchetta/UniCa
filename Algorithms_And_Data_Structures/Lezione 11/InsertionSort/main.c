#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef enum{ORDINATO, QUASI_ORDINATO, INV_ORDINATO, CASUALE} inputType;
int *genera_array(int dimensione, inputType tipo_schema);
void insertionSort(int *array, int dimensione);
void stampaVettore(int *array, int dimensione);
int inserisciDimensione(void);

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
    insertionSort(vettore, dimensione);
    end = clock();

    tempo = ((double) (end - start)) / CLOCKS_PER_SEC; //calcolo del tempo di esecuzione

    stampaVettore(vettore, dimensione);
    printf("\nTempo impiegato per l'ordinamento di un vettore di %d elementi: %lf secondi",dimensione, tempo);

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

void insertionSort(int *array, int dimensione)
{
    int i, j, next;

    for (i = 1; i <= dimensione - 1; i++)
    {
        next = array[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (next < array[j])
                array[j + 1] = array[j];
            else
                break;
        }
        array[j + 1] = next;
    }
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
                break;

            case 2: dimensione = 1000;
                break;

            case 3: dimensione = 10000;
                break;

            case 4: dimensione = 100000;
                break;

            case 5: dimensione = 200000;
                break;

            case 6: dimensione = 500000;
                break;
        }
    }while (scelta > 6);

    return dimensione;
}