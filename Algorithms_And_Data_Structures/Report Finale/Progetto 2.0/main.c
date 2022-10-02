//Inclusione librerie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vectorFunctions.h"
#include "supportFunctions.h"

//Definzione macro
#define N_DIM 7

//Funzioni scelta versione
void testAutomatico(int *vDim, int* vettore);
void testManuale(void);

int main()
{
    int *vettore = NULL;
    int vDim[N_DIM] = {500, 1000, 2000, 5000, 10000, 20000, 50000}; //vettore contenente le varie dimensioni
    int scelta;

    srand(time(NULL)); //inizializzazione del seed random

    printf("\nInserire 0 per la modalita' auotamtica\nInserire 1 per la modalita' manuale\n");
    scanf("%d", &scelta);

    if (scelta == 0)
        testAutomatico(vDim, vettore);
    else
        testManuale();

    free(vettore); //Libero memoria allocata in precedenza dal vettore

    return 0;
}

void testAutomatico(int *vDim, int* vettore)
{
    int nElementi, dim;
    //vettore di stringhe contenente il nome dei vari schemi di ordinamento
    char typeArray[][30] = {"ORDINATO", "QUASI_ORDINATO", "INV_ORDINATO", "CASUALE"};

    //vettore di stringhe contenente il nome dei vari algoritmi di ordinamento
    char aType[][30] = {"Selection Sort","Insertion Sort","Merge Sort","Heap Sort","Quick Sort"};

    //variabile per lo schema di ordinamento
    inputType arrayType;

    //variabile per l'algoritmo di ordinamento
    sortingAlgo algoritmo;

    //variabili per il calcolo del tempo di esecuzione
    clock_t start , end;
    double tempo;

    //vettore per il mergesort
    int *ordinata = NULL;

    //puntatore a file per scrivere i risultati su file di testo
    FILE *csv = NULL;

    //apertura file di testo in modalità WRITE, così da aggiungere alla fine del file i vari risultati
    csv = fopen("risultatiTestLol122.csv", "w");

    for(arrayType = 0; arrayType < 4; arrayType++)//scorre i possibili schemi di ordinamento del vettore
    {
        printf("\nINSIEME %s", typeArray[arrayType]);
        fprintf(csv, "\nINSIEME %s", typeArray[arrayType]);

        for(nElementi = 0; nElementi < 7; nElementi++ )//scorre le possibili dimensioni del vettore da ordinare
        {
            printf("\n\nNUMERO ELEMENTI: %d", vDim[nElementi]);
            fprintf(csv, "\n\nNUMERO ELEMENTI: %d", vDim[nElementi]);

            for(algoritmo = 0; algoritmo < 5; algoritmo++ )//scorre i vari algoritmi da utilizzare
            {
                resetSwaps();
                resetComparison();
                dim = vDim[nElementi];
                vettore = genera_array(dim, arrayType, algoritmo);

                switch (algoritmo)//il for incrementa la variabile algoritmo, così verranno svolti i test per ogni algo
                {
                    case SELECTION_SORT:
                        start = clock();
                        selectionSort(vettore, dim);
                        end = clock();
                        free(vettore);
                        break;

                    case INSERTION_SORT:
                        start = clock();
                        insertionSort(vettore, dim);
                        end = clock();
                        free(vettore);
                        break;

                    case MERGE_SORT:
                        ordinata = (int *) malloc(dim * sizeof(int));

                        start = clock();
                        mergeSort(vettore, ordinata,0 , dim-1);
                        end = clock();

                        free(ordinata);
                        free(vettore);
                        break;

                    case HEAP_SORT:
                        start = clock();
                        heapSort(vettore, dim);
                        end = clock();
                        free(vettore);
                        break;

                    case QUICK_SORT:
                        start = clock();
                        quickSort(vettore, 0, dim - 1);
                        end = clock();
                        free(vettore);
                        break;
                }
                tempo =((double)(end - start)) / CLOCKS_PER_SEC;

                printf("\n%-15s : tempo: %lf\tNumero confronti : %-10d\tNumero scambi : %-10d", aType[algoritmo], tempo, getComparison(), getSwaps());
                fprintf(csv, "\n%-15s; %-10d; %-10d; %lf", aType[algoritmo], getComparison(), getSwaps(), tempo);
            }
            printf("\n\n");
            fprintf(csv, "\n\n");
        }
    }
    fclose(csv);
}

void testManuale(void)
{
    int sceltaDimensione, *vettore = NULL, sceltaMenu;
    inputType sceltaSchemaOrdinamento;
    sortingAlgo sceltaAlgoritmoSorting;

    do
    {
        resetComparison();
        resetSwaps();
        //sceltaDimensione = inserisciDimensione();

        printf("\nInserire la dimensione desiderata: ");
        scanf("%d", &sceltaDimensione);

        printf("\nSeleziona lo schema di ordinamento del vettore");
        stampaScelteOrdinamentoVettore();
        scanf("%d", &sceltaSchemaOrdinamento);

        printf("\nSeleziona l'algoritmo di ordinamento da usare");
        stampaScelteAlgoritmi();
        scanf("%d", &sceltaAlgoritmoSorting);

        vettore = genera_array(sceltaDimensione, sceltaSchemaOrdinamento, sceltaAlgoritmoSorting);

        switch (sceltaAlgoritmoSorting)
        {
            case SELECTION_SORT: operazioniSelection(vettore, sceltaDimensione);
                free(vettore);
                break;

            case INSERTION_SORT: operazioniInsertion(vettore, sceltaDimensione);
                free(vettore);
                break;

            case MERGE_SORT: operazioniMerge(vettore, sceltaDimensione);
                free(vettore);
                break;

            case HEAP_SORT: operazioniHeap(vettore, sceltaDimensione);
                free(vettore);
                break;

            case QUICK_SORT: operazioniQuick(vettore, sceltaDimensione);
                free(vettore);
                break;
        }

        printf("\nVuoi effettuare altre operazioni?");
        printf("\nYES(1)\tNO(0)");
        scanf("%d", &sceltaMenu);
    }while (sceltaMenu != 0);
}


