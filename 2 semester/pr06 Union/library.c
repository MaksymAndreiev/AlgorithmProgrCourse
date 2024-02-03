#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct {
    char name[50];
    int year;
    int pages;
    union {
        struct {
            char author[36];
        } book;
        struct {
            char issue[38];
            int artical;
        } magazine;
    };
} library;

void enter(library *print, int N, int tmp) {
    int i, ch;
    print = (library *) realloc(print, sizeof(library) * N);
    printf("Выберите тип:\n1.Книга\n2.Журнал\n");
    scanf("%d", &ch);

    for (i = N - 1; i < N; i++) {
        printf("Название:\n");
        scanf("%s", &print[i].name);

        printf("Год:\n");
        scanf("%d", &print[i].year);

        while (print[i].year > 2026) {
            printf("Некорректный ввод. Пожалуйста, введите корректный год:\n");
            scanf("%d", &print[i].year);
        }

        printf("Количество страниц:\n");
        scanf("%d", &print[i].pages);

        while (print[i].pages < 0) {
            printf("Некорректный ввод. Введите положительное количество страниц:\n");
            scanf("%d", &print[i].pages);
        }
    }

    switch (ch) {
        case 1:
            for (i = N - 1; i < N; i++) {
                tmp[i] = 1;
                printf("Автор:\n");
                scanf("%s", &print[i].book.author);
            }
            break;
        case 2:
            for (i = N - 1; i < N; i++) {
                tmp[i] = 0;
                printf("Номер выпуска:\n");
                scanf("%s", &print[i].magazine.issue);

                printf("Количество статей:\n");
                scanf("%d", &print[i].magazine.artical);
            }

            while (print[i].magazine.artical < 0) {
                printf("Некорректный ввод. Введите положительное количество статей:\n");
                scanf("%d", &print[i].magazine.artical);
            }
            break;
    }
}

void printbook(library *print, int N, int tmp) {
    int i;
    printf(" Название\tГод издания\tКоличество страниц\tАвтор\n");

    for (i = 0; i < N; i++) {
        if (tmp[i] == 1) {
            printf("%s\t%d\t%d\t%s\n", print[i].name, print[i].year, print[i].pages, print[i].book.author);
        }
    }
}

void printmagazine(library *print, int N, int tmp) {
    int i;
    printf(" Название\tГод издания\tКоличество страниц\tНомер выпуска\tКоличество статей\n");

    for (i = 0; i < N; i++) {
        if (tmp[i] == 0) {
            printf("%s\t%d\t%d\t%s\t%d\n", print[i].name, print[i].year, print[i].pages, print[i].magazine.issue,
                   print[i].magazine.artical);
        }
    }
}

void counting(library *print, int N, int tmp) {
    int i, c = 0;

    for (i = 0; i < N; i++) {
        if (tmp[i] == 0) {
            c += print[i].magazine.artical;
        }
    }

    printf("Количество статей со всех журналов: %d\n", c);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int ch, N = 1, tmp[N];
    library *print;
    print = (library *) malloc(sizeof(library));

    while (1) {
        printf("1. Ввод информации.\n2. Вывод информации о книгах.\n3. Вывод информации о журналах.\n4. Подсчет (Темы? со всех журналов.\n5. Выход.\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                enter(print, N, tmp);
                break;
            case 2:
                printbook(print, N, tmp);
                break;
            case 3:
                printmagazine(print, N, tmp);
                break;
            case 4:
                counting(print, N, tmp);
                break;
            case 5:
                return 0;
        }
    }

    return 0;
}
