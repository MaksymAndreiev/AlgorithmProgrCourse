#include <stdio.h>
#include <math.h>

void init(int *v, int N) {
    int i;
    printf("Enter numbers:\n");
    for (i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }
}

int sum(int *v, int N) {
    int i, sum = 0;
    for (i = 0; i < N; i++) {
        sum += v[i];
    }
    return sum;
}

float len(int *v, int N) {
    int i, power, sum = 0;
    for (i = 0, i < N; i++) {
        power = pow(v[i], 2);
        sum += power;
    }
    return sqrt(sum);
}

int main() {
    int N;
    printf("Enter N:\n");
    scanf("%d", &N);
    int v[N];
    init(v, N);
    printf("%d\n", sum(v, N));
    printf("%.3f", len(v, N));
    return 0;
}