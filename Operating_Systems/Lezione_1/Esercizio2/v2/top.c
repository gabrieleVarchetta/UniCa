#include <stdio.h>
#include "max.h"

int main()
{
    int a, b;

    printf("Inserire il primo numero: ");
    scanf("%d", &a);

    printf("Inserire il secondo numero: ");
    scanf("%d", &b);

    if (!areEquals(a, b))
        printf("Il maggiore tra i due numeri e' %d.\n", max(a, b));
    else
        printf("I due numeri sono uguali.\n");
    
    return 0;
}