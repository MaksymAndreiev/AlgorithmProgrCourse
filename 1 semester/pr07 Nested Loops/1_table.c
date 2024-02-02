#include <stdio.h>
#include <math.h>

int main() {
    int i, ii, exp, j;
    i = 1;
    while (i <= 5) {
        for (j = 0; j < i; j++) {
            printf(" \t");
        }
        for (ii = i; ii < 6; ii++) {
            exp = powf(ii, 2);
            printf("%d\t", exp);
        }
        printf("\n");
        i++;
    }
    return 0;
}