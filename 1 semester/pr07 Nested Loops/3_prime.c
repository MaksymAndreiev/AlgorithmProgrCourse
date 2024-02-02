#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Rus");
    int num, prov, sum;
    float del;
    sum = 0;
    prov = 2;
    printf(":\n");
    scanf("%d", &num);
    if (num <= 0) {
        printf("\n");
        return 0;
    }
    if (num == 1) {
        printf("\n");
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
        printf("\n");
    } else {
        printf("\n");
    }
    return 0;
}
