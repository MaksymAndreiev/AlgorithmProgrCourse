#include <stdio.h>
#include <windows.h>
#include <string.h>

#define N 5
struct product {
    char name[10];
    int count;
    double price;
} product[N], tmp;

void change(FILE *file, struct product *product) {
    int i, c = 0, j;
    char tmpname[10], t[10];
    strcpy(tmp.name, "Маска");
    tmp.price = 10.5;
    tmp.count = 100;
    printf("Наименование:\n");
    scanf("%s", &tmpname);
    file = fopen("prct19.dat", "rb+");
    for (i = 0; i < N; i++) {
        fread(&product[i], sizeof(struct product), 1, file);
        if (strcmp(tmpname, product[i].name) == 0) {
            c++;
            printf("Меняем:\n");
            printf("%s %d %.2lf", product[i].name, product[i].count, product[i].price);
            strcpy(product[i].name, tmp.name);
            product[i].count = tmp.count;
            product[i].price = tmp.price;
            j = sizeof(struct product);
            fseek(file, -j, 1); //возврат на sizeof() байт назад
            fwrite(&product[i], sizeof(struct product), 1, file);
            printf("\n%s %d %.2lf", product[i].name, product[i].count, product[i].price);
            fseek(file, j, 1);
        }
    }
    if (c == 0) {
        printf("Не найдено.\n");
    }
    fclose(file);
}

void trash(FILE *file, struct product *product) {
    int i, j, tm[5];
    char tmprr[5][10];
    double t[5];
    strcpy(tmp.name, "Маска");
    tmp.price = 10.5;
    tmp.count = 100;
    file = fopen("prct19.dat", "rb+");
    for (i = 0; i < N; i++) {
        strcpy(tmprr[i], product[i].name);
        tm[i] = product[i].count;
        t[i] = product[i].price;
    }
    for (j = 0, i = 0; j < (N + 5), i < N; j += 2, i++) {
        strcpy(product[j].name, tmprr[i]);
        product[j].count = tm[i];
        product[j].price = t[i];
    }
    for (j = 1; j < (N + 5); j += 2) {
        strcpy(product[j].name, tmp.name);
        product[j].count = tmp.count;
        product[j].price = tmp.price;
    }
    for (i = 0; i < (N + 5); i++) {
        printf("\n%s %d %.2lf", product[i].name, product[i].count, product[i].price);
        fwrite(&product[i], sizeof(struct product), 1, file);
    }
    fclose(file);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int i;
    for (i = 0; i < N; i++) {
        printf("Наименование товара:\n");
        scanf("%s", product[i].name);
        printf("Количество товара:\n");
        scanf("%d", &product[i].count);
        printf("Цена товара:\n");
        scanf("%lf", &product[i].price);
    }
    FILE *file = fopen("prct19.dat", "wb");
    fwrite(product, sizeof(struct product), N, file);
    fclose(file);
    system("pause");
    change(file, product);
    system("pause");
    trash(file, product);
    return 0;
}
