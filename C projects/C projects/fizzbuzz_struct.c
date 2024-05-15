#include <stdio.h>

struct Fizzbuzz
{
    char*    fizzbuzz;
};

int main()
{
    struct Fizzbuzz fb;

    for(int i=1; i<=100; i++)
    {
            if (i % 3 == 0 && i % 5 == 0)
            {
    	        fb.fizzbuzz = "FizzBuzz";
    	        printf("%s\n", fb.fizzbuzz);
    	    }
            else if (i % 3 == 0)
            {
                fb.fizzbuzz = "Fizz";
                printf("%s\n", fb.fizzbuzz);
            }
            else if (i % 5 == 0)
            {
                fb.fizzbuzz = "Buzz";
                printf("%s\n", fb.fizzbuzz);
            }
            else
                printf("%d\n", i);
    }
}