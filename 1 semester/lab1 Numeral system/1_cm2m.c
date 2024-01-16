#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
    int L, N;
    system("chcp 1251");
    system("“cls");
    printf("Введите длину в сантиметрах:");
    scanf("%d", &L);
    N = L / 100;
    printf("%d\n", N);
    return 0;
}