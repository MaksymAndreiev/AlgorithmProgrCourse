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

void adding(group *student, int N, FILE *file, int *p) {
    int i, j;
    int cd = 0, cm = 0, cy = 0, t; //cd, cm, cy- идентификаторы ошибок в дате. Если ошибка есть, то +1, если нет, то -1. Если ошибок более чем 0, то перезаписываем
    char tmp[25];
    float tt;
    student = (group *) realloc(student, sizeof(group) * N);
    file = fopen("group.bin", "ab");
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
            printf("Эта особь слишком мала чтобы она поступила в университет.\n");
        } else if (student[i].data.year < 135) {
            cy++;
            printf("Прообразом университетов ранее были атенеи в Древнем Риме. Первый атеней был построен в 135 году. Поэтому студентов ранее быть не может.\n");
        } else {
            cy--;
        }
        while ((cd > 0) || (cm > 0) || (cy > 0)) {
            printf("Дата рождения:\n");
            scanf("%d.%d.%d", &student[i].data.day, &student[i].data.month, &student[i].data.year);
            cd = cm = cy = 0;
            goto here;
        }
        printf("Средняя успеваемость:\n");
        scanf("%f", &student[i].mark);
        while (student[i].mark > 100) {
            printf("Успеваемость в пределах от 0 до 100. Еще раз:\n");
            scanf("%f", &student[i].mark);
        }
        p[i] = 1; //это массив идентификаторов. Таким образом я сообщаю, что новый студент добавлен. Смотрите далее в функции категорий
    }
    for (i = N - 1; i < N; i++) {
        fprintf(file, "%s %s %s %02d %02d %04d %f\n", student[i].surname, student[i].name, student[i].patronymic,
                student[i].data.day, student[i].data.month, student[i].data.year, student[i].mark);
    }
    fclose(file);
    file = file = fopen("group.bin", "wb");
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
    for (i = 0; i < N; i++) {
        fprintf(file, "%s %s %s %02d %02d %04d %f\n", student[i].surname, student[i].name, student[i].patronymic,
                student[i].data.day, student[i].data.month, student[i].data.year, student[i].mark);
    }
    fflush(file);
    fclose(file);
}

void search1(group *student, int N, FILE *file) {
    int i, c = 0;
    char sur[25];
    file = fopen("group.bin", "rb");
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
    fclose(file);
}

void search2(group *student, int N, FILE *file) {
    int i, ot, doo, c = 0;
    file = fopen("group.bin", "rb");
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
    fclose(file);
}

void search3(group *student, int N, FILE *file) {
    int i, dd, mm, c = 0;
    file = fopen("group.bin", "rb");
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
    fclose(file);
}

void searching(group *student, int N, FILE *file) {
    int i, num;
    printf("1. По фамилии.\n2. По диапазону успеваемости.\n3. По дате рождения.\n");
    scanf("%d", &num);
    switch (num) {
        case 1:
            search1(student, N, file);
            break;
        case 2:
            search2(student, N, file);
            break;
        case 3:
            search3(student, N, file);
            break;
    }
}

void printing(group *student, int N, FILE *file) {
    int i;
    file = fopen("group.bin", "rb");
    if (N != 0) {
        printf("N\t        Фамилия\t            Имя\t            Отчeство\tДата рождения\tУспеваемость\n");
        for (i = 0; i < N; i++) {
            fscanf(file, "%s %s %s %d %d %d %f", &student[i].surname, &student[i].name, &student[i].patronymic,
                   &student[i].data.day, &student[i].data.month, &student[i].data.year, &student[i].mark);
            printf("%d\t%15s\t%15s\t%20s\t%02d.%02d.%04d\t%.2f\n", i + 1, student[i].surname, student[i].name,
                   student[i].patronymic, student[i].data.day, student[i].data.month, student[i].data.year,
                   student[i].mark);
        }
    } else {
        printf("Пусто\n");
    }
    fclose(file);
}

int number_before(FILE *file) { //считаю сколько уже введено студентов
    int N = 0;
    file = fopen("group.bin", "rb");
    while (fscanf(file, "%*[^\n]%*c") != EOF) {
        N++;
    }
    fclose(file);
    return N;
}

int number_category1(FILE *category1) { //тот же принцип. Считаю сколько уже студентов находится в данной категории
    int n = 0;
    category1 = fopen("category1.bin", "rb");
    while (fscanf(category1, "%*[^\n]%*c") != EOF) {
        n++;
    }
    fclose(category1);
    return n;
}

int number_category2(FILE *category2) {
    int n = 0;
    category2 = fopen("category2.bin", "rb");
    while (fscanf(category2, "%*[^\n]%*c") != EOF) {
        n++;
    }
    fclose(category2);
    return n;
}

int number_category3(FILE *category3) {
    int n = 0;
    category3 = fopen("category3.bin", "rb");
    while (fscanf(category3, "%*[^\n]%*c") != EOF) {
        n++;
    }
    fclose(category3);
    return n;
}

void deleting(group *student, int N, int t, FILE *file) {
    int i, temp;
    float tt;
    char tmp[25];
    file = fopen("group.bin", "wb");
    for (i = 0; i <= N; i++) {
        fscanf(file, "%s %s %s %d %d %d %f", &student[i].surname, &student[i].name, &student[i].patronymic,
               &student[i].data.day, &student[i].data.month, &student[i].data.year, &student[i].mark);
    }
    for (i = 0; i <= N; i++) {
        if (i != (t - 1)) { //просто записываю все, кроме удаляемого
            fprintf(file, "%s %s %s %02d %02d %04d %f\n", student[i].surname, student[i].name, student[i].patronymic,
                    student[i].data.day, student[i].data.month, student[i].data.year, student[i].mark);
        }
    }
    student = (group *) realloc(student, sizeof(group) * N);
    fflush(file);
    fclose(file);
}

void categoryone(group *student, int nc1, FILE *category1) {
    category1 = fopen("category1.bin", "rb");
    int i;
    fflush(category1);
    for (i = 0; i < nc1; i++) {
        fscanf(category1, "%s %s %s %d %d %d %f", &student[i].surname, &student[i].name, &student[i].patronymic,
               &student[i].data.day, &student[i].data.month, &student[i].data.year, &student[i].mark);
        printf("%d\t%15s\t%15s\t%20s\t%02d.%02d.%04d\t%.2f\n", i + 1, student[i].surname, student[i].name,
               student[i].patronymic, student[i].data.day, student[i].data.month, student[i].data.year,
               student[i].mark);
    }
    fclose(category1);
}

void categorytwo(group *student, int nc2, FILE *category2) {
    int i;
    category2 = fopen("category2.bin", "rb");
    fflush(category2);
    for (i = 0; i < nc2; i++) {
        fscanf(category2, "%s %s %s %d %d %d %f", &student[i].surname, &student[i].name, &student[i].patronymic,
               &student[i].data.day, &student[i].data.month, &student[i].data.year, &student[i].mark);
        printf("%d\t%15s\t%15s\t%20s\t%02d.%02d.%04d\t%.2f\n", i + 1, student[i].surname, student[i].name,
               student[i].patronymic, student[i].data.day, student[i].data.month, student[i].data.year,
               student[i].mark);
    }
    fclose(category2);
}

void categorythree(group *student, int nc3, FILE *category3) {
    int i;
    category3 = fopen("category3.bin", "rb");
    fflush(category3);
    for (i = 0; i < nc3; i++) {
        fscanf(category3, "%s %s %s %d %d %d %f", &student[i].surname, &student[i].name, &student[i].patronymic,
               &student[i].data.day, &student[i].data.month, &student[i].data.year, &student[i].mark);
        printf("%d\t%15s\t%15s\t%20s\t%02d.%02d.%04d\t%.2f\n", i + 1, student[i].surname, student[i].name,
               student[i].patronymic, student[i].data.day, student[i].data.month, student[i].data.year,
               student[i].mark);
    }
    fclose(category3);
}

void category(group *student, int N, FILE *file, int nc1, int nc2, int nc3, FILE *category1, FILE *category2,
              FILE *category3, int *p) {
    int i, num;
    file = fopen("group.bin", "rb");
    category1 = fopen("category1.bin", "wb");
    category2 = fopen("category2.bin", "wb");
    category3 = fopen("category3.bin", "wb");
    for (i = 0; i < N; i++) {
        fscanf(file, "%s %s %s %d %d %d %f", &student[i].surname, &student[i].name, &student[i].patronymic,
               &student[i].data.day, &student[i].data.month, &student[i].data.year, &student[i].mark);
        if ((student[i].mark >= 70) && (student[i].mark <= 100)) {
            fprintf(category1, "%s %s %s %02d %02d %04d %f\n", student[i].surname, student[i].name,
                    student[i].patronymic, student[i].data.day, student[i].data.month, student[i].data.year,
                    student[i].mark);
            if (p[i] == 1) { //а вот зачем нужен массив идентификаторов: я спрашиваю у массива добавлен ли студент
                nc1 += 1;
            }
        }
        if ((student[i].mark >= 50) && (student[i].mark < 70)) {
            fprintf(category2, "%s %s %s %02d %02d %04d %f\n", student[i].surname, student[i].name,
                    student[i].patronymic, student[i].data.day, student[i].data.month, student[i].data.year,
                    student[i].mark);
            if (p[i] == 1) { //если добавлен, то я увеличиваю количество элементов именно этой категории
                nc2 += 1;
            }
        }
        if ((student[i].mark >= 0) && (student[i].mark < 50)) {
            fprintf(category3, "%s %s %s %02d %02d %04d %f\n", student[i].surname, student[i].name,
                    student[i].patronymic, student[i].data.day, student[i].data.month, student[i].data.year,
                    student[i].mark);
            if (p[i] == 1) { //может есть вариант проще, но я додумался только до этого
                nc3 += 1;
            }
        }
    }
    fclose(file);
    fclose(category1);
    fclose(category2);
    fclose(category3);
    printf("Вывести студентов:\n1. С высоким баллом.\n2. С низким баллом.\n3. Без зачета.\n");
    scanf("%d", &num);
    printf("N\t        Фамилия\t            Имя\t            Отчeство\tДата рождения\tУспеваемость\n");
    switch (num) {
        case 1:
            categoryone(student, nc1, category1);
            break;
        case 2:
            categorytwo(student, nc2, category2);
            break;
        case 3:
            categorythree(student, nc3, category3);
            break;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FILE *file;
    FILE *category1;
    FILE *category2;
    FILE *category3;
    int n, N = number_before(file), t;
    int p[N];
    group *student;
    student = (group *) malloc(N * sizeof(group));
    int nc1 = number_category1(category1), nc2 = number_category2(category2), nc3 = number_category3(category3);
    while (1) {
        printf("1. Добавить студента.\n2. Поиск студента.\n3. Удаление студента.\n4. Классификация по категориям\n5. Печать группы.\n6. Выход\n");
        scanf("%d", &n);
        switch (n) {
            case 1:
                if (N == 0) {
                    student = (group *) malloc(N * sizeof(group));
                }
                adding(student, N += 1, file, p);
                break;
            case 2:
                searching(student, N, file);
                break;
            case 3:
                printf("Введите номер студента, который будет исключен:\n");
                scanf("%d", &t);
                if (t > N) {
                    printf("Нет такого студента\n");
                }
                deleting(student, N -= 1, t, file);
                break;
            case 4:
                category(student, N, file, nc1, nc2, nc3, category1, category2, category3, p);
                break;
            case 5:
                printing(student, N, file);
                break;
            case 6:
                return 1;
        }
    }
    return 0;
}
