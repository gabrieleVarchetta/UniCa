#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_TITLE 50
#define DIM_GENRE 50
#define DIM_NAME 50

//struttura che rappresenta una SERIE TV
struct tvs
{
    char title[DIM_TITLE];
    char genre[DIM_GENRE];
    int num_episodes;
    struct tvs* prev;
    struct tvs* next;
};

typedef struct tvs TVS;

//struttura che rappresenta una PLAYLIST
struct playlist
{
    char name[DIM_NAME];
    TVS* top;
};

typedef struct playlist PlayList;

//funzioni (gia' definite) per l'acquisizione e per la stampa di una serie tv
TVS* acquireTVSeries(); //acquisisce i dati di UNA serie tv chiedendoli all'utente
void printTVSeries(TVS* t); //stampa i dati relativi ad UNA serie tv (passata tramite puntatore)

//prototipi funzioni STUDENTE
void menu();
void svuotaBuffer();
void insertTVSeries(PlayList* pl, TVS* t);
TVS *findTVSeries(PlayList* pl, char title[]);
PlayList *modifyTVSeries(PlayList* pl, TVS* t);
void deleteTVSeries(PlayList* pl, TVS* t);
void printPlayList(PlayList* pl);
TVS *nextTVSeries(TVS* t);
TVS *prevTVSeries(TVS* t);
void mergePlayList(PlayList* plA, PlayList* plB, PlayList* plC);

int main()
{
    menu();

    return 0;
}
/* ---------------------------------------------
* funzioni da NON modificare
* --------------------------------------------*/
TVS* acquireTVSeries()
{
    TVS* new_s = (TVS*)malloc(sizeof(TVS));
    printf("\nInsert title: ");
    scanf("%[^\n]s", new_s->title);
    svuotaBuffer();

    printf("Insert genre: ");
    scanf("%[^\n]s", new_s->genre);
    svuotaBuffer();

    printf("Insert number of episodes: ");
    scanf("%d", &(new_s->num_episodes));
    svuotaBuffer();

    new_s->prev = NULL;
    new_s->next = NULL;

    return new_s;
}

void printTVSeries(TVS* t)
{
    printf("TITLE    :\t %s \n", t->title);
    printf("GENRE    :\t %s \n", t->genre);
    printf("EPISODES :\t %d \n\n", t->num_episodes);
}

/* ---------------------------------------------
* funzioni STUDENTE
* --------------------------------------------*/
void menu()
{
    //Creazione di una PLAYLIST. Utilizzare e riempire questa playlist
    PlayList p, p1, mergedP;
    TVS *serie, *serieTrovata, *appoggio;
    strcpy(p.name, "My own TV Series");
    p.top = NULL;
    p1.top = NULL;
    mergedP.top = NULL;

    //altre chiamate e istruzioni per testare il funzionamento delle funzioni create

    int scelta, sceltaP;
    char string[DIM_TITLE];

    do
    {
        printf("\n-------------NETFLIX-------------\n");
        printf("\nChe operazione desideri effettuare?\n");
        printf("\n0. Terminare il programma.\n");
        printf("\n1. Inserire una nuova serie tv alla playlist.\n");
        printf("\n2. Modificare una serie tv della playlist.\n");
        printf("\n3. Eliminare una serie tv dalla playlist.\n");
        printf("\n4. Mostrare i dati di una serie tv della playlist.\n");
        printf("\n5. Mostrare tutte le serie tv della playlist.\n");
        printf("\n6. Mostrare la serie tv precedente a quella scelta.\n");
        printf("\n7. Mostrare la serie tv successiva a quella scelta.\n");
        printf("\n8. Unire due playlist diverse in una unica.\n");
        scanf("%d", &scelta);
        getchar();

        switch (scelta)
        {
            case 1:
                    printf("\nSelezionare una delle due playlist in cui inserire la serie\n");
                    printf("1. Playlist numero 1\n2. Playlist numero 2\n");
                    scanf("%d", &sceltaP);
                    getchar();

                    if (sceltaP == 1)
                    {
                        serie = acquireTVSeries();
                        insertTVSeries(&p, serie);
                    }
                    else
                    {
                        serie = acquireTVSeries();
                        insertTVSeries(&p1, serie);
                    }
                break;

            case 2:
                    printf("\nSelezionare una delle due playlist in cui modificare la serie\n");
                    printf("1. Playlist numero 1\n2. Playlist numero 2\n");
                    scanf("%d", &sceltaP);
                    getchar();

                    printf("\nInserire il nome della serie tv da modificare: ");
                    scanf("%[^\n]s", string);
                    svuotaBuffer();

                    if (sceltaP == 1)
                    {
                        serieTrovata = findTVSeries(&p, string);
                        modifyTVSeries(&p,serieTrovata);
                    }
                    else
                    {
                        serieTrovata = findTVSeries(&p1, string);
                        modifyTVSeries(&p1, serieTrovata);
                    }
                break;

            case 3:
                    printf("\nSelezionare una delle due playlist in cui eliminare la serie\n");
                    printf("1. Playlist numero 1\n2. Playlist numero 2\n");
                    scanf("%d", &sceltaP);
                    getchar();

                    printf("\nInserire il nome della serie tv da eliminare: ");
                    scanf("%[^\n]s", string);
                    svuotaBuffer();

                    if (sceltaP == 1)
                    {
                        serieTrovata = findTVSeries(&p, string);
                        deleteTVSeries(&p, serieTrovata);
                    }
                    else
                    {
                        serieTrovata = findTVSeries(&p1, string);
                        deleteTVSeries(&p1, serieTrovata);
                    }
                break;

            case 4:
                    printf("\nSelezionare una delle due playlist in cui cercare la serie\n");
                    printf("1. Playlist numero 1\n2. Playlist numero 2\n");
                    scanf("%d", &sceltaP);
                    getchar();

                    printf("\nInserire il nome della serie tv di cui mostrare i dati: ");
                    scanf("%[^\n]s", string);
                    svuotaBuffer();

                    if (sceltaP == 1)
                    {
                        serieTrovata = findTVSeries(&p, string);
                        printTVSeries(serieTrovata);
                    }
                    else
                    {
                        serieTrovata = findTVSeries(&p1, string);
                        printTVSeries(serieTrovata);
                    }
                break;

            case 5:
                    printf("\nSelezionare una delle due playlist da visualizzare\n");
                    printf("1. Playlist numero 1\n2. Playlist numero 2\n");
                    scanf("%d", &sceltaP);

                    printf("\nEcco tutte le serie tv presenti nella playlist\n");

                    if (sceltaP == 1)
                        printPlayList(&p);
                    else
                        printPlayList(&p1);
                break;

            case 6:
                    printf("\nSelezionare una delle due playlist in cui cercare la serie precedente\n");
                    printf("1. Playlist numero 1\n2. Playlist numero 2\n");
                    scanf("%d", &sceltaP);
                    getchar();

                    printf("\nInserire il nome della serie tv che si sta guardando: ");
                    scanf("%[^\n]s", string);
                    svuotaBuffer();

                    if (sceltaP == 1)
                    {
                        serieTrovata = findTVSeries(&p, string);
                        printf("\nQuesta e' la serie tv che si sta guardando\n");
                        printTVSeries(serieTrovata);
                        printf("\nQuesta e' la serie tv precedente a quella scelta\n");
                        appoggio = prevTVSeries(serieTrovata);
                        printTVSeries(appoggio);
                    }
                    else
                    {
                        serieTrovata = findTVSeries(&p1, string);
                        printf("\nQuesta e' la serie tv che si sta guardando\n");
                        printTVSeries(serieTrovata);
                        printf("\nQuesta e' la serie tv precedente a quella scelta\n");
                        appoggio = prevTVSeries(serieTrovata);
                        printTVSeries(appoggio);
                    }

                break;

            case 7:
                    printf("\nSelezionare una delle due playlist in cui cercare la serie successsiva\n");
                    printf("1. Playlist numero 1\n2. Playlist numero 2\n");
                    scanf("%d", &sceltaP);
                    getchar();

                    printf("\nInserire il nome della serie tv che si sta guardando: ");
                    scanf("%[^\n]s", string);
                    svuotaBuffer();

                    if (sceltaP == 1)
                    {
                        serieTrovata = findTVSeries(&p, string);
                        printf("\nQuesta e' la serie tv che si sta guardando\n");
                        printTVSeries(serieTrovata);
                        printf("\nQuesta e' la serie tv successiva a quella scelta\n");
                        appoggio = nextTVSeries(serieTrovata);
                        printTVSeries(appoggio);
                    }
                    else
                    {
                        serieTrovata = findTVSeries(&p1, string);
                        printf("\nQuesta e' la serie tv che si sta guardando\n");
                        printTVSeries(serieTrovata);
                        printf("\nQuesta e' la serie tv successiva a quella scelta\n");
                        appoggio = nextTVSeries(serieTrovata);
                        printTVSeries(appoggio);
                    }

                break;

            case 8: printf("\nPlaylist numero 1\n");
                    printPlayList(&p);

                    printf("\nPlaylist numero 2\n");
                    printPlayList(&p1);

                    mergePlayList(&p, &p1, &mergedP);
                    printf("\nQuesta e' la fusione delle due playlist\n");
                    printPlayList(&mergedP);
                break;
        }
    }while (scelta != 0);
}

void svuotaBuffer() {
    char c;

    do {
        c = getchar();
    } while (c != '\n');
}
/**
 * inserisce una serie tv (creata con la funzione acquire) nella lista in maniera ordinata
 * @param pl indirizzo della playlist in cui inserire la serie tv
 * @param t indirizzo della serie tv da inserire nella playlist
 */
void insertTVSeries(PlayList* pl, TVS* t)
{
    //due puntatori di appoggio
    TVS *temp_prev;
    TVS *temp_next;

    if (pl->top == NULL)
        pl->top = t;
    else
    {
        //ricerca della posizione in cui inserire la serie tv
        temp_prev = NULL;
        temp_next = pl->top;
        while (temp_next != NULL && strcmp(temp_next->title, t->title) <= 0)
        {
            temp_prev = temp_next;
            temp_next = temp_next->next;
        }
        //dopo il ciclo conosciamo la posizione in cui inserire il nodo

        //inserimento in coda
        if (temp_next == NULL)
        {
            t->next = NULL;
            t->prev = temp_prev;
            temp_prev->next = t;
        }
        //inserimento in testa
        else if (temp_prev == NULL)
        {
            t->next = temp_next;
            t->prev = NULL;
            pl->top = t;
            temp_next->prev = t;
        }
        //inserimento in mezzo
        else
        {
            t->next = temp_next;
            t->prev = temp_prev;
            temp_next->prev = t;
            temp_prev->next = t;
        }
    }
}

/**
 * cerca una serie tv nella lista (tramite il titolo) e restituisce il suo puntatore
 * @param pl playlist in cui cercare la serie tv
 * @param title nome della serie tv
 * @return puntatore alla serie tv
 */
TVS *findTVSeries(PlayList* pl, char title[])
{
    TVS *temp = pl->top;

    if (temp == NULL)
        printf("\nLa playlist non contiene nessuna serie.");
    else
    {
        //ciclo che si interrompe se si arriva alla fine della lista oppure quando i titoli
        //del nodo in cui ci troviamo e il titolo cercato sono uguali
        while (temp != NULL && strcmp(temp->title, title) != 0)
            temp = temp->next;

        if (temp == NULL)
            printf("\nSerie TV non trovata.");
    }
    return temp;
}

/**
 * modifica una serie tv gia’presente (trovata tramite la funzione find) e la riposiziona nella posizione corretta
 * @param pl
 * @param t
 */
PlayList *modifyTVSeries(PlayList *pl, TVS *t) {
    TVS *temp = (TVS *) malloc(sizeof(TVS));
    int sceltaOperazione, appoggioEpisodi;
    char appoggioTitolo[DIM_TITLE], appoggioGenere[DIM_GENRE];

    if (pl->top == NULL)
        printf("\nLa playlist non contiene nessuna serie tv.");
    else {
        printf("\nQuesta e' la serie tv scelta\n");
        printTVSeries(t);

        printf("\nQuale campo della serie tv vuoi modificare?\n1. Titolo\n2. Genere\n3. Episodi\n");
        scanf("%d", &sceltaOperazione);
        getchar();

        switch (sceltaOperazione)
        {
            case 1:
                //se si modifica il titolo, tramite un nodo di appoggio effettuo la copia del nodo da modificare
                //nel nodo temporaneo, successivamente inserisco in una stringa il nuovo titolo e lo si copia
                //nel nodo di appoggio. Infine si elimina il nodo scelto per la modifica e si inserisce il
                //nodo di appoggio, così che venga inserito in ordine. Inoltre si restituisce l'indirizzo della
                //playlist con gli elementi aggiornati.
                *temp = *t;
                printf("\nInserisci il nuovo titolo della serie: ");
                scanf("%[^\n]s", appoggioTitolo);
                svuotaBuffer();

                strcpy(temp->title, appoggioTitolo);

                deleteTVSeries(pl, t);
                insertTVSeries(pl, temp);
                return pl;

            //se si modifica un campo diverso dal titolo, sarà sufficiente copiare il nuovo valore di
            //numero episodi/genere all'interno del nodo da modificare. Non è necessario eliminare e
            //reinserire il nodo in quanto vengono ordinati nella lista solo in base al titolo.
            case 2:
                printf("\nInserisci il nuovo genere della serie: ");
                scanf("%[^\n]s", appoggioGenere);
                svuotaBuffer();

                strcpy(t->genre, appoggioGenere);
                break;

            case 3:
                printf("\nInserisci il nuovo numero di episodi della serie: ");
                scanf("%d", &appoggioEpisodi);

                t->num_episodes = appoggioEpisodi;
                break;
        }
    }
    free(temp);
    return pl;
}

/**
 * elimina una serie tv già presente (trovata tramite la funzione find) e dealloca l’elemento
 * @param pl
 * @param t
 */
    void deleteTVSeries(PlayList *pl, TVS *t)
    {
        TVS *prev = t->prev, *next = t->next;
        if (pl->top == NULL)
            printf("\nLa playlist non contiene nessuna serie tv.");
        else
        {
            //eliminazione quando è presente solo un elemento nella lista
            if (t->prev == NULL && t->next == NULL)
            {
                pl->top = NULL;
                free(t);
            }
            //eliminazione in coda
            else if (t->next == NULL)
            {
                t->prev->next = NULL;
                free(t);
            }
            //eliminazione in testa
            else if (t->prev == NULL)
            {
                pl->top = t->next;
                t->next->prev = NULL;
                free(t);
            }
            //eliminazione in mezzo
            else
            {
                prev->next = t->next;
                next->prev = prev->next;

                t->prev = NULL;
                t->next = NULL;
                free(t);
            }
        }
    }

/**
 * stampa l’intera playlist di serie tv (usando la funzione di stampa singola)
 * @param pl playlist da stampare
 */
    void printPlayList(PlayList *pl) {
        int i = 1;
        TVS *temp = pl->top;

        if (pl->top == NULL)
            printf("\nLa playlist non contiene nessuna serie tv.\n");
        else {
            printf("\n");
            do {
                printf("\nSerie tv numero %d\n", i);
                i++;
                printTVSeries(temp);
                temp = temp->next;
            } while (temp != NULL);
        }
    }

    TVS *nextTVSeries(TVS *t)
    {
        if (t->next == NULL)
            return NULL;
        else
            return t->next;
    }

    TVS *prevTVSeries(TVS *t)
    {
        if (t->prev == NULL)
            return NULL;
        else
            return t->prev;
    }

/**
 * procedura che unisce due playlist in una terza unica playlist
 * @param plA prima playlist
 * @param plB seconda playlist
 * @param plC playlist vuota in cui unire le prime due
 */
void mergePlayList(PlayList* plA, PlayList* plB, PlayList* plC)
{
    TVS *t = NULL;

    while (plA->top != NULL || plB->top != NULL)
    {
        if (plA->top != NULL && plB->top != NULL)
        {
            if (strcmp(plA->top->title, plB->top->title) < 0)
            {
                t = plA->top;
                plA->top = plA->top->next;
            }
            else
            {
                t = plB->top;
                plB->top = plB->top->next;
            }
            t->next = NULL;
            t->prev = NULL;
            insertTVSeries(plC, t);
        }
        else
        {
            if (plA->top != NULL)
            {
                t = plA->top;
                plA->top = plA->top->next;
            }
            else
            {
                t = plB->top;
                plB->top = plB->top->next;
            }
            t->next = NULL;
            t->prev = NULL;
            insertTVSeries(plC, t);
        }
    }
}



