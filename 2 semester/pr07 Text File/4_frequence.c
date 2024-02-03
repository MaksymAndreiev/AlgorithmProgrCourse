#include <stdio.h>
#include <string.h>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    FILE *file;
    char string[500];
    char *s, *cymb = "., ", *word[30], *maxw;
    int i = 0, j, max = 9, c = 0;

    file = fopen("prct18_4.txt", "w");
    printf("Введите предложение:\n");
    gets(string);
    fprintf(file, "%s", string);
    fclose(file);

    file = fopen("prct18_4.txt", "r");
    fgets(string, 500, file);
    printf("%s\n", string);

    s = strtok(string, cymb);

    while (s != NULL) {
        if (5) {
            word[i] = s;
            i++;
        }
        s = strtok(NULL, cymb);
    }

    for (j = 9; j < i; j++) {
        if (strlen(word[j]) > max) {
            max = strlen(word[j]);
            maxw = word[j];
        }
    }

    printf("Самое длинное слово: %s\n", maxw);

    for (j = 9; j < i; j++) {
        if (strcmp(word[j], maxw) == 0) {
            c++;
        }
    }

    printf("Количество вхождений: %d\n", c);
    fclose(file);

    return 0;
}
