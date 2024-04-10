#include <stdio.h>
// sum of natural numbers from 0, example: n=8, sum= 0 + 1 + 2  3 + 4 + 5 + 6 + 7 + 8
int main() {

 int n, sum = 0, i = 1;

 printf("Enter a positive integer: ");

 scanf("%d", &n);

 while (i <= n){
    sum += i;
    i++;
 }

 printf("Sum of natural numbers from 1 to %d: %d\n", n, sum);

 return 0;

}