#include <stdio.h>

int main()
{

    int n;
    int sum = 0;
    
    for(int i = 1; i<=10; i++)
    {
        printf("Enter your number: ");
        scanf("%d", &n);
        sum += n;
    }

    printf("Sum of entered numbers is: %d\n", sum);

    return 0;
}
/*
check if entered number is a valid enteger to avoid potential issue:
#include <stdio.h>

int main()
{
    int n;
    int sum = 0;
    
    for (int i = 1; i <= 10; i++)
    {
        printf("Enter your number: ");
        
        // Check if input is a valid integer
        if (scanf("%d", &n) != 1)
        {
            printf("Invalid input. Please enter an integer.\n");
            // Clear input buffer
            while (getchar() != '\n');
            // Decrement loop counter to repeat this iteration
            i--;
            continue;
        }
        
        sum += n; // Add the entered number to the sum
    }

    printf("Sum of entered numbers is: %d\n", sum);

    return 0;
}
*/