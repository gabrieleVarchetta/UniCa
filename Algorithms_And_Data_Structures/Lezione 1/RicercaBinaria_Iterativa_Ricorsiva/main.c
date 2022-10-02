#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

typedef enum{ORDINATO, QUASI_ORDINATO, INV_ORDINATO, CASUALE} inputType;

static int contBI = 0, contBIR = 0; //contatori per i conteggi dei confronti della ricerca lineare, binaria iterativa e ricorsiva

int *genera_array(int dimensione, inputType tipo_schema);
void stampaVettore(int *array, int dimensione);
void selectionSort(int *array, int dimensione);
void swap(int *array, int i, int min);
int ricercaBinariaIter(int *array, int numric, int dim);
int ricBinRic(int *array, int numric, int primo, int ultimo);
void stampaRisultati(int pos, double t, int cont);
int inserisciDimensione(void);

int main()
{
    int dimensione, tipo, valoreCercato, posizioneValoreBI, posizioneValoreBIR, primo, ultimo;
    int *vettore = NULL;
    double tempoBI, tempoBIR;
    clock_t start, end;

    srand(time(NULL));

    dimensione = inserisciDimensione();

    printf("\nInserisci il tipo di schema di ordinamento del vettore. \n");
    printf("\nORDINATO - 0\nQUASI ORDINATO - 1\nINVERSAMENTE ORDINATO - 2\nCASUALE - 3\n");
    scanf("%d", &tipo);

    vettore = genera_array(dimensione, tipo);
    selectionSort(vettore, dimensione);

    printf("\nStampo il vettore ordinato...\n");
    stampaVettore(vettore, dimensione);

    printf("\nInserisci il numero da cercare: \n");
    scanf("%d", &valoreCercato);

    //BLOCCO DI CODICE PER LA RICERCA BINARIA ITERATIVA
    start = clock();
    posizioneValoreBI = ricercaBinariaIter(vettore, valoreCercato, dimensione);
    end = clock();
    tempoBI = ((double) (end - start)) / (CLOCKS_PER_SEC / 1000); //calcolo del tempo di esecuzione

    //BLOCCO DI CODICE PER LA RICERCA BINARIA RICORSIVA
    primo = 0;
    ultimo = dimensione - 1;
    start = clock();
    posizioneValoreBIR = ricBinRic(vettore, valoreCercato, primo, ultimo);
    end = clock();
    tempoBIR = ((double) (end - start)) / (CLOCKS_PER_SEC / 1000); //calcolo del tempo di esecuzione

    stampaRisultati(posizioneValoreBI, tempoBI, contBI);
    stampaRisultati(posizioneValoreBIR, tempoBIR, contBIR);

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

void stampaVettore(int *array, int dimensione)
{
    int i;

    printf("\n");

    for(i = 0; i < dimensione; i++)
    {
        printf("\nElemento n. %d: %d\n", i + 1, array[i]);
    }
}

void selectionSort(int *array, int dimensione)
{
    int i, j, min;
    for(i = 0; i <= dimensione - 2; i++)
    {
        min = i;
        for(j = i + 1; j <= dimensione - 1; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        swap(array, i, min);
    }
}

void swap(int *array, int i, int min)
{
    int temp;

    temp = array[i];
    array[i] = array[min];
    array[min] = temp;
}

int ricercaBinariaIter(int *array, int numric, int dim)
{
    int primo = 0, ultimo = dim - 1, mezzo;

    while (primo <= ultimo)
    {
        contBI++;
        mezzo = (primo + ultimo) / 2;
        if (numric < array[mezzo])
            ultimo = mezzo - 1;
        else if (numric == array[mezzo])
            return mezzo;
        else
            primo = mezzo + 1;
    }

    printf("\nIl numero inserito non e' presente nel vettore.\n");
    exit(-1);
}

int ricBinRic(int *array, int numric, int primo, int ultimo)
{
    int mezzo;

    if (primo > ultimo)
    {
        printf("\nIl numero inserito non e' presente nel vettore.\n");
        exit(-1);
    }

    mezzo = (primo + ultimo) / 2;

    contBIR++;
    if (array[mezzo] == numric)
        return mezzo;

    else if (array[mezzo] < numric)
        return ricBinRic(array, numric, mezzo + 1, ultimo);

    else
        return ricBinRic(array, numric, primo, mezzo - 1);
}

void stampaRisultati(int pos, double t, int cont)
{
    printf("\n");
    printf("Il valore ricercato si trova in posizione %d.", pos + 1);
    printf("\nSono stati effettuati %d confronti.\n", cont);
    printf("Il tempo impiegato per trovare il numero e': %lf millisecondi.\n", t);
}

int inserisciDimensione(void)
{
    bool flag = false;
    int scelta, dimensione;

    do
    {
        printf("\nInserisci la dimensione del vettore. \n");
        printf("\nDimensioni tra cui scegliere: \n");
        printf("1. 10\n2. 50\n3. 100\n4. 1000\n5. 10000\n6. 100000\n7. 500000\n");
        scanf("%d", &scelta);

        switch (scelta)
        {
            case 1: dimensione = 10;
                flag = true;
                break;

            case 2: dimensione = 50;
                flag = true;
                break;

            case 3: dimensione = 100;
                flag = true;
                break;

            case 4: dimensione = 1000;
                flag = true;
                break;

            case 5: dimensione = 10000;
                flag = true;
                break;

            case 6: dimensione = 100000;
                flag = true;
                break;

            case 7: dimensione = 500000;
                flag = true;
                break;
        }
    }while (flag != true);

    return dimensione;
}