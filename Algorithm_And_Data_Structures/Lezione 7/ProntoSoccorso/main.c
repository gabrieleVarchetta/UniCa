#include <stdio.h>
#include <stdlib.h>

#define DIM_NOME 50
#define DIM_HEAP 50

//stuttura che rappresenta un Pronto soccorso
typedef struct
{
    int numeroB;
    int numeroG;
    int numeroV;
    int numeroR;
} ProntoSoccorso;

//enumerazione che rappresenta i codici del pronto soccorso
typedef enum {BIANCO, VERDE, GIALLO, ROSSO} Codice;

//struttura che rappresenta un Paziente
typedef struct
{
    char nome[DIM_NOME];
    Codice codice;
    int ordine;
}Paziente;


/*funzione che chiede i dati relativi ad un nuovo paziente e lo restituisce (con il campo ordine calcolato automaticamente),
pronto per essere inserito nella coda con priorita' (heap) */
Paziente nuovoPaziente(ProntoSoccorso *ps);
/*
 * procedura per avviare il menù
 */
void menu();

void insertHeap(Paziente *heap, Paziente item, int *n);
Paziente deleteHeap(Paziente *heap, int *n);
void printHeap(Paziente *heap, int nElementi);
int priority(Paziente p1, Paziente p2);


int main()
{
    menu();

    return 0;
}

Paziente nuovoPaziente(ProntoSoccorso *ps)
{
    Paziente p;

    printf("\nNome paziente -> ");
    scanf("%[^\n]s", p.nome);
    getchar();

    do
    {
        printf("\nCodice paziente (0 = bianco, 1 = verde, 2 = giallo, 3 = rosso)-> ");
        scanf("%u", &p.codice);
        getchar();

        if(p.codice < BIANCO || p.codice > ROSSO)
            printf("\nCodice non valido");
    }while(p.codice < BIANCO || p.codice > ROSSO);

    if(p.codice == BIANCO)
    {
        ps->numeroB++;
        p.ordine = ps->numeroB;
    }
    else if(p.codice == GIALLO)
    {
        ps->numeroG++;
        p.ordine = ps->numeroG;

    }
    else if (p.codice == VERDE)
    {
        ps->numeroV++;
        p.ordine = ps->numeroV;
    }
    else
    {
        ps->numeroR++;
        p.ordine = ps->numeroR;
    }

    return p;
}

void menu()
{
    //inizializzazione pronto soccorso
    ProntoSoccorso ps;
    ps.numeroB = ps.numeroG = ps.numeroV = ps.numeroR = 0;

    //inizializzazione della Coda con priorita'
    Paziente codaPrio[DIM_HEAP], item;
    int dim_coda = 0, scelta;

    do
    {
        printf("\nInserisci l'operazione da effettuare\n");
        printf("1. Inserire un nuovo paziente nella coda di priorita'.\n");
        printf("2. Eliminare paziente dalla coda di priorita'.\n");
        printf("3. Stampare la coda di priorita'.\n");
        printf("0. Terminare il programma.\n");
        scanf("%d", &scelta);

        switch (scelta)
        {
            case 1:
                getchar();
                item = nuovoPaziente(&ps);
                insertHeap(codaPrio, item, &dim_coda);
                printf("\nPaziente inserito alla coda.");
                break;

            case 2:
                deleteHeap(codaPrio, &dim_coda);
                printf("\nPaziente con priorita' massima eliminato.");
                break;

            case 3:
                printf("\nStampo la coda dei pazienti (nPazienti %d)\n", dim_coda);
                printHeap(codaPrio, dim_coda);
        }
    }while (scelta != 0);
}

void insertHeap(Paziente *heap, Paziente item, int *n)
{
    int i;

    if (*n == DIM_HEAP - 1)
    {
        printf("\nL'heap e' pieno.");
        return;
    }

    (*n)++;
    i = *n;

    while (i != 1 && priority(item, heap[i/2]) == 1)
    {
        heap[i] = heap[i/2];
        i = i/2;
    }

    heap[i] = item;
}

Paziente deleteHeap(Paziente *heap, int *n)
{
    Paziente item, temp;
    int padre, figlio;

    item = heap[1];
    temp = heap[*n];
    (*n)--;
    padre = 1;
    figlio = 2;

    while (figlio <= *n)
    {
        if (figlio < *n && priority(heap[figlio], heap[figlio + 1]) == 2)
            figlio++;
        if (priority(temp, heap[figlio]) == 1)
            break;

        heap[padre] = heap[figlio];
        padre = figlio;
        figlio = 2 * figlio;
    }

    heap[padre] = temp;
    return item;
}

int priority(Paziente p1, Paziente p2)
{
    if (p1.codice == p2.codice)
    {
        if (p1.ordine < p2.ordine)
            return 1;
        else
            return 2;
    }
    else if (p1.codice > p2.codice)
        return 1;
    else
        return 2;
}

void printHeap(Paziente *heap, int nElementi)
{
    int i;

    for(i = 1; i <= nElementi; i++)
    {
        printf("\nElemento numero %d", i);
        printf("\nNome paziente: %s", heap[i].nome);
        printf("\nCodice paziente: %d", heap[i].codice);
        printf("\nOrdine arrivo paziente: %d", heap[i].ordine);
        printf("\n\n");
    }
}