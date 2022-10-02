#include <stdio.h>
#include <stdbool.h>

int max(int a, int b);
int min(int a, int b);
bool areEquals(int a, int b);

int main()
{
    int num1, num2, scelta;

    do
    {
        printf("Scegliere l'operazione da eseguire\n");
        printf("1. Maggiore tra due numeri\n2. Minore tra due numeri\n");
        scanf("%d", &scelta);
    } while (scelta < 1 || scelta > 2);
    
    printf("Inserire il primo numero: ");
    scanf("%d", &num1);

    printf("Inserire il secondo numero: ");
    scanf("%d", &num2);

    switch (scelta)
    {
    case 1:
        if(!areEquals(num1, num2))
            printf("Il maggiore tra i due numeri e' %d.\n", max(num1, num2));
        else
            printf("I due numeri sono uguali.\n");
        break;
    
    case 2:
        if(!areEquals(num1, num2))
            printf("Il minore tra i due numeri e' %d.\n", min(num1, num2));
        else
            printf("I due numeri sono uguali.\n");
    default:
        break;
    }

    return 0;
}

int max(int a, int b)
{
    int temp;

    temp = (a > b) ? a : b;

    return temp;
}

int min(int a, int b)
{
    int temp;

    temp = (a < b) ? a : b;

    return temp;
}

bool areEquals(int a, int b)
{
    if(a == b)
        return true;

    return false;
}