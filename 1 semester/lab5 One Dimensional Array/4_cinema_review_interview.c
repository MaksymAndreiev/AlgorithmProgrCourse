#include <stdio.h>
#include <locale.h>

void init(int *v, int N) {
    int i;
    printf("Выберете всех гостей:\n");
    for (i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }
}

void add(int *v, int N) {
    int i, j, a;
    printf("Введите позицию: ");
    scanf("%d", &j);
    printf("Введите элемент: ");
    scanf("%d", &a);
    printf("Добавлено!\n");
    for (i = 20; i > j - 1; j--) {
        v[j + 1] = v[j];
    }
    for (i = 20; i >= j - 1; i--) {
        v[j] = v[j - 1];
    }
    v[j - 1] = a;
}

void del(int *v, int N, int b) {
    int i;
    for (i = b - 1; i < 20; i++) {
        v[i] = v[i + 1];
    }
    N--;
}

int main() {
    setLocale(LC_ALL, "Rus");
    int N, n, i, j, b;
    int v[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                 0, 0, 0, 0, 0, 0};
    printf("Введите количество всех гостей:\n");
    scanf("%d", &N);
    init(v, N);
    printf("Выберете 1-4:\n1. Показать список.\n2. Добавить.\n3. Удалить.\n4.Выход\n");
    for (j = 0;; j++) {
        scanf("%d", &n);
        if (n == 1) {
            printf("Список:\n");
            if (v[0] == 0) {
                printf("Пусто\n");
            } else {
                for (i = 0; i < 20; i++) {
                    if (v[i] != 0) {
                        printf("%d)%d\n", i + 1, v[i]);
                    }
                }
            }
        } else if (n == 2) {
            add(v, N);
        } else if (n == 3) {
            printf("Введите позицию: ");
            scanf("%d", &b);
            del(v, N, b);
        } else if (n == 4) {
            break;
        }
    }
    return 0;
}
