#include <stdio.h>
// also known as number factorial, example: 5! = 15
int main() {

 int n, fac = 1, i = 1;

 printf("Enter a positive integer: ");

 scanf("%d", &n);

 while (i <= n){
    fac *= i;
    i++;
 }

 printf("Factorial of natural numbers from 1 to %d: %d\n", n, fac);

 return 0;

}