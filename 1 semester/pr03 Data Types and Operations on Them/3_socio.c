#include <stdio.h>

int main() {
    int M;
    int N;
    double L;
    printf("M=");
    scanf("%d", &M);
    printf("N=");
    scanf("%d", &N);
    L = (double) M / (double) N * 100;
    printf("\nL=%.f%%", L);
    return 0;
}