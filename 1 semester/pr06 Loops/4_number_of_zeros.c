#include <stdio.h>

int main() {
    int N, n, i, sum, ii;
    printf("Enter a number of numbers:\n");
    scanf("%d", &N);
    printf("Enter the numbers:\n");
    sum = 0;
    i = 0;
    while (i < N) {
        i++;
        scanf("%d", &n);
        if (n != 0) {
            ii++;
        }
        if (n == 0) {
            sum++;
        }
    }
    if (ii == N) {
        printf("No 0");
    } else {
        printf("Numbers of 0: %d", sum);
    }
    return 0;
}
