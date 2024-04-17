#include <stdio.h>

// Function to convert an integer to string
void int_to_str(int n, char *str) {
    int i = 0;
    // Handle negative numbers
    if (n < 0) {
        str[i++] = '-';
        n = -n;
    }
    // Extract digits one by one
    while (n) {
        int digit = n % 10;
        str[i++] = '0' + digit;
        n /= 10;
    }
    // Add null terminator
    str[i] = '\0';
    // Reverse the string
    int len = i;
    for (int j = 0; j < len / 2; j++) {
        char temp = str[j];
        str[j] = str[len - j - 1];
        str[len - j - 1] = temp;
    }
}

// Function to convert a double to string
void double_to_str(double n, char *str) {
    // Handle negative numbers
    if (n < 0) {
        n = -n;
    }
    // Convert the integer part
    int integer_part = (int)n;
    int_to_str(integer_part, str);

    // Find the length of the integer part
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    // Add the decimal point
    str[len++] = '.';

    // Convert the fractional part
    double fractional_part = n - integer_part;
    for (int i = 0; i < 6; i++) { // Assuming precision of 6 decimal places
        fractional_part *= 10;
        int digit = (int)fractional_part;
        str[len++] = '0' + digit;
        fractional_part -= digit;
    }
    // Add null terminator
    str[len] = '\0';
}

int main() {
    double n = 456321.7651234;
    char str[100];
    double_to_str(n, str);
    printf("The string is: %s\n", str);
    return 0;
}
