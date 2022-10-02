//
// Created by GAB on 14/05/2021.
//

#include "sortingAlgorithms.h"
#include "supportFunctions.h"

void swap(int *variabile1, int *variabile2)
{
    int temp;

    temp = *variabile1;
    *variabile1 = *variabile2;
    *variabile2 = temp;
    incSwaps();
}

void selectionSort(int *array, int dimensione)
{
    int i, j, min;
    for(i = 0; i <= dimensione - 2; i++)
    {
        min = i;
        for(j = i + 1; j <= dimensione - 1; j++)
        {
            incComparison();
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        swap(&array[i], &array[min]);
    }
}

void insertionSort(int *array, int dimensione)
{
    int i, j, next;

    for (i = 1; i <= dimensione - 1; i++)
    {
        next = array[i];
        for (j = i - 1; j >= 0; j--)
        {
            incComparison();
            if (next < array[j])
            {
                array[j + 1] = array[j];
                incSwaps();
            }
            else
                break;
        }
        array[j + 1] = next;
        incSwaps();
    }
}

void quickSort(int *array, int u, int v)
{
    int q;

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
            i++;
            incComparison();
        }while ( i <= ultimo && array[i] <= pivot);

        do
        {
            j--;
            incComparison();
        }while (j >= primo && array[j] > pivot);

        if (i < j)
            swap(&array[i], &array[j]);
    }
    swap(&array[primo], &array[j]);

    return j;
}

void heapSort(int *vettore, int n)
{
    int i;

    //si costruisce lo heap associato all'insieme da ordinare lista
    for (i = n / 2; i >= 1; i--)
        adatta(vettore, i, n);

    for (i = n - 1; i >= 1; i--)
    {
        //si estrae, di volta in volta, il massimo lista[1] e lo si posiziona in fondo alla sequenza
        swap(&vettore[1], &vettore[i + 1]);

        // si opera nuovamente sullo heap ridotto di un elemento
        adatta(vettore, 1, i);
    }
}

void adatta(int *array, int radice, int n)
{
    int temp, figlio;

    temp = array[radice];
    figlio = 2 * radice; //figlio sx, il figlio dx sarà uguale a figlio + 1

    while (figlio <= n)
    {
        //trova il maggiore tra il figlio sx e figlio dx
        incComparison();
        if (figlio < n && array[figlio] < array[figlio + 1])
            figlio = figlio + 1;

        //confronta la radice e figlio max
        incComparison();
        if (temp > array[figlio])
            break; //il padre di figlio sarà nella posizione corretta
        else
        {
            array[figlio / 2] = array[figlio]; //il figlio si sposta verso il padre

            //ripeti sul sottoalbero selezionato
            figlio = 2 * figlio;
            incSwaps();
        }
    }
    array[figlio / 2] = temp; //copia la radice nella posizione corretta
    incSwaps();
}

void mergeSort(int *vettore, int *ordinata, int lower, int upper)
{
    int medium;

    if (lower >= upper) return;

    medium = (lower + upper) / 2; //prendo il valore a metà
    mergeSort(vettore, ordinata, lower, medium); //prima metà del vettore
    mergeSort(vettore, ordinata, medium + 1, upper); //seconda metà del vettore
    merge(vettore, ordinata, lower, medium, upper); //fondo in un unico vettore gli altri vettori ordinati
}

void merge(int *array, int *ordinata, int i, int m, int n)
{
    int j, k, posIniziale, t;

    j = m + 1; //indice per la seconda parte del vettore
    k = i; //indice per il vettore ordinato "ordinata"
    posIniziale = i; //posizione iniziale nel vettore

    while (i <= m && j <= n)
    {
        incComparison();
        if (array[i] <= array[j])
        {
            ordinata[k] = array[i];
            i++;
            k++;
        }
        else
        {
            ordinata[k] = array[j];
            j++;
            k++;
        }
        incSwaps();
    }
    if (i > m)
        for (t = j; t <= n; t++)
        {
            ordinata[k + t - j] = array[t];
            incSwaps();
        }
    else
        for (t = i; t <= m; t++)
        {
            ordinata[k + t - i] = array[t];
            incSwaps();
        }

    for (; posIniziale <= n; posIniziale++)
        array[posIniziale] = ordinata[posIniziale];
}
