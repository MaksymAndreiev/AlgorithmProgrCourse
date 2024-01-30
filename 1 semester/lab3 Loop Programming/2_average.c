#include <stdio.h>
#include <math.h>

int main() {
    int N, i, A, q = 0;
    float cr, sum = 0;
    printf("Enter a number of numbers:\n");
    scanf("%d", &N);
    printf("Enter numbers:\n");
    for (i = 0; i < N; i++) {
        scanf("%d", &A);
        if (A > 0) {
            sum += A;
            q++;
        }
    }
    cr = sum / q;
    printf("%.2f", cr);
    return 0;
}