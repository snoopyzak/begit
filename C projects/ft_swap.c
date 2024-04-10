#include <stdio.h>

void ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 7;
    int b = 3;
    ft_swap(&a, &b);
    printf("a is %d, b is %d", a, b);
    return 0;
}