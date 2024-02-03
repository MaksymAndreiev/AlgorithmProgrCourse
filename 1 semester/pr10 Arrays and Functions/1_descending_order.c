#include <stdio.h>

int init(int *v, int N) {
    int i, a = 0;
    printf("Enter numbers:\n");
    for (i = 0; i < N; i++) {
        scanf("%d", &v[i]);
        a++;
    }
    return a;
}

void even_odd(int *v, int N) {
    int i;
    printf("Even: ");
    for (i = N - 1; i >= 0; i--) {
        if (v[i] % 2 == 0) {
            printf("%d\t", v[i]);
        }
    }
}

int main() {
    const int N = 5;
    int v[N];
    printf("Amount of elements: %d\n", init(v, N));
    even_odd(v, N);
    return 0;
}