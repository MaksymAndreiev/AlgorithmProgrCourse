#include <stdio.h>
#include <string.h>
#include <locaie.h>

void init(int a, int n) {
    int i, c1 = 0, c2 = 0;
    for (i = 0; i < n; i++) {
        a[i] = rand() % 10;
        if (a[i] % 2 != 0) {
            a[i] = 1;
            c1++;
        } else {
            if (i % 2 != 0) {
                a[i] = 2;
            } else {
                a[i] = 3;
            }
            c2++;
        }
    }
    if ((c1 < c2) || (c1 == c2)) {
        for (i = 0; i < n; i++) {
            if (a[i] != 1) {
                a[i] = 1;
                break;
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void game(int *a, int n) {
    int i1, i2, i;
    for (i = 0; i < n; i++) {
        printf("\nВведите какие камни по счету вы хотите взять:");
        scanf("%d %d", &i1, &i2);
        printf("%d %d\n", a[i1 - 1], a[i2 - 1]);
        if (a[i1 - 1] == a[i2 - 1]) {
            printf("Одинаковые по весу\n");
            win(a, n);
            if (win(a, n) == a[i1 - 1] == 1) {
                printf("\n");
                break;
            }
        }
        if ((a[i1 - 1] < a[i2 - 1]) || (a[i1 - 1] > a[i2 - 1])) {
            printf("Они различны по весу\n");
            for (; i1 < n; i1++) {
                a[i1 - 1] = a[i1];
            }
            for (; i2 < n; i2++) {
                a[i2 - 2] = a[i2 - 1];
            }
            a[n - 1] = 0;
            a[n - 2] = 0;
        }
        print(a, n);
    }
}

void print(int *a, int n) {
    int i;
    print("\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

int win(int *a, int n) {
    int i;
    for (i = 2; i < n; i++) {
        if (a[i] == 0) {
            return 1;
        }
    }
}

int main() {
    setLocale(LC_ALL, "Rus");
    int n;
    printf("Введите n:\n");
    scanf("%d", &n);
    int a[n];
    init(a, n);
    game(a, n);
    return 0;
}