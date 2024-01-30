# include <stdio.h>

const int M = 3, N = 4;

void init(int a[M][N]) {
    int i, j, feature = 0, c = 0;
    printf("Enter numbers:\n");
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            a[i][j] = rand() % 10;
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void feature(int a[M][N], int f[M]) {
    int i, j, sum = 0, c = 0;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            if ((a[i][j] > 0) && (a[i][j] % 2 == 0)) {
                sum += a[i][j];
            } else {
                continue;
            }
        }
        sum -= c;
        c = sum;
        f[i] = c;
        printf("\nfeature(%d)=%d\n", i + 1, f[i]);
    }
}

void comp(int f[M], int a[M][N]) {
    int i, j, temp, k;
    for (i = 0; i < M; i++) {
        for (k = i + 1; k < N; k++) {
            if (f[i] > f[k]) {
                for (j = 0; j < M; j++) {
                    temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }
    }
}

void prov(int f[M], int a[M][N]) {
    int i, j;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[M][N];
    int f[M];
    init(a);
    feature(a, f);
    comp(f, a);
    printf("\n");
    prov(f, a);
}