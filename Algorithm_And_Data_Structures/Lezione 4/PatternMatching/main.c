#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define DIM 1000

int *insuccesso(char *pattern);
int knuthMorrisPratt(char *stringa, char *pattern);
bool knuthMorrisPrattRotazioniCicliche(char *stringa, char *pattern);

int main()
{
    char stringa[DIM + 1], pat [DIM + 1];

    printf("\nInserisci una stringa: ");
    scanf("%[^\n]s", stringa);
    getchar();

    printf("\nInserisci un pattern da cercare all'interno della stringa: ");
    scanf("%[^\n]s", pat);
    getchar();

    if (knuthMorrisPratt(stringa, pat) < 0)
        printf("\nNessuna corrispondenza trovata.");
    else
        printf("\nIl match inizia in posizione %d.", knuthMorrisPratt(stringa, pat));


    if (knuthMorrisPrattRotazioniCicliche(stringa, pat) == false)
        printf("\nLa seconda stringa non e' una rotazione ciclica della prima.");
    else
        printf("\nLa seconda stringa e' una rotazione ciclica della prima.");

    return 0;
}

/**
 * funzione che dato un pattern di caratteri in input, lo analizza e crea un vettore di interi chiamato insuccesso,
 * come ausilio per la funzione KMP per il pattern matching. Il pattern viene analizzato a partire dalla prima
 * posizione, e ogni volta che va avanti aggiunge il carattere successivo all'analisi. Quando viene trovato un
 * carattere che è un prefisso ma non un suffisso, nel vettore viene memorizzato il valore -1, altrimenti se il
 * prefisso è anche un suffisso, viene memorizzato inizialmente 0, se subito dopo si trova un prefisso che è anche
 * suffisso ma più lungo, viene memorizzato un valore incrementato di 1.
 * @param pattern stringa(pattern)
 * @return puntatore al vettore insuccesso
 */
int *insuccesso(char *pattern)
{
    int lunghezzaPattern, *arrayInsuccesso = NULL, i, j;

    lunghezzaPattern = strlen(pattern); //lunghezza del pattern
    arrayInsuccesso = (int*) malloc(lunghezzaPattern * sizeof(int));

    arrayInsuccesso[0] = -1; //nella prima posizione il valore sarà -1, essendoci solo un carattere

    //analisi dei prefissi
    for(j = 1; j <= lunghezzaPattern - 1; j++) //si ripete finchè j non arriva alla lunghezza del pattern - 1
    {
        i = arrayInsuccesso[j - 1]; //la i prende il valore dell'array identificato dall'indice precedente a j
        while (pattern[j] != pattern[i + 1] && i >= 0)
            i = arrayInsuccesso[i];

        if (pattern[j] == pattern[i + 1])
            arrayInsuccesso[j] = i + 1;
        else
            arrayInsuccesso[j] = -1;
    }

    return arrayInsuccesso;
}

/**
 * funzione che effettua la ricerca di un pattern all'interno di una stringa inserita dall'utente, in maniera
 * ottimale ed evitando controlli inutili, effettuando qualche controllo, avendo alla fine una complessità O(m+n).
 * Utilizza la funzione insuccesso come supporto, viene utilizzato per capire da quale cella ricominciare il
 * confronto dopo un mismatch. Viene utilizzato l'indice i per la stringa e l'indice j per il pattern, se gli
 * elementi nelle celle i e j sono uguali, incrementa entrambi i contatori di 1 per passare al carattere successivo,
 * altrimenti se sono diversi ma j è 0, incrementa solo i per passare al carattere successivo della stringa. Se i
 * due contatori sono diversi e j non è 0, j assume il valore di arrayInsuccesso nella posizione precedente di j, a
 * cui viene sommato +1.
 * @param stringa stringa in cui cercare il pattern
 * @param pattern pattern da cercare in stringa
 * @return posizione della stringa in cui inizia il match
 */
int knuthMorrisPratt(char *stringa, char *pattern)
{
    int *arrayInsuccesso = NULL, i = 0, j = 0, lunghezzaStringa, lunghezzaPattern;

    arrayInsuccesso = insuccesso(pattern);
    lunghezzaStringa = strlen(stringa);
    lunghezzaPattern = strlen(pattern);

    while (i < lunghezzaStringa && j < lunghezzaPattern)
    {
        if (stringa[i] == pattern[j])
        {
            i++;
            j++;
        }
        else if (j == 0)
            i++;
        else
            j = arrayInsuccesso[j - 1] + 1;
    }

    if (j == lunghezzaPattern)
        return i - lunghezzaPattern;
    else
        return -1;
}

/**
 * in questa versione modificata del KMP, il funzionamento è praticamente lo stesso, con qualche accorgimento. Il
 * confronto inizia solo se la stringa e il pattern hanno la stessa lunghezza, se hanno la stessa lunghezza inizia
 * il confronto come nel KMP. La differenza principale è che il ciclo viene svolto finchè i è minore del doppio
 * della lunghezza della stringa, così da poter cercare tutte le eventuali rotazioni cicliche. Viene utilizzato
 * un contatore k che quando arriva alla stessa grandezza della stringa, viene riportato a 0 per effettuare di nuovo
 * i confronti a partire dal primo carattere della stringa.
 * @param stringa stringa campione
 * @param pattern stringa che potrebbe essere una rotazione ciclica della prima
 * @return true o false a seconda che la seconda stringa sia o meno una rotazione ciclica della prima
 */
bool knuthMorrisPrattRotazioniCicliche(char *stringa, char *pattern)
{
    int *arrayInsuccesso = NULL, i = 0, j = 0, k = 0, lunghezzaStringa, lunghezzaPattern;

    lunghezzaStringa = strlen(stringa);
    lunghezzaPattern = strlen(pattern);

    if (lunghezzaPattern == lunghezzaStringa)
    {
        arrayInsuccesso = insuccesso(pattern);

        while (i < lunghezzaStringa * 2 && j < lunghezzaPattern)
        {
            if (k == lunghezzaStringa)
                k = 0;

            if (stringa[k] == pattern[j])
            {
                j++;
                k++;
                i++;
            }
            else if (j == 0)
            {
                k++;
                i++;
            }

            else
                j = arrayInsuccesso[j - 1] + 1;
        }

        free(arrayInsuccesso);

        if (j == lunghezzaPattern)
            return true;
    }

    return false;
}
