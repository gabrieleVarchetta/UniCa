#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_NOME 50
#define NUM_TEST 15

typedef struct
{
    char nome[DIM_NOME];
    float gradi;
    int bottiglie;
} Birra;

typedef struct nodo
{
    Birra key;
    struct nodo *parent;
    struct nodo *left;
    struct nodo *right;
} Nodo;

/* -------------------------------
 Funzioni gia' implementate:
 ------------------------------- */
Birra acquisisci_birra();
void stampa_birra(Birra b);

Nodo* crea_nodo(Birra b);
Nodo* carica_test();

/* -------------------------------
 Funzioni da implementare:
 ------------------------------- */
Nodo* insert_nodo(Nodo* root, Nodo* new_node);
void inorder(Nodo* root);
void preorder(Nodo* root);
void postorder(Nodo* root);

int profondita(Nodo* root);
int max(int v1, int v2);

Nodo* ricerca(Nodo* root, char* nome_birra);

Nodo* abr_min(Nodo* root);
Nodo* abr_max(Nodo* root);

Nodo* abr_succ(Nodo* x);
Nodo* abr_pred(Nodo* x);

Nodo* delete_node(Nodo* root, Nodo* nodo);

int main()
{
    Nodo *root = NULL; // Radice dell'ABR

    //variabili ausiliarie
    int scelta;
    Birra tmp_birra;
    Nodo* tmp_nodo;
    int prof;
    char tmp_nome[DIM_NOME];


    do
    {
        //Menu con le operazioni disponibili
        printf("\nMENU:\n");
        printf("1) inserisci nuova birra \n");
        printf("2) visita INORDER \n");
        printf("3) visita PREORDER \n");
        printf("4) visita POSTORDER \n");
        printf("5) calcolo profondita \n");
        printf("6) ricerca di una birra \n");
        printf("7) ricerca del minimo \n");
        printf("8) ricerca del massimo \n");
        printf("9) ricerca del precedente di una birra \n");
        printf("10) ricerca del successore di una birra \n");
        printf("11) cancellazione di una birra \n");
        printf("12) carica birre di test (in un ABR vuoto)\n");
        printf("13) esci \n");

        printf("scelta: ");
        scanf("%d", &scelta);

        switch(scelta)
        {
            case 1:
                tmp_birra = acquisisci_birra();
                tmp_nodo = crea_nodo(tmp_birra);
                root = insert_nodo(root, tmp_nodo);
                break;

            case 2:
                inorder(root);
                break;

            case 3:
                preorder(root);
                break;

            case 4:
                postorder(root);
                break;

            case 5:
                prof = profondita(root);
                printf("\nProfondita: %d\n", prof);
                break;

            case 6:
                printf("\nBirra da cercare: ");
                getchar();
                scanf("%[^\n]s", tmp_nome);
                tmp_nodo = ricerca(root, tmp_nome);

                if(tmp_nodo != NULL)
                    printf("\nTrovata birra %s\n", tmp_nodo->key.nome);
                else
                    printf("\nBirra %s non trovata\n", tmp_nome);
                break;

            case 7:
                tmp_nodo = abr_min(root);
                printf("Il minimo e': %s\n", tmp_nodo->key.nome);
                break;

            case 8:
                tmp_nodo = abr_max(root);
                printf("Il minimo e': %s\n", tmp_nodo->key.nome);
                break;

            case 9:
                printf("\nBirra da cercare: ");
                getchar();
                scanf("%[^\n]s", tmp_nome);
                tmp_nodo = ricerca(root, tmp_nome);

                if(tmp_nodo != NULL)
                {
                    tmp_nodo = abr_pred(tmp_nodo);
                    if(tmp_nodo != NULL)
                        printf("\nIl precedente e': %s\n", tmp_nodo->key.nome);
                    else
                        printf("\nNon esiste un precedente\n");
                }

                else
                    printf("\nBirra non trovata\n");
                break;

            case 10:
                printf("\nBirra da cercare: ");
                getchar();
                scanf("%[^\n]s", tmp_nome);
                tmp_nodo = ricerca(root, tmp_nome);

                if(tmp_nodo != NULL)
                {
                    tmp_nodo = abr_succ(tmp_nodo);
                    if(tmp_nodo != NULL)
                        printf("\nIl successore e': %s\n", tmp_nodo->key.nome);
                    else
                        printf("\nNon esiste un successore\n");
                }

                else
                    printf("\nBirra non trovata\n");
                break;

            case 11:
                printf("\nBirra da cercare: ");
                getchar();
                scanf("%[^\n]s", tmp_nome);
                tmp_nodo = ricerca(root, tmp_nome);

                if(tmp_nodo != NULL)
                {
                    root = delete_node(root, tmp_nodo);
                    printf("\nNodo eliminato\n");
                }

                else
                    printf("\nBirra non trovata\n");
                break;


            case 12:
                root = carica_test();
                break;

            case 13:
                printf("\nCiao!\n");
                break;

            default:
                printf("\nScelta non valida\n");

        }

    } while(scelta != 13);


    return 0;
}


/* -------------------------------
 Funzioni gia' implementate (NON MODIFICARE):
 ------------------------------- */
Birra acquisisci_birra()
{
    Birra b;
    getchar();

    printf("nome: ");
    scanf("%[^\n]s", b.nome);
    getchar();

    printf("gradi: ");
    scanf("%f", &b.gradi);

    printf("bottiglie: ");
    scanf("%d", &b.bottiglie);

    return b;
}

void stampa_birra(Birra b)
{
    printf("--------------------- \n");
    printf("nome:  %s \n", b.nome);
    printf("gradi: %.1f \n", b.gradi);
    printf("bottiglie: %d \n", b.bottiglie);
    printf("--------------------- \n");
}

Nodo* crea_nodo(Birra b)
{
    Nodo* new_node = (Nodo*)malloc(sizeof(Nodo));
    if(new_node != NULL)
    {
        new_node->key = b;
        new_node->parent = NULL;
        new_node->left = NULL;
        new_node->right = NULL;
    }

    return new_node;
}

Nodo* carica_test()
{
    Nodo *root = NULL;
    int i;
    Birra elenco[NUM_TEST] = {{"Ichnusa", 4.7, 3}, {"Founders", 5.7, 15}, {"Peroni", 4.7, 2},
                              {"San Miguel", 3.2, 4}, {"Miller", 4.7, 7}, {"Guinnes", 4.2, 1},
                              {"Best Brau", 4.7, 12}, {"Barley", 5.0, 7}, {"Chouffe", 8.0, 12},
                              {"Franziskaner", 5, 10}, {"Heineken", 5.0, 7}, {"Kwak", 8.0, 14},
                              {"Paulaner", 5.5, 10}, {"Rubiu", 4.5, 10}, {"Tuborg", 5.0, 3}};


    for(i = 0; i < NUM_TEST; i++)
    {
        Nodo *new_birra = crea_nodo(elenco[i]);
        root = insert_nodo(root, new_birra);
    }

    return root;
}


/* -------------------------------
 Funzioni da implementare:
 ------------------------------- */
Nodo* insert_nodo(Nodo* root, Nodo* new_node)
{
    // Inserisci qui il codice...
    Nodo *y, *x;

    y = NULL;
    x = root;

    while (x != NULL)
    {
        y = x;
        if (strcmp(new_node->key.nome, x->key.nome) < 0)
            x = x->left;
        else
            x = x->right;
    }
    //usciti da questo ciclo y è il puntatore al padre del nuovo nodo
    new_node->parent = y;

    if (y == NULL)
        root = new_node;
    else if (strcmp(new_node->key.nome, y->key.nome) < 0)
        y->left = new_node;
    else
        y->right = new_node;

    return root;
}

void inorder(Nodo* root)
{
    // Inserisci qui il codice...
    if (root == NULL)
        return;

    inorder(root->left);
    stampa_birra(root->key); //visita del nodo -> stampa del suo contenuto
    inorder(root->right);
}

void preorder(Nodo* root)
{
    // Inserisci qui il codice...
    if (root == NULL)
        return;

    stampa_birra(root->key); //visita del nodo -> stampa del suo contenuto
    preorder(root->left);
    preorder(root->right);
}

void postorder(Nodo* root)
{
    // Inserisci qui il codice...
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    stampa_birra(root->key); //visita del nodo -> stampa del suo contenuto
}

int profondita(Nodo* root)
{
    // Inserisci qui il codice...
    int sx, dx;

    if (root == NULL)
        return 0;

    sx = profondita(root->left);
    dx = profondita(root->right);

    return 1 + max(sx, dx);
}

/**
 * restituisce il massimo tra due interi, utilizzato per calcolare la profondità
 * dell'ABR.
 * @param v1 profondità sottoalbero sinistro
 * @param v2 profondità sottoalbero destro
 * @return il massimo tra le due profondità
 */
int max(int v1, int v2)
{
    // Inserisci qui il codice...
    if (v1 > v2)
        return v1;
    else
        return v2;
}

Nodo* ricerca(Nodo* root, char* nome_birra)
{
    // Inserisci qui il codice...
    while (root != NULL)
    {
        if (strcmp(nome_birra, root->key.nome) == 0)
            return root;
        if (strcmp(nome_birra, root->key.nome) < 0)
            root = root->left;
        else
            root = root->right;
    }
    //se dopo la ricerca non è stata trovata nessuna corrispondenza, restituisce NULL
    return NULL;
}

Nodo* abr_min(Nodo* root)
{
    // Inserisci qui il codice...
    Nodo *appoggio;

    appoggio = root;

    while (appoggio->left != NULL)
        appoggio = appoggio->left;

    return appoggio;
}

Nodo* abr_max(Nodo* root)
{
    // Inserisci qui il codice...
    Nodo *appoggio;

    appoggio = root;

    while (appoggio->right != NULL)
        appoggio = appoggio->right;

    return appoggio;
}


Nodo* abr_pred(Nodo* x)
{
    // Inserisci qui il codice...
    Nodo *appoggio = NULL;

    if (x->left != NULL)
        return abr_max(x->left);

    appoggio = x->parent;

    while (appoggio != NULL && x == appoggio->left)
    {
        x = appoggio;
        appoggio = appoggio->parent;
    }

    return appoggio;
}

Nodo* abr_succ(Nodo* x)
{
    // Inserisci qui il codice...
    Nodo *appoggio = NULL;

    if (x->right != NULL)
        return abr_min(x->right);

    appoggio = x->parent;

    while (appoggio != NULL && x == appoggio->right)
    {
        x = appoggio;
        appoggio = appoggio->parent;
    }

    return appoggio;
}

Nodo* delete_node(Nodo* root, Nodo* nodo)
{
    // Inserisci qui il codice...
    Nodo *appoggio1, *appoggio2;

    if (nodo->left == NULL || nodo->right == NULL)
        appoggio1 = nodo;
    else
        appoggio1 = abr_succ(nodo);

    if (appoggio1->left != NULL)
        appoggio2 = appoggio1->left;
    else
        appoggio2 = appoggio1->right;

    if (appoggio2 != NULL)
        appoggio2->parent = appoggio1->parent;

    if (appoggio1->parent == NULL)
        root = appoggio2;
    else if (appoggio1->parent->left == appoggio1)
        appoggio1->parent->left = appoggio2;
    else
        appoggio1->parent->right = appoggio2;

    if (appoggio1 != nodo)
        nodo->key = appoggio1->key;

    free(appoggio1);

    return root;
}