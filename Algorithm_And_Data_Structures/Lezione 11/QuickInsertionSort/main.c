#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef enum{ORDINATO, QUASI_ORDINATO, INV_ORDINATO, CASUALE} inputType;
int *genera_array(int dimensione, inputType tipo_schema);
void quickInsertionSort(int * array, int u, int v, int M);
void insertionSort(int *array, int primo, int ultimo);
int perno(int *array, int primo, int ultimo);
void swap(int *variabile1, int *variabile2);
void stampaVettore(int *array, int dimensione);
int inserisciDimensione(void);


int main()
{
    int dimensione, cutAlgorithm;
    int *vettore = NULL;
    inputType tipo;
    clock_t start, end;
    double tempo;

    srand(time(NULL));

    //dimensione = inserisciDimensione();

    printf("\nInserisci la dimensione desiderata: ");
    scanf("%d", &dimensione);
    printf("\nInserisci il tipo di schema di ordinamento del vettore.");
    printf("\nORDINATO - 0\nQUASI ORDINATO - 1\nINVERSAMENTE ORDINATO - 2\nCASUALE - 3\n");
    scanf("%d", &tipo);

    vettore = genera_array(dimensione, tipo);

    printf("\nInserisci il valore per il quale si passa da quickSort a insertionSort:  ");
    scanf("%d", &cutAlgorithm);

    printf("\nVettore prima dell'ordinamento: ");
    stampaVettore(vettore, dimensione);

    printf("\nVettore dopo l'ordinamento: ");

    start = clock();
    quickInsertionSort(vettore, 0, dimensione - 1, cutAlgorithm);
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
                vettore[i] = i + 1;
            break;

        case QUASI_ORDINATO: for(i = 0; i < dimensione; i++)
            {
                if (i >= 0 && i <= ((dimensione/2)-1)) //fino a metà, elementi ordinati
                    vettore[i] = i + 1;
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

void quickInsertionSort(int * array, int primo, int ultimo, int M)
{
    int q;
    
    if (M >= ultimo - primo)
    {
        q = perno(array, primo, ultimo);

        if (primo < q) quickInsertionSort(array, primo, q - 1, M);

        if (q < ultimo) quickInsertionSort(array, q + 1, ultimo, M);
    }
    else
        insertionSort(array, primo, ultimo);
}

/**
 * algoritmo modificato per usarlo nel quickInsertionSort, la modifica consiste
 * nel far partire i confronti dal valore di primo e farli finire al valore di
 * ultimo, così ordinerà solo la lista parziale designata da questi due valori.
 * @param array vettore da ordinare
 * @param primo primo elemento della sottolista
 * @param ultimo ultimo elemento della sottolista
 */
void insertionSort(int *array, int primo, int ultimo)
{
    int i, j, next;

    for (i = primo; i <= ultimo; i++)
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
            case 1: dimensione = 15;
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
