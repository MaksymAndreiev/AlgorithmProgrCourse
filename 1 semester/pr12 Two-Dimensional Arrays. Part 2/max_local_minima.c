#include <stdio.h>
#include <math.h>

void init(int v[][3], int M, int N) {
    int i, j;
    printf("Enter numbers:\n");
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &b[i][j]);
        }
    }
}

int main() {
    const int M = 2, N = 3;
    int localmin, i, j, max;
    int v[M][N];
    init(v, M, N);
    max = 0;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            if ((v[i][j] < v[i][j + 1]) && (v[i][j] < v[i][j - 1])) {
                localmin = v[i][j];
                if (abs(localmin) > abs(max)) {
                    max = localmin;
                }
            }
        }
    }
    printf("Maximum of local minimum: %d", max);
    return 0;
}