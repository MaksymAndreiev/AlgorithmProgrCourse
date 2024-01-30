#include <stdio.h>
#include <math.h>

int main() {
    int N, i, k, fact = 1, x;
    double F = 0, S, eps, slog, delta;
    printf("Enter eps: ");
    scanf("%f", &eps);
    printf("x\t\t\t\tF\t\t\t\tS\tdelta\n");
    for (x = 0, k = 1; x <= 10; x++, k++) {
        fact *= k;
        slog = (pow(-1, (k + 1)) * (pow(2, (2 * k - 1))) * pow(x, (2 * k))) / (2 * fact);
        F += slog;
        S = F - (pow(sin(x), 2));
        delta = F - S;
        if (fabs(slog) < eps) {
            break;
        }
        printf("%d\t%25.2lf\t%25.2lf\t%5.2lf\n", x, F, S, delta);
    }
    return 0;
}