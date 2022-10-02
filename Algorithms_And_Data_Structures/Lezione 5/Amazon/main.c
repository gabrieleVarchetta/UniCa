#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define DIM_CODA 5
#define DIM_STACK 5
#define DIM 50

typedef struct
{
    char articolo[DIM];
    double prezzo;
    char destinatario[DIM];
}Ordine;

struct node
{
    Ordine data;
    struct node* link;
};

typedef struct node Node;

typedef struct
{
    Node* front;
    Node* back;
    int cont;
}Queue;

typedef struct
{
    Node* top;
    int cont;
}Stack;

void menu();
void controlloBufferOverflow ();
void inserisciOrdine(Ordine* ordine);

//prototipi funzioni per la gestione della Coda
bool isEmptyQueue(Queue* coda);
bool isFullQueue(Queue* coda);
void pushQueue(Queue* coda, Ordine val);
Ordine popQueue(Queue* coda);
void printQueue(Queue coda);

//prototipi funzioni per la gestione dello Stack
bool isEmptyStack(Stack* pila);
bool isFullStack(Stack* pila);
void pushStack(Stack* pila, Ordine val);
Ordine popStack(Stack* pila);
void printStack(Stack pila);

int main()
{
    menu();

    return 0;
}

void menu()
{
    int scelta;
    bool flag = true;

    //dichiarazione e inizializzazione della Coda
    Queue queue;
    queue.front = NULL;
    queue.back = NULL;
    queue.cont = 0;
    Ordine ordine;

    //dichiarazione e inizializzazione dello Stack
    Stack stack;
    stack.top = NULL;
    stack.cont = 0;

    do
    {
        printf("\n\n");
        printf("\nScegliere l'operazione da effettuare:");
        printf("\n1. Aggiungere un ordine nella coda");
        printf("\n2. Processare (eliminare) un ordine dalla coda");
        printf("\n3. Inserire un nuovo ordine per la consegna (nello stack)");
        printf("\n4. Rimuovere un ordine dalla lista delle consegne (dallo stack)");
        printf("\n5. Processare il primo ordine e automaticamente prepararlo per la consegna (popQueue, pushStack)");
        printf("\n6. Stampare la lista degli ordini da mettere in consegna");
        printf("\n7. Stampare la lista degli ordini in consegna");
        printf("\n0. Uscire dal programma.\n");
        scanf("%d", &scelta);

        switch (scelta)
        {
            case 0: flag = false;
                break;

            case 1: inserisciOrdine(&ordine);
                    pushQueue(&queue, ordine);
                    printf("\nOrdine aggiunto.");
                break;

            case 2: popQueue(&queue);
                    printf("\nOrdine processato.");
                break;

            case 3: inserisciOrdine(&ordine);
                    pushStack(&stack, ordine);
                    printf("\nOrdine pronto per la consegna.");
                break;

            case 4: popStack(&stack);
                    printf("\nOrdine consegnato.");
                break;

            case 5:     if (isFullStack(&stack))
                            printf("\nERRORE. La lista degli ordini in consegna e' piena.");
                        else if (isEmptyQueue(&queue))
                            printf("\nERRORE. La lista degli ordini in coda e' vuota.");
                        else
                        {
                            ordine = popQueue(&queue);
                            pushStack(&stack, ordine);
                            printf("\nOrdine processato e pronto per la consegna.");
                        }
                break;

            case 6: printf("\nQuesta e' la lista degli ordini in coda: \n");
                    printQueue(queue);
                break;

            case 7: printf("\nQuesta e' la lista degli ordini in consegna (stack): \n");
                    printStack(stack);
        }
    }while (flag == true);

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
    if (coda->cont == DIM_CODA)
        return true;
    else
        return false;
}

/**
 * procedura per l'inserimento di un elemento nella coda
 * @param coda indirizzo della coda in cui inserire l'elemento
 * @param val elemento da inserire
 */
void pushQueue(Queue* coda, Ordine val)
{
    if (isFullQueue(coda))
        printf("\nERRORE OVERFLOW.");
    else
    {
        Node *new_node = (Node*) malloc(sizeof(Node));
        new_node->data = val;
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
Ordine popQueue(Queue* coda)
{
    Ordine val;

    if (isEmptyQueue(coda))
    {
        printf("\nERRORE UNDERFLOW.");
        strcpy(val.destinatario, "N/A");
        val.prezzo = -1;
        strcpy(val.articolo, "N/A");
    }
    else
    {
        Node* temp = coda->front;
        val = temp->data;

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
    return val;
}

/**
 * procedura per la stampa di una coda per intero
 * @param coda coda da stampare
 */
void printQueue(Queue coda)
{
    int i;

    if (isEmptyQueue(&coda))
        printf("\nLa coda e' vuota.");
    else
    {
        for (i = 0; i < coda.cont; i++)
        {
            printf("\nOrdine numero %d:\n", i + 1);
            printf("\tArticolo: %s\n", coda.front->data.articolo);
            printf("\tPrezzo: %.2lf euro\n", coda.front->data.prezzo);
            printf("\tDestinatario: %s\n", coda.front->data.destinatario);
            printf("\n");

            coda.front = coda.front->link;
        }
    }
}

void controlloBufferOverflow ()
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    { }
}

/**
 * procedura che permette l'inserimento da tastiera dei campi di un elemento di tipo ordine
 * @param ordine indirizzo di memoria in cui inserire i campi
 */
void inserisciOrdine(Ordine *ordine)
{
    controlloBufferOverflow();
    printf("\nInserisci il nome dell'articolo: ");
    scanf("%[^\n]s", ordine->articolo);

    controlloBufferOverflow();
    printf("\nInserisci il prezzo dell'articolo: ");
    scanf("%lf", &ordine->prezzo);

    controlloBufferOverflow();
    printf("\nInserisci il destinatario dell'ordine: ");
    scanf("%[^\n]s", ordine->destinatario);
    printf("\n");
}

/**
 * funzione che controlla se una pila è vuota e quindi non ha elementi
 * @param pila indirizzo della pila da controllare
 * @return false se non è vuota, true altrimenti
 */
bool isEmptyStack(Stack* pila)
{
    if (pila->top == NULL)
        return true;
    else
        return false;
}

/**
 * funzione che controlla se una coda è piena e quindi ha raggiunto la dimensione massima
 * @param pila indirizzo della pila da controllare
 * @return false se non è piena, true altrimenti
 */
bool isFullStack(Stack* pila)
{
    if (pila->cont == DIM_STACK)
        return true;
    else
        return false;
}

/**
 * procedura per l'inserimento di un elemento nella pila
 * @param pila indirizzo della pila in cui inserire l'elemento
 * @param val elemento da inserire
 */
void pushStack(Stack* pila, Ordine val)
{
    if (isFullStack(pila))
        printf("\nERRORE OVERFLOW.");
    else
    {
        Node *new_node = (Node*) malloc(sizeof(Node));

        new_node->data = val;
        new_node->link = NULL;

        if (isEmptyStack(pila))
            pila->top = new_node;
        else
        {
            new_node->link = pila->top;
            pila->top = new_node;
        }

        pila->cont++;
    }
}

/**
 * funzione che elimina un elemento dalla pila e lo restituisce
 * @param pila indirizzo della pila da cui eliminare l'elemento
 * @return l'elemento eliminato
 */
Ordine popStack(Stack* pila)
{
    Ordine ordine;

    if (isEmptyStack(pila))
    {
        printf("\nERRORE UNDERFLOW.");
        strcpy(ordine.destinatario, "N/A");
        ordine.prezzo = -1;
        strcpy(ordine.articolo, "N/A");
    }
    else
    {
        Node *temp = pila->top;
        ordine = pila->top->data;

        pila->top = pila->top->link;
        pila->cont--;
        free(temp);
    }
    return ordine;
}

/**
 * procedura per la stampa di una pila per intero
 * @param pila pila da stampare
 */
void printStack(Stack pila)
{
    int i;

    if (isEmptyStack(&pila))
        printf("\nLo stack e' vuoto.");
    else
    {
        for (i = 0; i < pila.cont; i++)
        {
            printf("\nOrdine numero %d:\n", i + 1);
            printf("\tArticolo: %s\n", pila.top->data.articolo);
            printf("\tPrezzo: %.2lf euro\n", pila.top->data.prezzo);
            printf("\tDestinatario: %s\n", pila.top->data.destinatario);
            printf("\n");

            pila.top = pila.top->link;
        }
    }
}
