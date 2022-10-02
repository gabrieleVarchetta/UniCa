#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_TARGA 10
#define NUM_PIANI 7

typedef struct
{
    char targa[MAX_TARGA];
    int ora;
    int min;
}Auto;

typedef struct nodo
{
    Auto info;
    struct nodo *link;
}Nodo;

void menu(Nodo *parcheggio[]);
unsigned int hash_function(char targa[]);
Auto acquisisci_auto();
void inserisci_auto(Nodo* parcheggio[], Auto a);
void carica_auto_test(Nodo* parcheggio[]);
void stampa_parcheggio(Nodo* parcheggio[]);
void stampa_piano(Nodo* parcheggio[], int piano);
Nodo* ricerca_auto(Nodo* parcheggio[], char targa[]);
void elimina_auto(Nodo* parcheggio[], char targa[]);

int main()
{
    Nodo* parcheggio[NUM_PIANI];
    int i;

    for(i = 0; i < NUM_PIANI; i++)
        parcheggio[i] = NULL;

    //inserire qui le funzioni per i test
    menu(parcheggio);

    return 0;
}

void menu(Nodo *parcheggio[])
{
    Nodo* foundAuto;
    Auto toInsertAuto;
    char toFindAuto[MAX_TARGA], toDeleteAuto[MAX_TARGA];
    int scelta, pianoScelto;

    do
    {
        printf("\nInserire il numero dell'operazione da effettuare");
        printf("\n1. Inserimento nuova auto nel parcheggio.");
        printf("\n2. Visualizzare tutte le auto in un piano.");
        printf("\n3. Visualizzare tutte le auto nel parcheggio.");
        printf("\n4. Ricerca di un auto nel parcheggio.");
        printf("\n5. Eliminazione di un auto dal parchegigo.");
        printf("\n6. Modalita' test.");
        printf("\n7. Termina programma.\n");
        scanf("%d", &scelta);

        switch (scelta)
        {
            case 1:
                    toInsertAuto = acquisisci_auto();
                    inserisci_auto(parcheggio, toInsertAuto);
                    printf("\nAuto inserita con successo.\n");
                break;

            case 2:
                    printf("\nInserisci il numero del piano da visualizzare (0 - 6): ");
                    scanf("%d", &pianoScelto);

                    stampa_piano(parcheggio, pianoScelto);
                break;

            case 3:
                    printf("\nVisualizzazione di tutte le auto nel parcheggio");
                    stampa_parcheggio(parcheggio);
                break;

            case 4:
                    printf("\nInserisci la targa dell'auto da cercare: ");
                    scanf("%s", toFindAuto);

                    foundAuto = ricerca_auto(parcheggio, toFindAuto);

                    if (foundAuto == NULL)
                        printf("\nL'auto cercata non e' stata trovata.\n");
                    else
                    {
                        printf("\nEcco i dati dell'auto cercata\n");
                        printf("Targa: %s", foundAuto->info.targa);
                        printf("\nOre di permanenza: %d", foundAuto->info.ora);
                        printf("\nMinuti di permanenza: %d", foundAuto->info.min);
                    }
                break;

            case 5:
                    printf("\nInserisci la targa dell'auto da eliminare: ");
                    scanf("%s", toDeleteAuto);

                    elimina_auto(parcheggio, toDeleteAuto);
                    printf("\nAuto eliminata con successo.\n");
                break;

            case 6:
                    carica_auto_test(parcheggio);
                    printf("\nParcheggio di prova caricato con successo.\n");
                break;
        }
    }while (scelta >= 0 && scelta <= 6);

}
void carica_auto_test(Nodo* parcheggio[])
{
    Auto a0 = {"PI555TA", 12, 15};
    Auto a1 = {"CA220TO", 7, 59};
    Auto a2 = {"EG000AL", 19, 45};
    Auto a3 = {"GO000LE", 15, 20};
    Auto a4 = {"BA220TO", 10, 35};
    Auto a5 = {"AP111LE", 15, 20};
    Auto a6 = {"MI123FT", 18, 40};
    Auto a7 = {"NO985LE", 20, 30};
    Auto a8 = {"GI124CH", 11, 20};
    Auto a9 = {"LO199RE", 9, 30};
    Auto a10 = {"ZA156KF", 7, 10};

    inserisci_auto(parcheggio, a0);
    inserisci_auto(parcheggio, a1);
    inserisci_auto(parcheggio, a2);
    inserisci_auto(parcheggio, a3);
    inserisci_auto(parcheggio, a4);
    inserisci_auto(parcheggio, a5);
    inserisci_auto(parcheggio, a6);
    inserisci_auto(parcheggio, a7);
    inserisci_auto(parcheggio, a8);
    inserisci_auto(parcheggio, a9);
    inserisci_auto(parcheggio, a10);
}

unsigned int hash_function(char targa[])
{
    unsigned int value = 0;
    int i;

    for (i = 0; i < strlen(targa); i++)
    {
        value += (unsigned int)'A' - (unsigned int)targa[i];
    }

    return value % NUM_PIANI;
}

Auto acquisisci_auto()
{
    Auto appoggio;

    printf("\nInserisci la targa dell'auto: ");
    scanf("%s", appoggio.targa);

    printf("\nInserisci il numero di ore di permanenza al parcheggio: ");
    scanf("%d", &appoggio.ora);

    printf("\nInserisci il numero di minuti di permanenza al parcheggio: ");
    scanf("%d", &appoggio.min);

    return appoggio;
}

void inserisci_auto(Nodo* parcheggio[], Auto a)
{
    int value;
    Nodo *temp;

    value = hash_function(a.targa);

    if (parcheggio[value] == NULL)
    {
        parcheggio[value] = (Nodo*)malloc(sizeof(Nodo));
        parcheggio[value]->info = a;
        parcheggio[value]->link = NULL;
    }
    else
    {
        temp = parcheggio[value];

        //scorro la lista finché non trovo uno spazio libero
        while (temp->link != NULL)
            temp = temp->link;

        //dopo averlo trovato, alloco la memoria per il top della lista
        temp->link = (Nodo*)malloc(sizeof(Nodo));
        temp = temp->link;

        //inserisco l'elemento in top
        temp->link = NULL;
        temp->info = a;
    }
}

void stampa_parcheggio(Nodo* parcheggio[])
{
    int i, j = 1;

    for (i = 0; i < NUM_PIANI; i++)
    {
        printf("\nPiano numero %d", j);
        stampa_piano(parcheggio, i);
        j++;
        printf("\n");
    }
}
void stampa_piano(Nodo* parcheggio[], int piano)
{
    Nodo *temp = parcheggio[piano];
    int i = 1;

    if (parcheggio[piano] == NULL)
    {
        printf("\nNon e' presente nessuna auto in questo piano.");
        return;
    }
    else
    {
        while (temp != NULL)
        {
            printf("\nTarga auto numero %d: %s", i, temp->info.targa);
            temp = temp->link;
            i++;
        }
    }

}

Nodo* ricerca_auto(Nodo* parcheggio[], char targa[])
{
    int indice = hash_function(targa);

    if(parcheggio[indice]->link == NULL && strcmp(parcheggio[indice]->info.targa, targa) == 0)
        return parcheggio[indice];
    else
    {
        Nodo* appoggio;
        appoggio = parcheggio[indice];

        while(appoggio->link != NULL)
        {
            if(strcmp(appoggio->info.targa, targa) == 0)
                return appoggio;

            appoggio = appoggio->link;
        }
    }
    return NULL;
}

void elimina_auto(Nodo* parcheggio[], char targa[])
{
    Nodo *appoggio;
    Nodo *prev = NULL;

    int indice = hash_function(targa);
    appoggio = parcheggio[indice];//punta al top della lista di collisione

    //se la testa della coda coincide con l'elemento da eliminare
    if (appoggio != NULL && strcmp(appoggio->info.targa, targa) == 0)
    {
        parcheggio[indice] = appoggio->link; //imposto come testa della lista il nodo successivo
        free(appoggio); //libero la memoria del nodo
        return;
    }

    //se non è in testa, cerco la posizione in cui si trova
    while (appoggio != NULL && strcmp(appoggio->info.targa, targa) != 0)
    {
        prev = appoggio; //punta all'elemento precedente della lista di collisione
        appoggio = appoggio->link;
    }

    if (appoggio == NULL)//se dopo la ricerca appoggio è NULL l'auto non è presente nel parcheggio
    {
        printf("\nL'auto da eliminare non e' presente nel parcheggio.");
        return;
    }
    else //altrimenti modifico i collegamenti scollegando dalla lista il nodo da eliminare
        prev->link = appoggio->link;

    free(appoggio); //libero la memoria
}