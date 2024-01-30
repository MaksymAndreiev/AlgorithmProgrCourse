#include <stdio.h>
#include <math.h>

int main() {
    int N, k, pow = 1, d, i;
    float sum = 0;
    printf("Enter N and k:\n");
    scanf("%d %d", &N, &k);
    for (i = 0; pow <= N; i++) {
        pow = pow * k;
    }
    for (; i >= 0; i--) {
        pow /= k;
        d = N / pow;
        N = N - d * pow;
        printf("%d", d);
    }
    return 0;
}