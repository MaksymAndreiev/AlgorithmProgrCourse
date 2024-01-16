#include <stdio.h>
#include <windows.h>

double power(double a, long n) {
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 1.0 / (a * power(1.0 / a, n + 1));
    }
    return a * power(a, n - 1);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double a;
    long n;
    int f = 2;
    while (printf("Введите основание и показатель степени ") && scanf("%lf %ld", &a, &n) == 2) {
        printf("Результат: %lf\nВыход? 1.Да 2.Нет\n", power(a, n));
        scanf("%d", &f);
        if (f == 1) {
            break;
        }
    }
    return 0;
}
