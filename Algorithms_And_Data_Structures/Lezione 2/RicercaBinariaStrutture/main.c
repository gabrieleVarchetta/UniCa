#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_NOME 100
typedef struct
{
    char nome[DIM_NOME + 1];
    double prezzo_notte;
    int recensione;
} Hotel;

void selectionSort(Hotel *array, int dimensione);
void swap(Hotel *array, int i, int min);
void inserisciHotel(Hotel *p, int nElementi);
Hotel *ricercaBinariaIter(Hotel *array, char *nomeHotel, int dim);
void stampaVettore(Hotel *array, int dimensione);
void stampaRecord(Hotel *p);

int main()
{
    Hotel *vettore = NULL, *hotelTrovato = NULL;
    int nElementi;
    char stringa[DIM_NOME + 1];

    printf("\nQuanti hotel vuoi inserire?\n");
    scanf("%d", &nElementi);

    vettore = (Hotel*) malloc(nElementi * sizeof(Hotel));

    inserisciHotel(vettore, nElementi);
    printf("\nStampo l'elenco di hotel non ordinato: \n");
    stampaVettore(vettore, nElementi);

    selectionSort(vettore, nElementi);

    printf("\nStampo l'elenco di hotel ordinato: \n");
    stampaVettore(vettore, nElementi);

    getchar();
    printf("\nInserisci il nome dell'hotel da cercare: ");
    scanf("%[^\n]s", stringa);

    hotelTrovato = ricercaBinariaIter(vettore, stringa, nElementi);
    printf("\nEcco i dati dell'hotel ricercato: \n");
    stampaRecord(hotelTrovato);
    return 0;
}

void selectionSort(Hotel *array, int dimensione)
{
    int i, j, min;
    for(i = 0; i <= dimensione - 2; i++)
    {
        min = i;
        for(j = i + 1; j <= dimensione - 1; j++)
        {
            if (strcmp(array[min].nome, array[j].nome) > 0)
            {
                min = j;
            }
        }
        swap(array, i, min);
    }
}

void swap(Hotel *array, int i, int min)
{
    Hotel temp;

    temp = array[i];
    array[i] = array[min];
    array[min] = temp;
}

void inserisciHotel(Hotel *p, int nElementi)
{
    int i;

    for(i = 0; i < nElementi; i++)
    {
        getchar();
        printf("\nInserisci il nome dell'hotel: \n");
        scanf("%[^\n]s", p[i].nome);

        printf("\nInserisci il prezzo a notte: \n");
        scanf("%lf", &p[i].prezzo_notte);

        printf("\nInserisci il numero di recensioni: \n");
        scanf("%d", &p[i].recensione);
    }
}

Hotel *ricercaBinariaIter(Hotel *array, char *nomeHotel, int dim)
{
    int primo = 0, ultimo = dim - 1, mezzo;

    while (primo <= ultimo)
    {
        mezzo = (primo + ultimo) / 2;
        if (strcmp(nomeHotel, array[mezzo].nome) < 0)
            ultimo = mezzo - 1;
        else if (strcmp(nomeHotel, array[mezzo].nome) == 0)
            return &array[mezzo];
        else
            primo = mezzo + 1;
    }

    printf("\nIl nome inserito non e' presente nel vettore.\n");
    exit(-1);
}

void stampaVettore(Hotel *array, int dimensione)
{
    int i;

    printf("\n");

    for(i = 0; i < dimensione; i++)
    {
        printf("Nome: %s\n", array[i].nome);
        printf("Prezzo a notte: %.2lf euro\n", array[i].prezzo_notte);
        printf("Recensioni: %d\n", array[i].recensione);
        printf("\n");
    }
}

void stampaRecord(Hotel *p)
{
    printf("\n");

    printf("Nome: %s\n", p->nome);
    printf("Prezzo a notte: %.2lf euro\n", p->prezzo_notte);
    printf("Recensioni: %d\n", p->recensione);
    printf("\n");
}
