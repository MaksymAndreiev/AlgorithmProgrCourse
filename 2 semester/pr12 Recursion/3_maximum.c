#include <windows.h>
#include <time.h>

#define MAX 40006
int c = 0, N;

int maximum(int a[]) {
    c++;
    static int i = 0, max = 0;
    if (i < N) {
        if (max < a[i])
            max = a[i];
        i++;
        maximum(a);
    }
    return max;
}

void init(int *mas, int N) {
    int i;
    for (i = 0; i < N; i++) {
        mas[i] = rand() % 100;
        printf("%d ", mas[i]);
    }
    printf("\n");
}

int main() {
    int i, mas[MAX];
    srand(time(NULL));
    printf("Enter the size of the array: ");
    scanf("%d", &N);
    printf("\n");
    for (i = 0; i < N; i++) {
        mas[i] = rand() % 10;
        printf("%d ", mas[i]);
    }
    printf("\nLargest element of the array is %d\n", maximum(mas));
    printf("c=%d", c);
    return 0;
}
