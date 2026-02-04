#include<stdio.h>
void increment(int *x)
{
    (*x)++;
}
int main()
{
    int a;
    printf("Enter a number:");
    scanf("%d", &a);
    increment(&a);
   printf("Value after increment: %d\n", a);

    return 0;
}