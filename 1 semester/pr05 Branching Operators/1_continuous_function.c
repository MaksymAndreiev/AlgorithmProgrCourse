#include <stdio.h>
#include <math.h>

double computeFunction(double x) {
    if (x < -2.0 || x > 2.0) {
        return 0.0;
    } else if (fabs(x) > 1.0 && fabs(x) <= 2.0) {
        return x;
    } else if (x > -1.0 && x < 1.0) {
        return pow(x, 3);
    } else {
        return 0.0;
    }
}

int main() {
    printf("x\t|\tf(x)\n");
    printf("--------------------\n");

    for (double x = -5.0; x <= 5.0; x += 0.5) {
        printf("%.2f\t|\t%.2f\n", x, computeFunction(x));
    }

    return 0;
}
