#include <stdio.h>

// this program is used to calculate the median of n numbers entered.
// for this to work it needs these things:
// 1- ask the user to input desired n amount of numbers, scanf
// 2- get the median from the entered numbers using a formula
        // use a counter to get the amount of entered numbers
        // check if the desired amount of numbers is an odd or an even number
        // if its odd apply a formula to the numbers entered to get the median, same applies to even in another bracket
        // odd : number in (count+1)/2 , even: number in ((count/2) + (count/2 + 1))/2
        // how to give the is_odd value to get the number in the index of i ???
        // save the median calculated in an integer
// 3- print out the median to the user, printf

int main()
{
    int desired_amount;
    printf("Enter your desired amount of numbers: ");
    scanf("%d", &desired_amount);

    int numbers[desired_amount];

    for (int i = 0; i < desired_amount; i++)
    {
        printf("Enter number %d: ", i + 1);
        // this is just used to make the app more user_friendly so instead of saying enter number blancly, it asks the user to enter number1, number2 etc..
        // and the i + 1 is just cuz array starts from 0 and if we just say i it will ask the user to enter number0, enter number1 etcc, so its just to help the user
        scanf("%d", &numbers[i]);
    }

    double median;
    if (desired_amount % 2 == 0)
    {
    // need to cast double to atleast one part of the division, since both parts were assigned as int first so if we dont cast
    // atleast one part the resut will be an integer and the decimal part will be lost. if we cast atleast one of them as double
    // the result will always be double because it holds more information than int data type
        median = (double)(numbers[desired_amount / 2 - 1] + numbers[desired_amount / 2]) / 2;
        printf("The Median for your numbers is : %.1f\n", median);
    }
    else
    {
        median = numbers[desired_amount / 2];
        printf("The Median for your numbers is : %.0f\n", median);
    }

    return 0;
}