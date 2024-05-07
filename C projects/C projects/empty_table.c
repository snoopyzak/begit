#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int main() {
    int table[MAX_ROWS][MAX_COLS];
    int rows, cols;

    printf("Enter the number of rows (max %d): ", MAX_ROWS);
    scanf("%d", &rows);

    printf("Enter the number of columns (max %d): ", MAX_COLS);
    scanf("%d", &cols);

    if (rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Exceeded maximum size.\n");
        return 1;
    }

    printf("Enter the elements of the table:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &table[i][j]);
        }
    }

    printf("The table you entered is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", table[i][j]);
        }
        printf("\n");
    }

    return 0;
}
