#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <locale.h>

struct dev {
    int num;
    char name[20];
    int year;
    int cost;
};

void print(struct dev *mas, int sz) {
    int i;
    printf("Номер\tИмя\tГод\tЦена\t\n");
    for (i = 0; i < sz; i++) {
        printf("%d\t%s\t%d\t%d\t\n", mas[i].num, mas[i].name, mas[i].year, mas[i].cost);
    }
    printf("\n");
}

void search_price_range(struct dev *mas, int sz) {
    int i, pr1, pr2;
    printf("Введите первую цену:");
    scanf("%d", &pr1);
    printf("Введите вторую цену:");
    scanf("%d", &pr2);
    printf("\n");
    printf("Номер\tИмя\tГод\tЦена\t\n");
    for (i = 0; i < sz; i++) {
        if (mas[i].cost >= pr1 && mas[i].cost <= pr2) {
            printf("%d\t%s\t%d\t%d\t\n", mas[i].num, mas[i].name, mas[i].year, mas[i].cost);
        }
    }
    printf("\n");
}

void init(struct dev *mas, int sz) {
    printf("Номер:");
    scanf("%d", &mas[sz].num);
    printf("Имя:");
    scanf("%20s", &mas[sz].name);
    printf("Год:");
    scanf("%d", &mas[sz].year);
    printf("Цена:");
    scanf("%d", &mas[sz].cost);
    printf("\n");
}

void check_year(struct dev *mas, int sz) {
    int i, syear;
    printf("Введите год:");
    scanf("%d", &syear);
    printf("Номер\tИмя\tГод\tЦена\t\n");
    for (i = 0; i < sz; i++) {
        if (mas[i].year == syear) {
            printf("%d\t%s\t%d\t%d\t\n", mas[i].num, mas[i].name, mas[i].year, mas[i].cost);
        }
    }
    printf("\n");
}

void check_highest_price(struct dev *mas, int sz) {
    int i, max = 0, z;
    for (i = 0; i < sz; i++) {
        if (mas[i].cost > max) {
            max = mas[i].cost;
            z = i;
        }
    }
    printf("Номер\tИмя\tГод\tЦена\t\n");
    printf("%d\t%s\t%d\t%d\t\n", mas[z].num, mas[z].name, mas[z].year, mas[z].cost);
    printf("\n");
}

void delete_device(struct dev *mas, int sz, struct dev *dop, int size) {
    int i, z, a;
    struct dev *temp;
    printf("Введите номер устройства:");
    scanf("%d", &z);
    for (i = 0; i < sz; i++) {
        if (mas[i].num == z) {
            a = i;
        }
    }
    dop[size - 1] = mas[a];
    for (i = a; i < sz; i++) {
        mas[i] = mas[i + 1];
    }
    printf("\n");
}

void print2(struct dev *dop, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d\t%s\t%d\t%d\t", dop[i].num, dop[i].name, dop[i].year, dop[i].cost);
        printf("\n");
    }
    printf("\n");
}

int main() {

    setlocale(LC_ALL, "Rus");
    struct dev *mas, a, *dop;
    int sz = 0, k, i, size = 1;
    dop = (struct dev *) malloc(size * sizeof(struct dev));
    size--;
    while (1) {
        printf("1.Добавить устройство\n2.Искать устройство по номеру\n3.Поиск устройства по ценовому диапазону\n");
        printf("4.Показать устройство с самой высокой ценой\n5.Удалить устройство\n6.Показать все устройства\n7.Выход\n\n");
        printf("Мой выбор:");
        scanf("%d", &k);
        printf("\n");
        if (k == 1) {
            sz++;
            if (sz > 1) {
                mas = (struct dev *) realloc(mas, sz * sizeof(struct dev));
            } else {
                mas = (struct dev *) malloc(sz * sizeof(struct dev));
            }
            init(mas, sz - 1);
        }
        if (k == 2) {
            check_year(mas, sz);
        }
        if (k == 3) {
            search_price_range(mas, sz);
        }
        if (k == 4) {
            check_highest_price(mas, sz);
        }
        if (k == 5) {
            size++;
            dop = (struct dev *) realloc(dop, size * sizeof(struct dev));
            delete_device(mas, sz, dop, size);
            sz--;
            mas = (struct dev *) realloc(mas, sz * sizeof(struct dev));
        }
        if (k == 6) {
            print(mas, sz);
        }
        if (k == 7) {
            free(mas);
            free(dop);
            return 0;
        }
        if (k == 0) {
            print2(dop, size);
        }
    }
}
