#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void random(int *a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        a[i] = rand() % 10;
    }
}

void prrrint(int *a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void addd(int *a, int n, int m) {
    realloc(a, sizeof(int) * (n + m));
    int i;
    for (i = n; i < (n + m); i++) {
        a[i] = rand() % 10;
    }
    for (i = 0; i < (n + m); i++) {
        printf("%d ", a[i]);
    }
}

void delette(int *a, int n, int m, int k) {
    realloc(a, sizeof(int) * (n + m - k));
    int i;
    for (i = 0; i < (n + m - k); i++) {
        printf("%d ", a[i]);
    }
    if (sizeof(int) * (n + m - k) == 0) {
        printf("null");
    }
}

int main() {
    int n, m = 0, k;
    printf("Enter a number of elements:\n");
    scanf("%d", &n);
    int *a;
    a = (int *) malloc(n * sizeof(int));
    random(a, n);
    prrrint(a, n);
    printf("\nEnter a number of elements that should be added:\n");
    scanf("%d", &m);
    addd(a, n, m);
    printf("\nEnter a number of elements that should be deleted:\n");
    scanf("%d", &k);
    if (k > ((n + m))) {
        printf("Incorrect k");
    }
    delette(a, n, m, k);
    return 0;
}
