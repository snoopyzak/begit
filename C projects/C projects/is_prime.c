#include <stdio.h>

int prime(long long int n) {
    if (n <= 1) {
        return 0; // Numbers less than or equal to 1 are not prime
    }
    else if (n <= 3) {
        return 1; // 2 and 3 are prime
    }
    else if (n % 2 == 0 || n % 3 == 0) {
        return 0; // Even numbers (except 2) and multiples of 3 are not prime
    }
    else {
        for (long long int i = 5; i * i <= n; i += 2) {
            if (n % i == 0) {
                return 0;
            }
        }
    }
    return 1; // If no divisor found, the number is prime
}

int main() {
    if (prime(2147483647)) {
        printf("input is prime\n");
    } else {
        printf("input is non-prime\n");
    }
    return 0;
}
