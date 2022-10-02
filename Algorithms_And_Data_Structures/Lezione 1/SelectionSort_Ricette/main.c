#include <stdio.h>
#include <stdlib.h>
#define DIM_NOME 30
typedef struct
{
    char nome[DIM_NOME + 1];
    double tempo;
    int difficolta;
}Ricetta;

void inserisciRicetta(Ricetta *p, int nElementi);
void selectionSort(Ricetta *array, int dimensione);
int compare(Ricetta r1, Ricetta r2);
void swap(Ricetta *array, int i, int min);
void stampaVettore(Ricetta *array, int dimensione);

int main()
{
    Ricetta *vettoreRicette = NULL;
    int numRicette;

    printf("Quante ricette vuoi inserire? \n");
    scanf("%d", &numRicette);

    vettoreRicette = (Ricetta*) malloc(numRicette * sizeof(Ricetta));

    inserisciRicetta(vettoreRicette, numRicette);
    printf("\nPrima:\n");
    stampaVettore(vettoreRicette, numRicette);

    printf("\nDopo:\n");
    selectionSort(vettoreRicette, numRicette);
    stampaVettore(vettoreRicette, numRicette);

    return 0;
}

void inserisciRicetta(Ricetta *p, int nElementi)
{
    int i;

    for(i = 0; i < nElementi; i++)
    {
        getchar();
        printf("\nInserisci il nome della ricetta: \n");
        gets(p[i].nome);

        printf("\nInserisci il tempo per preparare la ricetta, in minuti: \n");
        scanf("%lf", &p[i].tempo);

        printf("\nInserisci la difficolta' di preparazione della ricetta: \n");
        scanf("%d", &p[i].difficolta);
    }
}

void selectionSort(Ricetta *array, int dimensione)
{
    int i, j, min;
    for(i = 0; i <= dimensione - 2; i++)
    {
        min = i;
        for(j = i + 1; j <= dimensione - 1; j++)
        {
            if (compare(array[j], array[min]) == 0)
            {
                min = j;
            }
        }
        swap(array, i, min);
    }
}

int compare(Ricetta r1, Ricetta r2)
{
    if (r1.tempo < r2.tempo)
        return 0;

    else if (r1.tempo == r2.tempo && r1.difficolta < r2.difficolta)
        return 0;

    else
        return 1;
}

void swap(Ricetta *array, int i, int min)
{
    Ricetta temp;

    temp = array[i];
    array[i] = array[min];
    array[min] = temp;
}

void stampaVettore(Ricetta *array, int dimensione)
{
    int i;

    printf("\n");

    for(i = 0; i < dimensione; i++)
    {
        printf("Nome: %s\n", array[i].nome);
        printf("Tempo: %.2lf\n", array[i].tempo);
        printf("Difficolta': %d\n", array[i].difficolta);
        printf("\n");
    }
}

