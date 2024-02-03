#include <stdio.h>
#include <stdlib.h>

void fillArray(int arr[][M], int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr[i][j] = rand() % 10;
        }
    }
}

void printArray(int arr[][M], int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void replaceEvenOdd(int arr[][M], int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr[i][j] = (arr[i][j] % 2 == 0) ? 0 : 1;
        }
    }
}

void convertRowsToDecimal(int arr[][M], int N, int M) {
    for (int i = 0; i < N; i++) {
        int decimal = 0;
        for (int j = 0; j < M; j++) {
            decimal = decimal * 2 + arr[i][j];
        }
        printf("%d ", decimal);
    }
    printf("\n");
}

void findMaxRow(int arr[][M], int N, int M) {
    int maxRow = 0;
    int maxDecimal = 0;
    for (int i = 0; i < N; i++) {
        int decimal = 0;
        for (int j = 0; j < M; j++) {
            decimal = decimal * 2 + arr[i][j];
        }
        if (decimal > maxDecimal) {
            maxDecimal = decimal;
            maxRow = i;
        }
    }
    printf("Row with the maximum decimal number: %d\n", maxRow + 1);
}

void convertColumnsToDecimal(int arr[][M], int N, int M) {
    for (int j = 0; j < M; j++) {
        int decimal = 0;
        for (int i = 0; i < N; i++) {
            decimal = decimal * 2 + arr[i][j];
        }
        printf("%d ", decimal);
    }
    printf("\n");
}

void findMaxColumn(int arr[][M], int N, int M) {
    int maxColumn = 0;
    int maxDecimal = 0;
    for (int j = 0; j < M; j++) {
        int decimal = 0;
        for (int i = 0; i < N; i++) {
            decimal = decimal * 2 + arr[i][j];
        }
        if (decimal > maxDecimal) {
            maxDecimal = decimal;
            maxColumn = j;
        }
    }
    printf("Column with the maximum decimal number: %d\n", maxColumn + 1);
}

int main() {
    int N = 3;
    int M = 4;
    int array[N][M];

    fillArray(array, N, M);
    printf("Original array:\n");
    printArray(array, N, M);

    replaceEvenOdd(array, N, M);
    printf("\nArray after replacing even and odd values:\n");
    printArray(array, N, M);

    printf("\nDecimal numbers from the array rows:\n");
    convertRowsToDecimal(array, N, M);
    findMaxRow(array, N, M);

    printf("\nDecimal numbers from the array columns:\n");
    convertColumnsToDecimal(array, N, M);
    findMaxColumn(array, N, M);

    return 0;
}
