#include <stdio.h>

int average()
{

    int n;
    int sum = 0;
    int count = 0;
    double average;

    for(int i = 1; i<=10; i++)
    {
        printf("Enter your number: ");
        scanf("%d", &n);
        sum += n;
        count++;
    }

    if (count != 0)
    {
        average = (double)sum / count;
        printf("Average of entered numbers is: %.2f\n", average);
    }
    else
    {
        printf("No numbers entered.\n");
    }
}

int main()
{
    average();
    return 0;
}
