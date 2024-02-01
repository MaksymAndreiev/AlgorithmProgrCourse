#include <stdio.h>

int main() {
    int k;
    float sum, drob, eps = 0.0001;
    unsigned int fact;
    k = 1;
    sum = 0;
    drob = 1;
    fact = 1;
    while ((drob >= eps) || (k < 13)) {
        sum += drob;
        drob = 1. / fact;
        k++;
        fact *= k;
    }
    printf("e = %f", sum);
    return 0;
}
