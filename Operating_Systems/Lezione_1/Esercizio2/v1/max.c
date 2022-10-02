#include <stdio.h>
#include <stdbool.h>

int max(int a, int b);
bool areEquals(int a, int b);

int main()
{
    int num1, num2;

    printf("Inserire il primo numero: ");
    scanf("%d", &num1);

    printf("Inserire il secondo numero: ");
    scanf("%d", &num2);

    if (!areEquals(num1, num2))
        printf("Il maggiore tra i due numeri e' %d\n", max(num1, num2));
    else
        printf("I due numeri sono uguali\n");

    return 0;
}

int max(int a, int b)
{
    int temp;

    temp = (a > b) ? a : b;

    return temp;
}

bool areEquals(int a, int b)
{
    if (a == b)
        return true;
    
    return false; 
}