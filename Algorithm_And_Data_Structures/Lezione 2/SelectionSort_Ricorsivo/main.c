#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef enum{ORDINATO, QUASI_ORDINATO, INV_ORDINATO, CASUALE} inputType;

void selectionSortRec(int *array, int dimA, int start);
int findmin(int *array, int minpos, int start, int dim);
void swap(int *array, int i, int min);
int inserisciDimensione(void);
void stampaVettore(int *array, int dimensione);
int *genera_array(int dimensione, inputType tipo_schema);

static unsigned long long int confrontiRicorsivi = 0, scambiRicorsivi = 0;

int main()
{
    int dimensione, *vettore = NULL, tipo, inizio = 0;
    clock_t start, end;
    double tempo;

    dimensione = inserisciDimensione();

    printf("\nInserisci il tipo di schema di ordinamento del vettore. \n");
    printf("\nORDINATO - 0\nQUASI ORDINATO - 1\nINVERSAMENTE ORDINATO - 2\nCASUALE - 3\n");
    scanf("%d", &tipo);

    vettore = genera_array(dimensione, tipo);
    printf("\nVettore prima: \n");
    stampaVettore(vettore, dimensione);

    printf("\nRiordino il vettore...\n");
    start = clock();
    selectionSortRec(vettore, dimensione, inizio);
    end = clock();
    tempo = (double)(end - start) / (CLOCKS_PER_SEC);

    printf("\n\n");
    printf("Vettore dopo: \n");
    stampaVettore(vettore, dimensione);

    printf("\nTempo impiegato per l'ordinamento di un vettore di %d elementi: %lf secondi",dimensione, tempo);
    printf("\nConfronti effettuati: %llu", confrontiRicorsivi);
    printf("\nScambi effettuati: %llu", scambiRicorsivi);

    return 0;
}

void selectionSortRec(int *array, int dimA, int start)
{
    int minIndex;

    if (start < dimA - 1)
    {
        minIndex = findmin(array, start, start + 1, dimA);
        swap(array, start, minIndex);
        selectionSortRec(array, dimA, start + 1);
    }
}

int findmin(int *array, int minpos, int start, int dim)
{
    if (start == dim)
        return minpos;

    confrontiRicorsivi++;
    if (array[start] < array[minpos])
        minpos = start;


    return findmin(array, minpos, start + 1, dim);
}

void swap(int *array, int i, int min)
{
    int temp;

    temp = array[i];
    array[i] = array[min];
    array[min] = temp;
    scambiRicorsivi++;
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

            case 6: dimensione = 500000;
                flag = true;
                break;
        }
    }while (flag != true);

    return dimensione;
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