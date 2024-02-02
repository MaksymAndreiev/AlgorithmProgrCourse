#include <stdio.h>

int main() {
    int i, N;
    unsigned int fact;
    printf("Enter N>0:\n");
    scanf("%d", &N);
    if ((N < 0) || (N > 12)) {
        printf("Error");
        return 1;
    }
    i = 0;
    fact = 1;
    while (i <= N) {
        printf("%d factorial=%u\n", i + 1, fact);
        i++;
        fact *= i;
    }
    return 0;
}