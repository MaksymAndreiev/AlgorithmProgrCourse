#include <stdio.h>
#include <math.h>

int main() {
    int n;
    float S_f = 0, i = 1, drob = 0, N;
    double S_d = 0, T;
    print("Choose N:\n1)1000\n2)10000\n3)50000\n4)100000\n");
    scanf("%d", &n);
    if (n == 1) {
        N = 1000;
    }
    if (n == 2) {
        N = 10000;
    }
    if (n == 3) {
        N = 50000;
    }
    if (n == 4) {
        N = 100000;
    }
    for (i; i < N; i++) {
        S_f += drob;
        S_d += drob;
        drob = 1. / (i * (i + 1));
    }
    T = 1 - 1 / (N + 1);
    printf("%.17f\t%.17lf\tT=%lf", S_f, S_d, T);
    return 0;
}