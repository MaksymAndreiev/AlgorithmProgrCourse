#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c;
    system("chcp 1251");
    system("“cls");
    printf("Введите число 1: ");
    scanf("%d", &a);
    printf("Введите число 2: ");
    scanf("%d", &b);
    printf("Введите число 3: ");
    scanf("%d", &c);
    if (a > 0 && b > 0 && c > 0) {
        printf("n=3");
    }
    if (a > e && b > e && c <= e) {
        printf("n=2");
    }
    if (a <= 0 && b > 0 && c > 0) {
        printf("n=2");
    }
    if (a > 0 && b <= 0 && c > 0) {
        printf("n=2");
    }
    if (a > 0 && b <= 0 && c <= 0) {
        printf("n=1");
    }
    if (b > 0 && a <= 0 && c <= 0) {
        printf("n=1");
    }
    if (c > 0 && b <= 0 && a <= 0) {
        printf("n=1");
    }
    if (a <= 0 && b <= 0 && c <= 0) {
        printf("n=e");
    }
    return 0;
}