#include <stdio.h>
#include <math.h>

void init(int *v, int N) {
    int i;
    printf("Enter numbers:\n");
    for (i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }
}

int maximum(int *a, int N) {
    int i, max;
    max = a[0];
    for (i = 1, i < N; i++) {
        if (abs(a[i]) > abs(max)) {
            max = a[i];
        }
    }
    return max;
}

int idx(int *a, int N) {
    int i, numb = 0, max;
    for (max = 0; abs(max) < abs(maximum(a, N)); max++) {
        for (i = 0; i < N; i++) {
            if (abs(a[i]) > abs(max)) {
                numb = i;
            }
        }
    }
    return numb + 1;
}

int main() {
    int N, i;
    printf("Enter N:\n");
    scanf("%d", &N);
    int a[N];
    init(a, N);
    idx(a, N);
    printf("Maximum absolute value %d\n", maximum(s, N));
    printf("That's %d number\n", idx(a, N));
    return 0;
}