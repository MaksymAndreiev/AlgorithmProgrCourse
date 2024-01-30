#include <stdio.h>
#include <math.h>

int main() {
    int N, i, cont, S = 0;
    printf("Enter a number:\n");
    scanf("%d", &N);
    if (N <= 0) {
        printf("Error\n");
    } else {
        for (i = N; i < 2 * N; i++) {
            S += pow(i, 2);
            printf("%d\n", S);
        }
    }
    return 0;
}