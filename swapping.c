#include<stdio.h>
void swap(int *a, int *b)
{
    int c;
    *a = *b;
    *b = c;
}
int main()
{
    int x, y;
    printf("Enter two numbers:\n");
    scanf("%d%d", &x, &y);
    swap(&x, &y);
    printf("After swapping:\n");
    printf("x = %d, y = %d", x, y);
    return 0;
}