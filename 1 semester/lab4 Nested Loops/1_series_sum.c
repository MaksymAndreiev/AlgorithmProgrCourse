#include <stdio.h>
#include <math.h>

int main() {
    int N, k;
    float sum = 0;
    printf("Enter N:\n");
    scanf("%d", &N);
    for (k = 1, k <= N; k++) {
        sum += (pow(-1, k)) / (pow(((2 * k) + 1), 2));
    }
    printf("sum = %f", sum);
    return 0;
}