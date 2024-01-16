#include <stdio.h>
#include <windows.h>

int c = 0;

double power(double a, long n) {
    c++;
    double tmp;
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 1.0 / (a * power(1.0 / a, n + 1));
    }
    if (n % 2) {
        return a * power(a, n - 1);
    }
    return power(a * a, n / 2);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double a;
    long n;
    int f = 2;
    while (printf("Введите основание и показатель степени ") && scanf("%lf %ld", &a, &n) == 2) {
        printf("Результат: %lf\nВыход? 1.Да 2.Нет\n", power(a, n));
        printf("%d шагов\n", c);
        c = 0;
        scanf("%d", &f);
        if (f == 1) {
            break;
        }
    }
    return 0;
}
