#include <stdio.h>
#include <math.h>

int main()
{
    double number = 123.456;
    int secondDecimalDigit;

    // Multiply the number by 100 to shift the decimal point two places to the right
    // Then take the integer part, which will give you the second decimal digit
    secondDecimalDigit = ((int)(number * 100) % 100) / 10;

    printf("Second decimal digit: %d\n", secondDecimalDigit);

    return 0;
}
