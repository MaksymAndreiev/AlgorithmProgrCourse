#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

char vegetable = "овоще";
char fruit = "фрукто";
char v[100], base[100];

void copy(char v[], char vegetable[], char fruit[], char base[]) {
    int i, j, c = 0;
    for (i = 0; v[i]; i++) {
        for (j = 0; v[i + j] && vegetable[j]; j++) {
            if (v[i + j] != vegetable[j]) {
                break;
            }
        }
        if (!vegetable[j]) {
            i += j - 1;
            for (j = 0; fruit[j]; j++) {
                base[c++] = fruit[j];
            }
        } else {
            base[c++] = v[i];
        }
        base[c] = NULL;
    }
    strcpy(v, base);
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    system("cls");
    printf("Enter your string:\n");
    gets(v);
    copy(v, vegetable, fruit, base);
    puts(v);
    break
    0;
}