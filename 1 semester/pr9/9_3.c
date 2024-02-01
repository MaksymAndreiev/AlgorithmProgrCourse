#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, N, c, j, ii;
    printf("Enter N:\n");
    scanf("%d", &N);
    int a[N];
    for (i = 0; i < N; i++) {
        a[i] = rand();
        printf("%d\t", a[i]);
    }
    printf("\n\n\n");
    for (j = 0; j < N; j++) {
        for (ii = 0; ii < N - 1; ii++) {
            if (a[ii + 1] > a[ii]) {
                c = a[ii];
                a[ii] = a[ii + 1];
                a[ii + 1] = c;
            }
            for (i = 0; i < N; i++) {
                printf("%d\t", a[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
