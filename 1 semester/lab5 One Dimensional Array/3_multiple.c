#include <stdio.h>

void init(int *v, int N) {
    int i;
    printf("Enter numbers:\n");
    for (i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }
}

int main() {
    const int N = 5;
    int v[N], i, j, k, p;
    init(v, N);
    printf("Enter k and p: ");
    scanf("%d %d", &k, &p);
    for (i = 0; i < N; i++) {
        if (v[i] % k == 0) {
            v[i] *= p;
        }
        printf("%d ", v[i]);
    }
    return 0;
}