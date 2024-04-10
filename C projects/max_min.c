#include <stdio.h>

int main()
{
    int n;
    int max;
    int min;
    int max_index;
    int min_index;
    int first_number_entered = 0;

    for(int i = 1; i<11; i++)
    {
        printf("Enter your number: ");
        scanf("%d", &n);
        
        if (first_number_entered == 0) 
        {
            max = n;
            min = n;
            max_index = i;
            min_index = i;
            first_number_entered = 1;
        }
        else 
        {
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
    }

    if (first_number_entered) 
    {
        printf("Max number = %d at index %d\nMin number = %d at index %d\n", max, max_index, min, min_index);
    }
    else
    {
        printf("No numbers entered.\n");
    }

    return 0;
}