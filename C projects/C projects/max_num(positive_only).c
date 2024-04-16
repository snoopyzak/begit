#include <stdio.h>
// make a program which takes a desired amount of numbers, then prints out the max number
int main()
{
    int n;
    // you can also handle negative numbers by using the <limits.h> header and then this:
    //     int max = INT_MIN; // Initialize to smallest possible integer value
    int max = -1;
    int desired_amount;

    printf("enter your desired amount of numbers : ");
    scanf("%d", &desired_amount);

    for(int i = 0; i<desired_amount; i++)
    {
        printf("enter your numbers : ");
        scanf("%d", &n);
        if(max<n)
            max = n;
    }
    printf("max number = %d", max);
    return 0;
}

// printi l index li l9a fih l max number, printi l min number tahwa, f same loop
// 3ti sum, average, median. (put each task in a separate function)

/*
#include <stdio.h>

int main()
{
    int n;
    int max; // No need to initialize here
    int desired_amount;
    int first_number_entered = 0; // Flag variable

    printf("Enter your desired amount of numbers: ");
    scanf("%d", &desired_amount);

    for (int i = 0; i < desired_amount; i++)
    {
        printf("Enter your number: ");
        scanf("%d", &n);
        
        if (first_number_entered == 0) {
            max = n;
            first_number_entered = 1; // Update flag
        }
        else {
            if (n > max)
                max = n;
        }
    }

    if (first_number_entered) {
        printf("Max number = %d\n", max);
    } else {
        printf("No numbers entered.\n");
    }
    return 0;
}
*/