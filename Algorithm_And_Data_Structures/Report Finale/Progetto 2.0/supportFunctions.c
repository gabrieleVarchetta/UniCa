//
// Created by GAB on 14/05/2021.
//

#include "supportFunctions.h"

int scambi = 0, confronti = 0;

void operazioniSelection(int *vettore, int dimensione)
{
    clock_t start, end;
    double tempo;

    printf("\nStampa dei primi elementi del vettore non ordinato");
    stampaVettore(vettore, dimensione);

    printf("\nStampa dei primi elementi del vettore ordinato");

    start = clock();
    selectionSort(vettore, dimensione);
    end = clock();

    tempo = ((double) (end - start)) / CLOCKS_PER_SEC; //calcolo del tempo di esecuzione

    stampaVettore(vettore, dimensione);
    stampaTempiConfrontiScambi(tempo, confronti, scambi, dimensione);
}

void operazioniInsertion(int *vettore, int dimensione)
{
    clock_t start, end;
    double tempo;

    printf("\nStampa dei primi elementi del vettore non ordinato");
    stampaVettore(vettore, dimensione);

    printf("\nStampa dei primi elementi del vettore ordinato");

    start = clock();
    insertionSort(vettore, dimensione);
    end = clock();

    tempo = ((double) (end - start)) / CLOCKS_PER_SEC; //calcolo del tempo di esecuzione

    stampaVettore(vettore, dimensione);
    stampaTempiConfrontiScambi(tempo, confronti, scambi, dimensione);
}

void operazioniQuick(int *vettore, int dimensione)
{
    clock_t start, end;
    double tempo;

    printf("\nStampa dei primi elementi del vettore non ordinato");
    stampaVettore(vettore, dimensione);

    printf("\nStampa dei primi elementi del vettore ordinato");

    start = clock();
    quickSort(vettore, 0, dimensione - 1);
    end = clock();

    tempo = ((double) (end - start)) / CLOCKS_PER_SEC; //calcolo del tempo di esecuzione

    stampaVettore(vettore, dimensione);
    stampaTempiConfrontiScambi(tempo, confronti, scambi, dimensione);
}

void operazioniMerge(int *vettore, int dimensione)
{
    int *ordinata = NULL;
    clock_t start, end;
    double tempo;

    ordinata = (int*)malloc(dimensione * sizeof(int));

    printf("\nStampa dei primi elementi del vettore non ordinato");
    stampaVettore(vettore, dimensione);

    printf("\nStampa dei primi elementi del vettore ordinato");

    start = clock();
    mergeSort(vettore, ordinata, 0, dimensione - 1);
    end = clock();

    tempo = ((double) (end - start)) / CLOCKS_PER_SEC; //calcolo del tempo di esecuzione

    stampaVettore(vettore, dimensione);
    stampaTempiConfrontiScambi(tempo, confronti, scambi, dimensione);
}

void operazioniHeap(int *vettore, int dimensione)
{
    clock_t start, end;
    double tempo;

    printf("\nStampa dei primi elementi del vettore non ordinato");
    stampaHeap(vettore, dimensione);

    printf("\nStampa dei primi elementi del vettore ordinato");

    start = clock();
    heapSort(vettore, dimensione);
    end = clock();

    tempo = ((double) (end - start)) / CLOCKS_PER_SEC; //calcolo del tempo di esecuzione

    stampaHeap(vettore, dimensione);
    stampaTempiConfrontiScambi(tempo, confronti, scambi, dimensione);
}

void stampaTempiConfrontiScambi(double time, int confronti, int scambi, int dim)
{
    printf("\nTempo impiegato per l'ordinamento di un vettore di %d elementi: %lf secondi",dim, time);
    printf("\nConfronti effettuati: %d", confronti);
    printf("\nScambi effettuati: %d", scambi);
}

void stampaScelteAlgoritmi(void)
{
    printf("\n0. SELECTION SORT");
    printf("\n1. INSERTION SORT");
    printf("\n2. MERGE SORT");
    printf("\n3. HEAP SORT");
    printf("\n4. QUICK SORT\n");
}

void stampaScelteOrdinamentoVettore(void)
{
    printf("\n0. ORDINATO");
    printf("\n1. QUASI ORDINATO");
    printf("\n2. INVERSAMENTE ORDINATO");
    printf("\n3. CASUALE\n");
}

void incComparison(void)
{
    confronti++;
}

void incSwaps(void)
{
    scambi++;
}

void resetComparison(void)
{
    confronti = 0;
}

void resetSwaps(void)
{
    scambi = 0;
}

int getComparison(void)
{
    return confronti;
}

int getSwaps(void)
{
    return scambi;
}

