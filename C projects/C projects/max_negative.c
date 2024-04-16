#include <stdio.h>

int main()
{
    int n;
    int max = -1;
    int desired_amount;

    printf("Enter your desired amount of numbers: ");
    scanf("%d", &desired_amount);

    for (int i = 0; i < desired_amount; i++)
    {
        printf("Enter your numbers: ");
        scanf("%d", &n);

        n *= -1;
        max *= -1;
        
        if (n > max)
            max = n;
    }
    
    max *= -1;
    printf("Max number = %d\n", max);

    return 0;
}