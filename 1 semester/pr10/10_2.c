#include <stdio.h>

void init(int *v, int N) {
    int i;
    printf("Enter numbers:\n");
    for (i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }
}

void positive(int *v, int N) {
    int i, p;
    for (i = 0; i < N; i++) {
        if (v[i] > 0) {
            printf("%d\t", v[i]);
        }
    }
}

void negative(int *v, int N) {
    int i, n;
    for (i = 0; i < N; i++) {
        if (v[i] <= 0) {
            printf("%d\t", v[i]);
        }
    }
}

int main() {
    int N;
    printf("Enter N:\n");
    scanf("%d", &N);
    int v[N];
    init(v, N);
    positive(v, N);
    negative(v, N);
    return 0;
}