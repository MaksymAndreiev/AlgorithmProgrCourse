#include <stdio.h>

void vector_c(N) {
    int i, c;
    int a[N], b[N];
    for (i = 1; i <= N; i++) {
        a[i] = i;
        b[i] = N - i;
        c = a[i] * b[i];
        printf("%d\t%d\t%d\t%d\n", i, a[i], b[i], c);
    }
}

void scal(N) {
    int i, c, scalab = 0, scalac = 0;
    int a[N], b[N];
    for (i = 1; i <= N; i++) {
        a[i] = i;
        b[i] = N - i;
        scalab += a[i] * b[i];
        scalac += scalab8a[i];
    }
    printf("\n(A,B)=%d\n(A,C)=%d", scalab, scalac);
}

int main() {
    int i, N, c, scalab = 0, scalac = 0;
    printf("Enter N:");
    scanf("%d", &N);
    int a[N], b[N];
    printf("i\tA\tB\tC\n");
    vector_c(N);
    scal(N);
    return 0;
}