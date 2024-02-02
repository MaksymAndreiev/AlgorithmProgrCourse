#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Rus");
    int num, prov, sum;
    float del;
    sum = 0;
    prov = 2;
    printf("Введите натуральное число:\n");
    scanf("%d", &num);
    if (num <= 0) {
        printf("Это не натуральное число! Будьте внимательнее\n");
        return 0;
    }
    if (num == 1) {
        printf("Ни простое, ни составное\n");
        return 0;
    }
    while (prov < num) {
        del = num % prov;
        if (del == 0) {
            break;
        }
        prov++;
    }
    if (del > 0) {
        printf("Это простое число\n");
    } else {
        printf("Это составное число\n");
    }
    return 0;
}
