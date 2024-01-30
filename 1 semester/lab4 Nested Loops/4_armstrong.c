#include <stdio.h>
#include <math.h>

int armstrong(int x) {
    int y = x, n = 0, numb = 0;
    do {
        y = y / 10;
        n++;
    } while (y);
    y = x;
    do {
        numb = numb + pow(y % 10, n);
        y = y / 10;
    } while (y);
    if (x == numb) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int N, k, i;
    printf("Enter k and N:\n");
    scanf("%d %d", &k, &N);
    for (i = k; i < N; ++i) {
        if (armstrong(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}