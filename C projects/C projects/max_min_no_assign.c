#include <stdio.h>

int main()
{
    int n;
    int max;
    int min;
    int max_index;
    int min_index;

    for(int i = 1; i<11; i++)
    {
        printf("Enter your number: ");
        scanf("%d", &n);

        if (n > max)
        {
            max = n;
            max_index = i;
        }
        if (n < min)
        {
            min = n;
            min_index = i;
        }
    }

    printf("Max number = %d at index %d\nMin number = %d at index %d\n", max, max_index, min, min_index);

    return 0;
}