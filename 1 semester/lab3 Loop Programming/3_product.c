#include <stdio.h>
#include <math.h>

int main() {
    float num = 1, denom = 2, f = 1, eps = 0.0001, del;
    while (f >= eps) {
        del = num / denom;
        f *= del;
        num += 2.;
        denom += 2.;
        printf("%f\n", f);
    }
    return 0;
}