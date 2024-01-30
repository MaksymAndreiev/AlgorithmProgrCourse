#include <stdio.h>

void init(int *v, int N) {
    int i;
    printf("Enter numbers:\n");
    for (i = 0; i < N; i += 3) {
        scanf("%d", &v[i]);
    }
}

int main() {
    const int N = 18;
    int v[N], i, j;
    init(v, N);
    for (i = 0; i < N; i += 3) {
        if ((i % 2) == 0) {
            v[i + 1] = v[i];
            v[i + 2] = v[i];
        } else {
            v[i + 1] = v[i + 2] = 0;
        }
    }
    for (i = 0; i < N; i++) {
        if (v[i] != 0) {
            printf("%d ", v[i]);
        }
    }
    return 0;
}
