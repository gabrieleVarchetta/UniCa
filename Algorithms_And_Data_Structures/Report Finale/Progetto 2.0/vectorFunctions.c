//
// Created by GAB on 14/05/2021.
//

#include "vectorFunctions.h"

int *genera_array(int dimensione, inputType tipo_schema, sortingAlgo algo)
{
    int *vettore = NULL;
    int i, j, k = 1;

    /*se l'utente sceglie di usare l'heapSort, imposto il contatore i a 1 per iniziare a riempire dalla seconda cella
     * e aumento la dimensione di 1, così da poter usare l'heapSort che appunto sfrutta la struttra dati Heap
     */
    if (algo == HEAP_SORT)
    {
        i = 1;
        dimensione++;
    }
    else
        i = 0;

    vettore = (int *) malloc(dimensione * sizeof(int));

    switch (tipo_schema)
    {
        case ORDINATO: for(; i < dimensione; i++)
            {
                vettore[i] = k;
                k++;
            }
            break;

        case QUASI_ORDINATO: for(; i < dimensione; i++)
            {
                if (i >= 0 && i <= ((dimensione/2)-1)) //fino a metà, elementi ordinati
                {
                    vettore[i] = k;
                    k++;
                }
                else if(i >= (dimensione/2) && i <= dimensione - 1) //dalla metà alla fine elementi random
                    vettore[i] = rand() % 101;
            }
            break;

        case INV_ORDINATO: j = dimensione;
            for(; i < dimensione; i++)
            {
                vettore[i] = j;
                j--;
            }
            break;

        case CASUALE: for(; i < dimensione; i++)
            {
                vettore[i] = rand() % 101;
            }
            break;
    }

    return vettore;
}

int inserisciDimensione(void)
{
    int scelta, dimensione;

    do
    {
        printf("\nSeleziona la dimensione del vettore");
        printf("\nDimensioni tra cui scegliere: \n");
        printf("1. 15\n2. 1000\n3. 2000\n4. 5000\n5. 10000\n6. 20000\n7. 50000\n");
        scanf("%d", &scelta);

        switch (scelta)
        {
            case 1: dimensione = 15;
                break;

            case 2: dimensione = 1000;
                break;

            case 3: dimensione = 2000;
                break;

            case 4: dimensione = 5000;
                break;

            case 5: dimensione = 10000;
                break;

            case 6: dimensione = 20000;
                break;

            case 7: dimensione = 50000;
                break;
        }
    }while (scelta <= 0 || scelta > 7);

    return dimensione;
}

void stampaVettore(int *array, int dimensione)
{
    int i, j = 0, k = 0;

    printf("\n");

    for(i = 0; i < dimensione; i++)
    {
        printf("%d\t", array[i]);
        j++;
        k++;

        if (j == 10)
        {
            printf("\n");
            j = 0;
        }
        if (k == 100)
            break;
    }
}

void stampaHeap(int *array, int dimensione)
{
    int i, j = 0, k = 0;

    printf("\n");

    for(i = 1; i < dimensione + 1; i++)
    {
        printf("%d\t", array[i]);
        j++;
        k++;

        if (j == 10)
        {
            printf("\n");
            j = 0;
        }
        if (k == 100)
            break;
    }
}

