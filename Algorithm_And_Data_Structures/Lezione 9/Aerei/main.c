#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VERTICI 20
#define DIM 50
#define NUM_NODI_TEST 11

typedef struct node
{
    int vertex_id;
    struct node* link;
}Node;

typedef struct
{
    char nome[DIM];
    int  abitanti;
    char nazione[DIM];
    Node* lista_adj;
}Citta;

typedef struct
{
    Node* front;
    Node* back;
    int cont;
}Queue;

/* ==============================
 * Funzioni gia' implementate
 * ============================== */
void carica_citta_test(Citta grafo[]);
void carica_grafo_test_orientato(Citta grafo[], int num_nodi);
void carica_grafo_test_non_orientato(Citta grafo[], int num_nodi);


/* ==============================
 * Funzioni da completare
 * ============================== */
void aggiungi_nodo(Citta grafo[], int num_nodi);
void crea_arco(Citta grafo[], int id_coda, int id_testa, int num_nodi);

void stampa_lista_adiacenze(Citta grafo[], int num_nodi);

void DFS(Citta grafo[], int visited[], int start_id);
void BFS(Citta grafo[], int visited[], int start_id);

void cancella_arco_orientato(Citta grafo[], int id_coda, int id_testa, int num_nodi);
void cancella_arco_non_orientato(Citta grafo[], int id_coda, int id_testa, int num_nodi);

void componenti_connesse(Citta grafo[], int visited[], int num_nodi);

void svuotaBuffer();
void menu(Citta grafo[], int num_nodi, int *visited);
bool isEmptyQueue(Queue* coda);
void pushQueue(Queue* coda, int id);
int popQueue(Queue* coda);
void stampaScelte();

int main()
{
    Citta grafo[MAX_VERTICI];
    int num_nodi = 0;
    int *visited = NULL;

    //Inserire qui le chiamate per testare le varie funzioni e il menu
    menu(grafo, num_nodi, visited);

    return 0;
}

void menu(Citta grafo[], int num_nodi, int *visited)
{
    int scelta, coda, testa, sceltaCitta, sceltaCancellazioneArco, sceltaCreazioneArco, sceltaTest;
    printf("\nScegliere l'operazione da effettuare\n");
    do
    {
        stampaScelte();
        scanf("%d", &scelta);

        switch (scelta)
        {
            case 0:
                    getchar();
                    aggiungi_nodo(grafo, num_nodi);
                    num_nodi++;
                break;

            case 1:
                    printf("1. Crea arco orientato.\n");
                    printf("2. Crea arco non orientato.\n");
                    scanf("%d", &sceltaCreazioneArco);

                    switch (sceltaCreazioneArco)
                    {
                        case 1:
                            printf("\nInserire il codice del nodo da cui parte l'arco: ");
                            scanf("%d", &coda);
                            printf("\nInserire il codice del nodo in cui termina l'arco: ");
                            scanf("%d", &testa);
                            crea_arco(grafo, coda, testa, num_nodi);
                            printf("\nArco creato con successo.");
                            break;

                        case 2:
                            printf("\nInserire il codice del nodo da cui parte l'arco: ");
                            scanf("%d", &coda);
                            printf("\nInserire il codice del nodo in cui termina l'arco: ");
                            scanf("%d", &testa);
                            crea_arco(grafo, coda, testa, num_nodi);
                            crea_arco(grafo, testa, coda, num_nodi);
                            printf("\nArco creato con successo.");
                            break;
                    }
                    break;

            case 2:
                    printf("\nVisualizzazione di tutte le rotte aeree tra le citta'\n");
                    stampa_lista_adiacenze(grafo, num_nodi);
                break;

            case 3:
                    printf("\nInserire il codice della citta' da cui cominciare la visita: ");
                    scanf("%d", &sceltaCitta);
                    visited = (int*) calloc(num_nodi, sizeof(int));
                    DFS(grafo, visited, sceltaCitta);
                break;

            case 4:
                    printf("\nInserire il codice della citta' da cui cominciare la visita: ");
                    scanf("%d", &sceltaCitta);
                    visited = (int*) calloc(num_nodi, sizeof(int));
                    BFS(grafo, visited, sceltaCitta);
                break;

            case 5:
                    printf("1. Cancella arco orientato.\n");
                    printf("2. Cancella arco non orientato.\n");
                    scanf("%d", &sceltaCancellazioneArco);

                    switch (sceltaCancellazioneArco)
                    {
                        case 1:
                                printf("\nInserire il codice del nodo da cui parte l'arco: ");
                                scanf("%d", &coda);
                                printf("\nInserire il codice del nodo in cui termina l'arco: ");
                                scanf("%d", &testa);
                                cancella_arco_orientato(grafo, coda, testa, num_nodi);
                            break;

                        case 2:
                                printf("\nInserire il codice del nodo da cui parte l'arco: ");
                                scanf("%d", &coda);
                                printf("\nInserire il codice del nodo in cui termina l'arco: ");
                                scanf("%d", &testa);
                                cancella_arco_non_orientato(grafo, coda, testa, num_nodi);
                            break;
                    }
                break;

            case 6:
                    printf("\nVisualizzazione delle possibili destinazioni\n");
                    visited = (int*) calloc(num_nodi, sizeof(int));
                    componenti_connesse(grafo, visited, num_nodi);
                break;

            case 7:
                    printf("\nInserire la modalita' di test da eseguire");
                    printf("\n1. Carica test con grafo orientato.");
                    printf("\n2. Carica test con grafo non orientato.");
                    scanf("%d", &sceltaTest);

                    switch (sceltaTest)
                    {
                        case 1:
                                num_nodi = NUM_NODI_TEST;
                                carica_grafo_test_orientato(grafo, num_nodi);
                            break;

                        case 2:
                                num_nodi = NUM_NODI_TEST;
                                carica_grafo_test_non_orientato(grafo, num_nodi);
                            break;
                    }
                break;
        }
    }while (scelta != 8);
}

void stampaScelte()
{
    printf("\n0. Inserimento di un nuovo nodo.");
    printf("\n1. Inserimento di un nuovo arco.");
    printf("\n2. Visualizzazione liste di adiacenza del grafo.");
    printf("\n3. Visita in profondita' del grafo a partire da un nodo.");
    printf("\n4. Visita in ampiezza del grafo a partire da un nodo.");
    printf("\n5. Cancellazione di un arco.");
    printf("\n6. Visualizzazione delle componenti connesse.");
    printf("\n7. Modalita' test.");
    printf("\n8. Termina il programma.\n");
}

/**
 * funzione che controlla se una coda è vuota e quindi non ha elementi
 * @param coda indirizzo della coda da controllare
 * @return false se non è vuota, true altrimenti
 */
bool isEmptyQueue(Queue* coda)
{
    if (coda->front == NULL && coda->back == NULL)
        return true;
    else
        return false;
}

/**
 * funzione che controlla se una coda è piena e quindi ha raggiunto la dimensione massima
 * @param coda indirizzo della coda da controllare
 * @return false se non è piena, true altrimenti
 */
bool isFullQueue(Queue* coda)
{
    if (coda->cont == MAX_VERTICI)
        return true;
    else
        return false;
}

/**
 * procedura per l'inserimento di un elemento nella coda
 * @param coda indirizzo della coda in cui inserire l'elemento
 * @param val elemento da inserire
 */
void pushQueue(Queue* coda, int id)
{
    if (isFullQueue(coda))
        printf("\nERRORE OVERFLOW.");
    else
    {
        Node *new_node = (Node*) malloc(sizeof(Node));
        new_node->vertex_id = id;
        new_node->link = NULL;

        if (isEmptyQueue(coda))
        {
            coda->front = new_node;
            coda->back = new_node;
        }
        else
        {
            coda->back->link = new_node;
            coda->back = new_node;
        }
        coda->cont++;
    }
}

/**
 * funzione che elimina un elemento dalla coda e lo restituisce
 * @param coda indirizzo della coda da cui eliminare un elemento
 * @return elemento eliminato
 */
int popQueue(Queue* coda)
{
    int id;

    if (isEmptyQueue(coda))
    {
        printf("\nERRORE UNDERFLOW.");
    }
    else
    {
        Node* temp = coda->front;
        id = temp->vertex_id;

        if (coda->cont == 1)
        {
            coda->front = NULL;
            coda->back = NULL;
        }
        else
            coda->front = coda->front->link;

        coda->cont--;
        free(temp);

    }
    return id;
}

void carica_citta_test(Citta grafo[])
{
    //Cagliari
    strcpy(grafo[0].nome, "Cagliari");
    strcpy(grafo[0].nazione, "Italia");
    grafo[0].abitanti = 300000;
    grafo[0].lista_adj = NULL;

    //Zurigo
    strcpy(grafo[1].nome, "Zurigo");
    strcpy(grafo[1].nazione, "Svizzera");
    grafo[1].abitanti = 400000;
    grafo[1].lista_adj = NULL;

    //Lione
    strcpy(grafo[2].nome, "Lione");
    strcpy(grafo[2].nazione, "Francia");
    grafo[2].abitanti = 500000;
    grafo[2].lista_adj = NULL;

    //Genova
    strcpy(grafo[3].nome, "Genova");
    strcpy(grafo[3].nazione, "Italia");
    grafo[3].abitanti = 800000;
    grafo[3].lista_adj = NULL;

    //Roma
    strcpy(grafo[4].nome, "Roma");
    strcpy(grafo[4].nazione, "Italia");
    grafo[4].abitanti = 4000000;
    grafo[4].lista_adj = NULL;

    //New York
    strcpy(grafo[5].nome, "New York");
    strcpy(grafo[5].nazione, "USA");
    grafo[5].abitanti = 8500000;
    grafo[5].lista_adj = NULL;

    //Bilbao
    strcpy(grafo[6].nome, "Bilbao");
    strcpy(grafo[6].nazione, "Spagna");
    grafo[6].abitanti = 350000;
    grafo[6].lista_adj = NULL;

    //Berlino
    strcpy(grafo[7].nome, "Berlino");
    strcpy(grafo[7].nazione, "Germania");
    grafo[7].abitanti = 3500000;
    grafo[7].lista_adj = NULL;

    //Londra
    strcpy(grafo[8].nome, "Londra");
    strcpy(grafo[8].nazione, "Gran Bretagna");
    grafo[8].abitanti = 8700000;
    grafo[8].lista_adj = NULL;

    //Miami
    strcpy(grafo[9].nome, "Miami");
    strcpy(grafo[9].nazione, "USA");
    grafo[9].abitanti = 450000;
    grafo[9].lista_adj = NULL;

    //Tokyo
    strcpy(grafo[10].nome, "Tokyo");
    strcpy(grafo[10].nazione, "Giappone");
    grafo[10].abitanti = 13700000;
    grafo[10].lista_adj = NULL;
}

void carica_grafo_test_orientato(Citta grafo[], int num_nodi)
{
    carica_citta_test(grafo);

    //Creazione archi
    crea_arco(grafo, 0, 1, num_nodi);
    crea_arco(grafo, 0, 4, num_nodi);

    crea_arco(grafo, 1, 0, num_nodi);
    crea_arco(grafo, 1, 2, num_nodi);

    crea_arco(grafo, 2, 1, num_nodi);
    crea_arco(grafo, 2, 3, num_nodi);

    crea_arco(grafo, 4, 0, num_nodi);
    crea_arco(grafo, 4, 1, num_nodi);
    crea_arco(grafo, 4, 5, num_nodi);
    crea_arco(grafo, 4, 6, num_nodi);

    crea_arco(grafo, 5, 1, num_nodi);

    crea_arco(grafo, 6, 7, num_nodi);

    crea_arco(grafo, 8, 9, num_nodi);

    crea_arco(grafo, 9, 8, num_nodi);
    crea_arco(grafo, 9, 10, num_nodi);
}

void carica_grafo_test_non_orientato(Citta grafo [], int num_nodi)
{
    carica_citta_test(grafo);

    //Creazione archi
    crea_arco(grafo, 0, 1, num_nodi);
    crea_arco(grafo, 1, 0, num_nodi);

    crea_arco(grafo, 0, 4, num_nodi);
    crea_arco(grafo, 4, 0, num_nodi);

    crea_arco(grafo, 1, 2, num_nodi);
    crea_arco(grafo, 2, 1, num_nodi);

    crea_arco(grafo, 2, 3, num_nodi);
    crea_arco(grafo, 3, 2, num_nodi);

    crea_arco(grafo, 4, 1, num_nodi);
    crea_arco(grafo, 1, 4, num_nodi);

    crea_arco(grafo, 4, 5, num_nodi);
    crea_arco(grafo, 5, 4, num_nodi);

    crea_arco(grafo, 4, 6, num_nodi);
    crea_arco(grafo, 6, 4, num_nodi);

    crea_arco(grafo, 5, 1, num_nodi);
    crea_arco(grafo, 1, 5, num_nodi);

    crea_arco(grafo, 6, 7, num_nodi);
    crea_arco(grafo, 7, 6, num_nodi);

    crea_arco(grafo, 8, 9, num_nodi);
    crea_arco(grafo, 9, 8, num_nodi);

    crea_arco(grafo, 9, 10, num_nodi);
    crea_arco(grafo, 10, 9, num_nodi);
}

void aggiungi_nodo(Citta grafo[], int num_nodi)
{
    // inserire qui il codice della funzione...
    printf("\nInserisci il nome della citta': ");
    scanf("%s", grafo[num_nodi].nome);
    svuotaBuffer();

    printf("\nInserisci il numero di abitanti della citta': ");
    scanf("%d", &grafo[num_nodi].abitanti);

    printf("\nInserisci la nazione in cui si trova la citta': ");
    scanf("%s", grafo[num_nodi].nazione);
    svuotaBuffer();

    grafo[num_nodi].lista_adj = NULL;
}

void crea_arco(Citta grafo[], int id_coda, int id_testa, int num_nodi)
{
    // inserire qui il codice della funzione...
    Node *appoggio = grafo[id_coda].lista_adj;
    Node *newNode = NULL;

    if (id_coda < 0 || id_coda > num_nodi || id_testa < 0 || id_testa > num_nodi)
    {
        printf("\nErrore, impossibile creare l'arco.\n");
        return;
    }
    else
    {
        newNode = (Node*) malloc(sizeof(Node));
        newNode->vertex_id = id_testa;
        newNode->link = NULL;

        if (appoggio == NULL)
            grafo[id_coda].lista_adj = newNode;
        else
        {
            while (appoggio->vertex_id < id_testa && appoggio->link != NULL)
                appoggio = appoggio->link;

            appoggio->link = newNode;
        }
    }
}

void stampa_lista_adiacenze(Citta grafo[], int num_nodi)
{
    // inserire qui il codice della funzione...
    int i, j = 1;
    Node *appoggio = NULL;

    for (i = 0; i < num_nodi; i++)
    {
        printf("\nNodo numero %d: %s", i, grafo[i].nome);
        appoggio = grafo[i].lista_adj;

        printf("\nLista di adiacenza del nodo\n");

        while (appoggio != NULL)
        {
            printf("Nodo numero %d: %s\n", j, grafo[appoggio->vertex_id].nome);
            appoggio = appoggio->link;
            j++;
        }
        j = 1;
        printf("\n");
    }
}

void DFS(Citta grafo[], int visited[], int start_id)
{
    // inserire qui il codice della funzione...
    Node *temp = grafo[start_id].lista_adj;
    int id_next;

    printf("%s, ", grafo[start_id].nome);
    visited[start_id] = 1;

    while (temp != NULL)
    {
        id_next = temp->vertex_id;

        if (visited[id_next] == 0)
            DFS(grafo, visited, id_next);

        temp = temp->link;
    }
}

void BFS(Citta grafo[], int visited[], int start_id)
{
    // inserire qui il codice della funzione...
    int i;
    Node *temp = NULL;

    printf("%s", grafo[start_id].nome);
    visited[start_id] = 1;

    //dichiarazione e inizializzazione della Coda
    Queue queue;
    queue.front = NULL;
    queue.back = NULL;
    queue.cont = 0;

    pushQueue(&queue, start_id);

    while (!isEmptyQueue(&queue))
    {
        i = popQueue(&queue);
        temp = grafo[i].lista_adj;

        while (temp != NULL)
        {
            if (visited[temp->vertex_id] == 0)
            {
                pushQueue(&queue, temp->vertex_id);
                printf(", %s", grafo[temp->vertex_id].nome);
                visited[temp->vertex_id] = 1;
            }
            temp = temp->link;
        }
    }
}

void cancella_arco_orientato(Citta grafo[], int id_coda, int id_testa, int num_nodi)
{
    // inserire qui il codice della funzione...
    Node *appoggio = NULL;
    Node *temp = NULL;
    bool flag;

    if (id_coda < 0 || id_coda > num_nodi || id_testa < 0 || id_testa > num_nodi)
    {
        printf("\nErrore, impossibile eliminare l'arco.\n");
        return;
    }
    else
    {
        appoggio = grafo[id_coda].lista_adj;

        if (appoggio == NULL)
        {
            printf("\nIl nodo e' isolato e non ha nessun arco da eliminare.");
            return;
        }
        else
        {
            if (appoggio->vertex_id == id_testa)
                grafo[id_coda].lista_adj = appoggio->link;
            else
            {
                while (appoggio->link != NULL && flag == false)
                {
                    if (appoggio->link->vertex_id == id_testa)
                    {
                        temp = appoggio->link;
                        appoggio->link = appoggio->link->link;
                        free(temp);
                        flag = true;
                    }
                    else
                        appoggio = appoggio->link;
                }
                if (flag == false)
                    printf("\nImpossibile eliminare l'arco del nodo perche' inesistente.");
            }
        }
    }
}

void cancella_arco_non_orientato(Citta grafo[], int id_coda, int id_testa, int num_nodi)
{
    // inserire qui il codice della funzione...
    cancella_arco_orientato(grafo, id_coda, id_testa, num_nodi);
    cancella_arco_orientato(grafo, id_testa, id_coda, num_nodi);
}

void componenti_connesse(Citta grafo[], int visited[], int num_nodi)
{
    // inserire qui il codice della funzione...
    int i, j = 1;

    for (i = 0; i < num_nodi; i++)
    {
        if (visited[i] == 0)
        {
            printf("\nComponente connessa numero %d\n", j);
            BFS(grafo, visited, i);
            j++;
            printf("\n");
        }
    }
}

void svuotaBuffer()
{
    char c;

    do {
        c = getchar();
    } while (c != '\n');
}