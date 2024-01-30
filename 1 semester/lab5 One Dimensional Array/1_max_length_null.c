#include <stdio.h>

void init(int *v, int N) {
    int i;
    printf("Enter numbers:\n");
    for (i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }
}

int main() {
    int N = 10, len = 0, i, max = 0, c, len2 = 0;
    int v[N];
    init(v, N);
    for (i = 0; i < N; i++) {
        if (v[i] == 0) {
            len++;
            if ((v[i + 1] != 0) && ((i + 1) < N)) {
                c = len;
                len = len2;
            }
            if (c > max) {
                max = c;
            }
        }
    }
    printf("Maximum length = %d", max);
    return 0;
}