#include <stdio.h>
#include <string.h>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    FILE *file;
    char string[500];
    char *s;

    file = fopen("prct18_3.txt", "r");
    fgets(string, 500, file);
    s = strtok(string, ".");

    while (s != NULL) {
        printf("%s.\n", s);
        printf("Символов: %d\n", strlen(s) + 1);
        s = strtok(NULL, ".");
    }

    fclose(file);

    return 0;
}
