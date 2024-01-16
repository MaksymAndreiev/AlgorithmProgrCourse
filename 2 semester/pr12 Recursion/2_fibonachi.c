#include <stdio.h>
#include <windows.h>

long long int fibonachi(int N) {
    if (N == 0) {
        return 0;
    }
    if (N == 1) {
        return 1;
    }
    return fibonachi(N - 1) + fibonachi(N - 2);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N, f = 2;
    while (printf("Введите N для вычисления N-го числа Фибоначчи:") && scanf("%d", &N) == 1) {
        printf("Результат: %lld\nВыход? 1.Да 2.Нет\n ", fibonachi(N));
        scanf("%d", &f);
        if (f == 1) {
            break;
        }
    }
    return 0;
}
