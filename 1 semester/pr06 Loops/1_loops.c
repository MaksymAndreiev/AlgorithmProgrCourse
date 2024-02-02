#include <stdio.h>

int main() {
    int i, n, val;
    printf("Enter n:\n");
    scanf("%d", &n);
    if ((n < 0) || (n > 6)) {
        printf("Error");
        return 1;
    }
    val = 1;
    printf("n\t2^n\n");
    while (i <= n) {
        printf("%d\t", i);
        printf("%d\n", val);
        i++;
        val *= 2;
    }
    for (i = 0; i <= n; i++) {
        printf("%d\t", i);
        printf("%d\n", val);
        val *= 2;
    }
    do {
        printf("%d\t", i);
        printf("%d\n", val);
        i++;
        val *= 2;
    } while (i <= 2);
    return 0;
}