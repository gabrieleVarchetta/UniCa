#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMC 15 // Numero di colonne della matrice
#define NUMR 10 // Numero di righe della matrice

typedef struct
{
    int riga;
    int colonna;
    int valore;
} Triple;

int appoggio; //variabile di appoggio per la ricerca del numero nella matrice sparsa
int numUsedIntegerSparse = 0; //variabile da usare per contare il numero di interi nella matrice tradizionale
int numUsedIntegerClassic = 0; //variabile da usare per contare il numero di interi nella matrice sparsa

Triple* riempiMatriceSparsa(Triple *matrice);
void stampaMatriceSparsa(Triple *matrice);
bool ricercaNumeroMatriceSparsa(Triple *matrice);
void trasposizioneRapida(Triple *matrice, Triple *matriceTrasposta);

void fill_classic_matrix(int matrix[][NUMC], int numr, int numc);
void print_classic_matrix(int matrix[][NUMC], int numr, int numc);
void search_element_in_classic_matrix(int matrix[][NUMC], int numr, int numc, int numric);

int main()
{
    int matrix[NUMR][NUMC] = {{0}};
    int numric = 71;     // assegnare a numric il numero da cercare.
    Triple *matrice = (Triple *) malloc(sizeof(Triple)), *matriceTrasposta;

    // INIZIO TEST MATRICE CLASSICA
    fill_classic_matrix(matrix, NUMR, NUMC);
    printf("\n");
    print_classic_matrix(matrix, NUMR, NUMC);
    printf("\nLocazioni intere usate per rappresentare una matrice nella forma classica: %d", numUsedIntegerClassic);
    search_element_in_classic_matrix(matrix, NUMR, NUMC, numric);
    // FINE TEST MATRICE CLASSICA

    // INIZIO TEST MATRICE SPARSA
    matrice = riempiMatriceSparsa(matrice);

    stampaMatriceSparsa(matrice);

    printf("\nLocazioni intere usate per rappresentare una matrice nella forma sparsa: %d", numUsedIntegerSparse);

    if(ricercaNumeroMatriceSparsa(matrice) == true)
        printf("\nIl numero ricercato si trova in riga %d e in colonna %d.", matrice[appoggio].riga, matrice[appoggio].colonna);
    else
        printf("\nIl numero ricercato non e' presente all'interno della matrice.");

    matriceTrasposta = (Triple*) malloc((matrice[0].valore + 1) * sizeof(Triple));

    trasposizioneRapida(matrice, matriceTrasposta);
    // FINE TEST MATRICE SPARSA

    return 0;
}

/**
 * Funzione per la creazione di una matrice sparsa. Consente all'utente di inserire il numero di righe, colonne
 * e elementi non nulli della matrice.
 * @param matrice vettore di triple
 * @return puntatore alla matrice sparsa
 */
Triple* riempiMatriceSparsa(Triple *matrice)
{
    int i, dimensione;

    /*Nella posizione 0 del vettore, registra il numero di righe, colonne e valori non nulli della matrice sparsa*/
    printf("\nInserisci il numero di valori non nulli: ");
    scanf("%d", &matrice[0].valore);
    numUsedIntegerSparse++; //conteggio locazioni intere utilizzate

    printf("\nInserisci il numero di righe: ");
    scanf("%d", &matrice[0].riga);
    numUsedIntegerSparse++; //conteggio locazioni intere utilizzate

    printf("\nInserisci il numero di colonne: ");
    scanf("%d", &matrice[0].colonna);
    numUsedIntegerSparse++; //conteggio locazioni intere utilizzate

    matrice = (Triple *) realloc(matrice, (matrice[0].valore + 1) * sizeof(Triple));

    dimensione = matrice[0].valore;

    /*Inserimento dei valori nelle posizioni non nulle, saltando quindi il primo elemento contenente il numero di
     * righe, colonne e valori non nulli*/
    for(i = 1; i <= dimensione; i++)
    {
        printf("\nInserisci la riga in cui si trova il valore numero %d: ", i);
        scanf("%d", &matrice[i].riga);
        numUsedIntegerSparse++; //conteggio locazioni intere utilizzate

        printf("\nInserisci la colonna in cui si trova il valore numero %d: ", i);
        scanf("%d", &matrice[i].colonna);
        numUsedIntegerSparse++; //conteggio locazioni intere utilizzate

        printf("\nInserisci il valore dell'elemento numero %d: ", i);
        scanf("%d", &matrice[i].valore);
        numUsedIntegerSparse++; //conteggio locazioni intere utilizzate
    }

    return matrice;
}

void stampaMatriceSparsa(Triple *matrice)
{
    int i, j, k = 1, nRighe = matrice[0].riga, nColonne = matrice[0].colonna, dimensione = matrice[0].valore;

    /*Stampa del vettore di triple*/
    for (i = 0; i <= dimensione; i++)
    {
        printf("\n<%d\t%d\t%d>",matrice[i].riga, matrice[i].colonna, matrice[i].valore);
    }

    printf("\n\n");

    /*Stampa della matrice sparsa identica alla matrice classica*/
    for(i = 0; i < nRighe; i++) //ciclo per scorrere le righe della matrice sparsa
    {
        /*se il numero della riga contenuta nel vettore di triple, è diverso dal numero della riga in cui ci si
         * trova attualmente, vuol dire che per tutta la riga saranno presenti valori nulli, quindi stampa 0*/
        if (matrice[k].riga != i)
        {
            for(j = 0; j < nColonne; j++) //ciclo per scorrere le colonne della matrice sparsa
            {
                printf("0\t");
            }
            printf("\n");
        }
        else
        {
            for(j = 0; j < nColonne; j++) //ciclo che scorre le colonne per trovare il valore non nullo della riga
            {
                /*se il numero della colonna contenuto nel vettore di triple, è diverso dal numero della colonna
                 * in cui ci si trova attualmente, vuol dire che in quella colonna è presente un valore nullo,
                 * quindi stampa 0*/
                if (matrice[k].colonna != j)
                    printf("0\t");
                else
                {
                    printf("%d\t", matrice[k].valore); //stampa il valore contenuto nel vettore di triple
                }
            }
            printf("\n");
            k++; //incremento il contatore per passare alla tripla successiva
        }
    }
}

/**
 * Funzione per la ricerca di un valore nella matrice sparsa
 * @param matrice vettore di triple
 * @return valore booleano per indicare la presenza o meno del valore nella matrice
 */
bool ricercaNumeroMatriceSparsa(Triple *matrice)
{
    int numeroCercato, i = 1;
    bool flag = false;

    printf("\nInserisci il numero da cercare nella matrice sparsa: ");
    scanf("%d", &numeroCercato);

    //finchè i è <= della dimensione, controlla se il valore della tripla è uguale al valore inserito
   do
   {
       if (matrice[i].valore == numeroCercato) //se sono uguali, restituisci true
       {
           appoggio = i; //salvo la posizione in cui si trova il valore in una variabile globale
           return true;
       }

       i++;
   }while (i <= matrice[0].valore);

    return flag; //se non trova l'elemento, restituisci il flag che è inizializzato a false
}

/**
 * Procedura per la trasposizione rapida di una matrice sparsa
 * @param matrice matrice sparsa di partenza
 * @param matriceTrasposta matrice sparsa dopo la trasposizione
 */
void trasposizioneRapida(Triple *matrice, Triple *matriceTrasposta)
{
    int nColonne = matrice[0].colonna, nValori = matrice[0].valore;
    /*dichiarazione e allocazione dinamica dello spazio per i vettori terminiRiga e posIniziale*/
    int *terminiRiga = (int*) malloc(nColonne * sizeof(int)), *posizioneIniziale = (int*) malloc(nColonne * sizeof(int));
    int i, curPosizione;

    /*nelle righe della trasposta, salvo il numero di colonne della matrice di partenza
     * nelle colonne della trasposta, salvo il numero di righe della matrice di partenza
     * nell'elemento che contiene il numero di valori non nulli, salvo il numero di elementi non nulli della matrice
     * di partenza*/
    matriceTrasposta[0].riga = nColonne;
    matriceTrasposta[0].colonna = matrice[0].riga;
    matriceTrasposta[0].valore = nValori;


    if (nValori > 0)
    {
        /*creazione vettore terminiRiga*/
        for(i = 0; i <= nColonne - 1; i++)
            terminiRiga[i] = 0;

        for(i = 1; i <= nValori; i++)
            terminiRiga[matrice[i].colonna] = terminiRiga[matrice[i].colonna] + 1;

        /*creazione vettore posIniziale*/
        posizioneIniziale[0] = 1;
        for(i = 1; i <= nColonne - 1; i++)
            posizioneIniziale[i] = posizioneIniziale[i - 1] + terminiRiga[i - 1];

        /*trasposizione*/
        for(i = 1; i <= nValori; i++)
        {
            curPosizione = posizioneIniziale[matrice[i].colonna];
            posizioneIniziale[matrice[i].colonna] = posizioneIniziale[matrice[i].colonna] + 1;
            matriceTrasposta[curPosizione].riga = matrice[i].colonna;
            matriceTrasposta[curPosizione].colonna = matrice[i].riga;
            matriceTrasposta[curPosizione].valore = matrice[i].valore;
        }
    }

    printf("\nMatrice sparsa iniziale: \n");
    for (i = 0; i <= matrice[0].valore; i++)
    {
        printf("\n<%d\t%d\t%d>",matrice[i].riga, matrice[i].colonna, matrice[i].valore);
    }

    printf("\n");

    printf("\nMatrice sparsa trasposta: \n");
    for (i = 0; i <= matriceTrasposta[0].valore; i++)
    {
        printf("\n<%d\t%d\t%d>",matriceTrasposta[i].riga, matriceTrasposta[i].colonna, matriceTrasposta[i].valore);
    }
}

// Funzione che riempie (con i valori dell'esempio presenti nelle slide della lezione 3) la matrice classica passata in ingresso
void fill_classic_matrix(int matrix[][NUMC], int numr, int numc)
{
    matrix[1][0] = 71;
    matrix[2][14] = 99;
    matrix[3][11] = 53;
    matrix[4][7] = 95;
    matrix[6][14] = 39;
    matrix[8][1] = 27;
    matrix[9][14] = 14;
}

// Funzione che stampa a video una matrice classica
void print_classic_matrix(int matrix[][NUMC], int numr, int numc)
{
    int i, j = 0;
    for(i=0; i<numr; i++)
    {
        for(j=0; j<numc; j++)
        {
            printf("%d\t", matrix[i][j]);
            numUsedIntegerClassic++;
        }
        printf("\n");
    }

}

// Funzione che implementa la ricerca di un elemento (numric) in una matrice classica
void search_element_in_classic_matrix(int matrix[][NUMC], int numr, int numc, int numric)
{
    int i, j = 0;
    for(i=0; i<numr; i++)
    {
        for(j=0; j<numc; j++)
        {
            if(matrix[i][j] == numric)
            {
                printf("\nElemento %d trovato in posizione (%d, %d).\n", numric, i, j);
                return;
            }
        }
    }
    printf("Elemento non trovato.\n");
}
