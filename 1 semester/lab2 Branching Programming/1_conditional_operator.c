#include <stdio.h>
#include <locale.h>

int main() {
    int a, b, c, d, n, sum;
    setlocale(LC_ALL, "Rus");
    printf("Введите четырехзначное число:\n");
    scanf("%d", &n);
    if ((n <= 999) || (10000 <= n)) {
        printf("Error");
    } else {
        a = n / 1000;
        b = (n % 1000) / 100;
        c = (n % 100) / 10;
        d = n % 10;
        sum = a + b + c + d;
        if (sum <= 99) {
            printf("Сумма является двузначным числом\nСумма любого четырехзначного числа будет двузначной");
        } else {
            printf("Сумма является недвузначным числом");
        }
        return 0;
    }
}