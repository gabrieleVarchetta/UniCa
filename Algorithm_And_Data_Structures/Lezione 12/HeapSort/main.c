#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef enum{ORDINATO, QUASI_ORDINATO, INV_ORDINATO, CASUALE} inputType;
int *genera_array(int dimensione, inputType tipo_schema);
void heapSort(int *vettore, int n);
void adatta(int *array, int radice, int n);
void swap(int *variabile1, int *variabile2);
void stampaVettore(int *array, int dimensione);
int inserisciDimensione(void);


int main()
{
    int dimensione;
    int *vettore = NULL;
    inputType tipo;
    clock_t start, end;
    double tempo;

    srand(time(NULL));

    dimensione = inserisciDimensione();

    printf("\nInserisci il tipo di schema di ordinamento del vettore.");
    printf("\nORDINATO - 0\nQUASI ORDINATO - 1\nINVERSAMENTE ORDINATO - 2\nCASUALE - 3\n");
    scanf("%d", &tipo);

    vettore = genera_array(dimensione, tipo);

    printf("\nVettore prima dell'ordinamento: ");
    stampaVettore(vettore, dimensione);

    printf("\nVettore dopo l'ordinamento: ");

    start = clock();
    heapSort(vettore, dimensione);
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

    vettore = (int *) malloc((dimensione + 1) * sizeof(int));

    switch (tipo_schema)
    {
        case ORDINATO: for(i = 1; i < dimensione + 1; i++)
                vettore[i] = i;
            break;

        case QUASI_ORDINATO: for(i = 1; i < dimensione + 1; i++)
            {
                if (i >= 1 && i <= ((dimensione/2)-1)) //fino a metà, elementi ordinati
                    vettore[i] = i + 1;
                else if(i >= (dimensione/2) && i <= dimensione) //dalla metà alla fine elementi random
                    vettore[i] = rand() % 101;
            }
            break;

        case INV_ORDINATO: j = dimensione;
            for(i = 1; i < dimensione + 1; i++)
            {
                vettore[i] = j;
                j--;
            }
            break;

        case CASUALE: for(i = 1; i < dimensione + 1; i++)
            {
                vettore[i] = rand() % 101;
            }
            break;

    }

    return vettore;
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
        if (figlio < n && array[figlio] < array[figlio + 1])
            figlio = figlio + 1;

        //confronta la radice e figlio max
        if (temp > array[figlio])
            break; //il padre di figlio sarà nella posizione corretta
        else
        {
            array[figlio / 2] = array[figlio]; //il figlio si sposta verso il padre

            //ripeti sul sottoalbero selezionato
            figlio = 2 * figlio;
        }
    }
    array[figlio / 2] = temp; //copia la radice nella posizione corretta
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

    for(i = 1; i < dimensione + 1; i++)
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

            case 6: dimensione = 500000;
                break;
        }
    }while (scelta > 6);

    return dimensione;
}

