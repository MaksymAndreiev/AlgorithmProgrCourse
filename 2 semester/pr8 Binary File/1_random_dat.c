#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, number[10];
    FILE *file;
    file = fopen("file_in.dat", "wb");
    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        number[i] = rand() % 100;
        printf("%d ", number[i]);

    }
    fwrite(number, sizeof(int), 10, file);
    printf("\n");
    fclose(file);
    system("pause");
    file = fopen("file_in.dat", "rb");
    int max = 0, min = 100;
    int num;
    for (i = 0; i < 10; i++) {
        fread(&num, sizeof(int), 1, file);
        if (num > max) {
            max = num;
        }
        if (num < min) {
            min = num;
        }
    }
    printf("\nmax=%d min=%d", max, min);
    return 0;
}
