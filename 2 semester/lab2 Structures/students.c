#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct {
    char name[10];
    char surname[15];
    char patronymic[15];
    struct {
        int day;
        int month;
        int year;
    } data;
    float mark;
} group;

void deleting(group *student, int N, int t) {
    int i;
    for (i = t - 1; i < N; i++) {
        student[i] = student[i + 1];
    }
    student = (group *) realloc(student, sizeof(group) * N);
}

void adding(group *student, int N) {
    int i, j;
    int cd = 0, cm = 0, cy = 0, t;
    float tt;
    char tmp[15];
    student = (group *) realloc(student, sizeof(group) * N);
    for (i = N - 1; i < N; i++) {
        printf("Фамилия:\n");
        scanf("%s", &student[i].surname);
        printf("Имя:\n");
        scanf("%s", &student[i].name);
        printf("Отчество:\n");
        scanf("%s", &student[i].patronymic);
        printf("Дата рождения(в формате дд.мм.гггг):\n");
        scanf("%d.%d.%d", &student[i].data.day, &student[i].data.month, &student[i].data.year);
        here:
        if (student[i].data.month > 12) {
            cm++;
            printf("Не существует такого месяца\n");
        } else {
            cm--;
        }
        if ((student[i].data.month == 1) || (student[i].data.month == 3) || (student[i].data.month == 5) ||
            (student[i].data.month == 7) || (student[i].data.month == 8) || (student[i].data.month == 10) ||
            (student[i].data.month == 12)) {
            if (student[i].data.day > 31) {
                cd++;
                printf("Не существует более 31 дня в месяце!\n");
            } else {
                cd--;
            }
        } else if (student[i].data.month != 2) {
            if (student[i].data.day > 30) {
                cd++;
                printf("В этом месяце 30 дней\n");
            } else {
                cd--;
            }
        } else {
            if (student[i].data.year % 4 == 0) {
                if (student[i].data.month == 2) {
                    if (student[i].data.day > 29) {
                        cd++;
                        printf("В високосном году в феврале только 29 дней!\n");
                    } else {
                        cd--;
                    }
                }
            } else {
                if (student[i].data.month == 2) {
                    if (student[i].data.day > 28) {
                        cd++;
                        printf("В феврале 28 дней!!!\n");
                    } else {
                        cd--;
                    }
                }
            }
        }
        if (student[i].data.year > (2020 - 11 - 5)) {
            cy++;
            printf("Не пытайтесь меня обмануть\n");
        } else {
            cy--;
        }
        while ((cd > 0) || (cm > 0) || (cy > 0)) {
            printf("Дата рождения:\n");
            scanf("%d.%d.%d", &student[i].data.day, &student[i].data.month, &student[i].data.year);
            goto here;
        }
        printf("Средняя успеваемость:\n");
        scanf("%f", &student[i].mark);
        while (student[i].mark > 100) {
            printf("Успеваемость в пределах от 0 до 100. Еще раз:\n");
            scanf("%f", &student[i].mark);
        }
    }
    for (i = 1; i < N; i++) {
        for (j = 0; j < N - i; j++) {
            if (strcmp(student[j].surname, student[j + 1].surname) > 0) {
                strcpy(tmp, student[j].surname);
                strcpy(student[j].surname, student[j + 1].surname);
                strcpy(student[j + 1].surname, tmp);
                strcpy(tmp, student[j].name);
                strcpy(student[j].name, student[j + 1].name);
                strcpy(student[j + 1].name, tmp);
                strcpy(tmp, student[j].patronymic);
                strcpy(student[j].patronymic, student[j + 1].patronymic);
                strcpy(student[j + 1].patronymic, tmp);
                t = student[j].data.day;
                student[j].data.day = student[j + 1].data.day;
                student[j + 1].data.day = t;
                t = student[j].data.month;
                student[j].data.month = student[j + 1].data.month;
                student[j + 1].data.month = t;
                t = student[j].data.year;
                student[j].data.year = student[j + 1].data.year;
                student[j + 1].data.year = t;
                tt = student[j].mark;
                student[j].mark = student[j + 1].mark;
                student[j + 1].mark = tt;
            }
        }

    }
}

void search1(group *student, int N) {
    int i, c = 0;
    char sur[15];
    printf("Фамилия:\n");
    scanf("%s", &sur);
    printf("N\t        Фамилия\t            Имя\t            Отчeство\tДата рождения\tУспеваемость\n");
    for (i = 0; i < N; i++) {
        if (strcmp(sur, student[i].surname) == 0) {
            c++;
            printf("%d\t%15s\t%15s\t%20s\t%02d.%02d.%04d\t%.2f\n", i + 1, student[i].surname, student[i].name,
                   student[i].patronymic, student[i].data.day, student[i].data.month, student[i].data.year,
                   student[i].mark);
        }
    }
    if (c == 0) {
        printf("Не найдено. Кто это вообще такой?\n");
    }
}

void search2(group *student, int N) {
    int i, ot, doo, c = 0;
    printf("Введите диапазон успеваемости от и до:\n");
    scanf("%d %d", &ot, &doo);
    printf("N\t        Фамилия\t            Имя\t            Отчeство\tДата рождения\tУспеваемость\n");
    for (i = 0; i < N; i++) {
        if ((student[i].mark >= ot) && (student[i].mark <= doo)) {
            c++;
            printf("%d\t%15s\t%15s\t%20s\t%02d.%02d.%04d\t%.2f\n", i + 1, student[i].surname, student[i].name,
                   student[i].patronymic, student[i].data.day, student[i].data.month, student[i].data.year,
                   student[i].mark);
        }
    }
    if (c == 0) {
        printf("Не найдено.\n");
    }
}

void search3(group *student, int N) {
    int i, dd, mm, c = 0;
    printf("Дата рождения(в формате дд.мм):\n");
    scanf("%d.%d", &dd, &mm);
    printf("N\t        Фамилия\t            Имя\t            Отчeство\tДата рождения\tУспеваемость\n");
    for (i = 0; i < N; i++) {
        if ((dd == student[i].data.day) && (mm == student[i].data.month)) {
            c++;
            printf("%d\t%15s\t%15s\t%20s\t%02d.%02d.%04d\t%.2f\n", i + 1, student[i].surname, student[i].name,
                   student[i].patronymic, student[i].data.day, student[i].data.month, student[i].data.year,
                   student[i].mark);
        }
    }
    if (c == 0) {
        printf("Не найдено.\n");
    }
}

void searching(group *student, int N) {
    int i, n;
    printf("1. По фамилии.\n2. По диапазону успеваемости.\n3. По дате рождения.\n");
    scanf("%d", &n);
    switch (n) {
        case 1:
            search1(student, N);
            break;
        case 2:
            search2(student, N);
            break;
        case 3:
            search3(student, N);
            break;
    }
}

void printing(group *student, int N) {
    int i, n = 15;
    printf("N\t        Фамилия\t            Имя\t            Отчeство\tДата рождения\tУспеваемость\n");
    if (N == 0) {
        printf("Пусто\n");
    }
    for (i = 0; i < N; i++) {
        printf("%d\t%15s\t%15s\t%20s\t%02d.%02d.%04d\t%.2f\n", i + 1, student[i].surname, student[i].name,
               student[i].patronymic, student[i].data.day, student[i].data.month, student[i].data.year,
               student[i].mark);
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int p, N = 0, t;
    group *student;
    student = (group *) malloc(N * sizeof(group));
    while (1) {
        printf("1. Добавить студента.\n2. Поиск студента.\n3. Удаление студента.\n4. Печать группы.\n5. Выход\n");
        scanf("%d", &p);
        switch (p) {
            case 1:
                if (N == 0) {
                    student = (group *) malloc(N * sizeof(group));
                }
                adding(student, N += 1);
                break;
            case 2:
                searching(student, N);
                break;
            case 3:
                printf("Введите номер студента, который будет исключен:\n");
                scanf("%d", &t);
                if (t > N) {
                    printf("Нет такого студента\n");
                }
                deleting(student, N -= 1, t);
                break;
            case 4:
                printing(student, N);
                break;
            case 5:
                return 1;
        }
    }
    return 0;
}
