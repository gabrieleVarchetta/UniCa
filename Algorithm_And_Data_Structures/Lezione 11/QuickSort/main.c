#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef enum{ORDINATO, QUASI_ORDINATO, INV_ORDINATO, CASUALE} inputType;
int *genera_array(int dimensione, inputType tipo_schema);
void quickSort(int *array, int u, int v);
int perno(int *array, int primo, int ultimo);
void swap(int *variabile1, int *variabile2);
void stampaVettore(int *array, int dimensione);
int inserisciDimensione(void);

int stop = 0;

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
    printf("\n0. ORDINATO\n1. QUASI ORDINATO\n2. INVERSAMENTE ORDINATO\n3. CASUALE\n");
    scanf("%d", &tipo);

    vettore = genera_array(dimensione, tipo);

    printf("\nVettore prima dell'ordinamento: ");
    stampaVettore(vettore, dimensione);

    printf("\nVettore dopo l'ordinamento...\n");

    start = clock();
    quickSort(vettore, 0, dimensione - 1);
    end = clock();

    tempo = ((double) (end - start)) / CLOCKS_PER_SEC; //calcolo del tempo di esecuzione

    stampaVettore(vettore, dimensione);
    printf("\nTempo impiegato per l'ordinamento di un vettore di %d elementi: %lf secondi",dimensione, tempo);

    return 0;
}

int *genera_array(int dimensione, inputType tipo_schema)
{
    int *vettore = NULL;
    int i, j, k = 1;

    vettore = (int *) malloc(dimensione * sizeof(int));

    switch (tipo_schema)
    {
        case ORDINATO: for(i = 0; i < dimensione; i++)
                        {
                            vettore[i] = k;
                            k++;
                        }

            break;

        case QUASI_ORDINATO: for(i = 0; i < dimensione; i++)
                                {
                                    if (i >= 0 && i <= ((dimensione/2)-1)) //fino a metà, elementi ordinati
                                        vettore[i] = k;
                                    else if(i >= (dimensione/2) && i <= dimensione - 1) //dalla metà alla fine elementi random
                                        vettore[i] = rand() % 101;

                                    k++;
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

void quickSort(int *array, int u, int v)
{
    int q;

    //if (stop == 4)
       // return;

    if (u == v) return;

    q = perno(array, u, v);

    if (u < q) quickSort(array, u, q - 1);

    if (q < v) quickSort(array, q + 1, v);
}

int perno(int *array, int primo, int ultimo)
{
    int i, j, pivot;

    i = primo;
    j = ultimo + 1;
    pivot = array[primo];

    while (i < j)
    {
        do
        {
            i = i + 1;
        }while (array[i] <= pivot && i <= ultimo);

        do
        {
            j = j - 1;
        }while (array[j] > pivot && j >= primo);

        if (i < j)
            swap(&array[i], &array[j]);
    }
    swap(&array[primo], &array[j]);

    //stop++;

    return j;
}

void swap(int *variabile1, int *variabile2)
{
    int temp;

    temp = *variabile1;
    *variabile1 = *variabile2;
    *variabile2 = temp;
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

            case 6: dimensione = 50000;
                break;
        }
    }while (scelta > 6);

    return dimensione;
}