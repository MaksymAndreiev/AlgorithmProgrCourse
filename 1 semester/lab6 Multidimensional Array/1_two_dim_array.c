#include <stdio.h>

int M = 4;

void init(int a[M][M]) {
    int i, j;
    for (i = 0; i < M; i++) {
        for (j = 0; j < M; j++) {
            a[i][j] = i * M + j + 1;
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void sum(int a[M][M]) {
    int i, j, sum1 = 0, sum2 = 0, sum3 = 0;

    for (i = 0; i < M; i++) {

        for (j = 0; j < M; j++) {
            sum3 += a[i][j];
        }
    }
    a[0][M - 1] = sum3;
    a[M - 1][0] = sum3;
    for (i = 1, j = 1; i < (M - 1) && j < (M - 1); i++, j++) {
        sum2 = a[i - 1][j - 1] + a[i][j - 1] + a[i - 1][j] + a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 1][j - 1] +
               a[i + 1][j] + a[i - 1][j + 1];
        a[i + 1][j - 1] = sum2;
        a[i - 1][j + 1] = sum2;
    }
    for (i = 1, j = 1; i < M && j < M; i++, j++) {
        sum1 = a[i - 1][j - 1] + a[i][j - 1] + a[i - 1][j] + a[i][j];
        a[i - 1][j] = sum1;
        a[i][j - 1] = sum1;
    }
    for (i = 0; i < M; i++) {
        for (j = 0; j < M; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[M][M];
    init(a);
    sum(a);
    return 0;
}