#include <stdio.h>

int prime(int N) {
    int i;
    if (N == 1) {
        return 0;
    }
    for (i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int N, c = 0, ii;
    printf("Enter the range:\n");
    scanf("%d", &N);
    for (ii = 1; ii <= N; ii++) {
        if (prime(ii)) {
            printf("%d\t", ii);
            c++;
        }
    }
    printf("\nAmount of prime numbers: %d", c);
    return 0;
}
