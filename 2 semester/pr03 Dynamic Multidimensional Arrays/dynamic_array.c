#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void displayMenu() {
    printf("1. Display array\n");
    printf("2. Add a row\n");
    printf("3. Add a column\n");
    printf("4. Delete a row\n");
    printf("0. Exit\n");
    printf("Your choice: ");
}

void fillArray(int **matrix, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void printArray(int **matrix, int rows, int cols) {
    int i, j;
    if (rows == 0) {
        printf("\nNo elements\n\n");
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addRow(int **matrix, int rows, int cols) {
    int position, i, j;
    matrix[rows - 1] = (int *) malloc(cols * sizeof(int));
    printf("Position:\n");
    scanf("%d", &position);
    for (i = rows - 1; i > position - 1; i--) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = matrix[i - 1][j];
        }
    }
    for (j = 0; j < cols; j++) {
        matrix[position - 1][j] = rand() % 10;
    }
}

void addColumn(int **matrix, int rows, int cols) {
    int position, j, i;
    printf("Position:\n");
    scanf("%d", &position);
    for (i = 0; i < rows; i++) {
        for (j = cols - 1; j > position - 1; j--) {
            matrix[i][j] = matrix[i][j - 1];
        }
    }
    for (i = 0; i < rows; i++) {
        matrix[i][position - 1] = rand() % 10;
    }
}

void deleteRow(int **matrix, int rows, int cols) {
    int position, j, i;
    printf("Delete row number: ");
    scanf("%d", &position);
    for (i = position - 1; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = matrix[i + 1][j];
        }
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    int rows, cols, choice, i;
    printf("Enter the size of the array NxM: ");
    scanf("%d %d", &rows, &cols);
    int *arr[rows];
    for (i = 0; i < rows; i++) {
        arr[i] = (int *) malloc(cols * sizeof(int));
    }
    fillArray(arr, rows, cols);
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Array:\n");
                printArray(arr, rows, cols);
                break;
            case 2:
                addRow(arr, rows += 1, cols);
                break;
            case 3:
                if (rows == 0) {
                    rows = 1;
                    cols = 0;
                }
                addColumn(arr, rows, cols += 1);
                break;
            case 4:
                deleteRow(arr, rows -= 1, cols);
                break;
            case 0:
                return 1;
        }
    }
    return 0;
}
