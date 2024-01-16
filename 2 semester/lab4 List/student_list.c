#include <stdio.h>
#include <string.h>
#include <windows.h>

typedef struct group {
    char surname[30];
    char name[20];
    char patronymic[30];
    int age;
    float mark;
    struct group *next;
} group;

group *addstart(group *head, char *surname, char *name, char *patronymic, int age, float mark) {
    group *tmp = (group *) malloc(sizeof(group));
    strcpy(tmp->surname, surname);
    strcpy(tmp->name, name);
    strcpy(tmp->patronymic, patronymic);
    tmp->age = age;
    tmp->mark = mark;
    tmp->next = head;
    return (tmp);
}

void addend(group *head, char *surname, char *name, char *patronymic, int age, float mark) {
    group *tmp = (group *) malloc(sizeof(group));
    strcpy(tmp->surname, surname);
    strcpy(tmp->name, name);
    strcpy(tmp->patronymic, patronymic);
    tmp->age = age;
    tmp->mark = mark;
    tmp->next = NULL;
    group *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = tmp;
}

void addsurname(group *head) {
    int f = 0;
    char tmpsur[30];
    printf("Фамилия студента, после которого надо добавить нового:\n");
    scanf("%s", &tmpsur);
    group *p = (group *) malloc(sizeof(group));
    group *tmp = (group *) malloc(sizeof(group));
    p = head;
    while (head != NULL) {
        if (!strcmp(head->surname, tmpsur)) {
            f++;
            printf("Фамилия:\n");
            scanf("%s", &(tmp->surname));
            printf("Имя:\n");
            scanf("%s", &(tmp->name));
            printf("Отчество:\n");
            scanf("%s", &(tmp->patronymic));
            printf("Возраст:\n");
            scanf("%d", &(tmp->age));
            while (tmp->age > (2020 - 11 - 5)) {
                printf("Эта особь слишком мала чтобы она поступила в университет. Еще раз:\n");
                scanf("%d", &(tmp->age));
            }
            printf("Средняя успеваемость:\n");
            scanf("%f", &(tmp->mark));
            while (tmp->mark > 100) {
                printf("Успеваемость в пределах от 0 до 100. Еще раз:\n");
                scanf("%f", &(tmp->mark));
            }
            tmp->next = head->next;
            head->next = tmp;
            break;
        } else {
            head = head->next;
        }
    }
    if (f == 0) {
        printf("Не найдено. Кто это вообще такой?\n");
    }
    head = p;
}

void sort(group *head) {
    group *p = head, *t = head;
    char tmp[30];
    int tmpage;
    float tmpmark;
    while (head != NULL) {
        while (head->next != NULL) {
            if (strcmp(head->surname, head->next->surname) > 0) {
                strcpy(tmp, head->surname);
                strcpy(head->surname, head->next->surname);
                strcpy(head->next->surname, tmp);
                strcpy(tmp, head->name);
                strcpy(head->name, head->next->name);
                strcpy(head->next->name, tmp);
                strcpy(tmp, head->patronymic);
                strcpy(head->patronymic, head->next->patronymic);
                strcpy(head->next->patronymic, tmp);
                tmpage = head->age;
                head->age = head->next->age;
                head->next->age = tmpage;
                tmpmark = head->mark;
                head->mark = head->next->mark;
                head->next->mark = tmpmark;
            }
            head = head->next;
        }
        head = p;
        head = head->next;
        p = head;
    }
    head = t;
}

group *dlt(group *head) {
    group *tmp = (group *) malloc(sizeof(group));
    tmp = head;
    char surname[30];
    printf("Фамилия студента, которого надо удалить:\n");
    scanf("%s", &surname);
    while (head != NULL) {
        if (!strcmp(head->surname, surname)) {
            if (head == tmp) {
                tmp = head->next;
            } else {
                group *p = (group *) malloc(sizeof(group));
                p = tmp;
                while (p->next != head) {
                    p = p->next;
                }
                p->next = head->next;
            }
        }
        head = head->next;
    }
    head = tmp;
    return tmp;
}

void search(group *head) {
    int c = 0;
    char sur[25];
    group *p;
    p = head;
    printf("Фамилия:\n");
    scanf("%s", &sur);
    while (p) {
        if (strcmp(sur, p->surname) == 0) {
            c++;
            printf("%25s%20s%20s\t %2d\t    %2.2f\n", p->surname, p->name, p->patronymic, p->age, p->mark);
        }
        p = p->next;
    }
    if (c == 0) {
        printf("Не найдено. Кто это вообще такой?\n");
    }
}

void printctg(group *head) {
    group *p = head;
    int a = 0, b = 0, c = 0, d = 0;
    printf("Отлично (90-100):\n");
    while (head != NULL) {
        if (head->mark >= 90) {
            printf("%25s%20s%20s\t %2d\t    %2.2f\n", head->surname, head->name, head->patronymic, head->age,
                   head->mark);
            a++;
        }
        head = head->next;
    }
    if (a == 0) {
        printf("Список пуст.\n");
    }
    head = p;
    printf("Хорошо (70-89):\n");
    while (head != NULL) {
        if ((head->mark >= 70) && (head->mark < 90)) {
            printf("%25s%20s%20s\t %2d\t    %2.2f\n", head->surname, head->name, head->patronymic, head->age,
                   head->mark);
            b++;
        }
        head = head->next;
    }
    if (b == 0) {
        printf("Список пуст.\n");
    }
    head = p;
    printf("Удовлетворительно (50-69):\n");
    while (head != NULL) {
        if ((head->mark >= 50) && (head->mark < 70)) {
            printf("%25s%20s%20s\t %2d\t    %2.2f\n", head->surname, head->name, head->patronymic, head->age,
                   head->mark);
            c++;
        }
        head = head->next;
    }
    if (c == 0) {
        printf("Список пуст.\n");
    }
    head = p;
    printf("Неудовлетворительно (0-49):\n");
    while (head != NULL) {
        if ((head->mark >= 0) && (head->mark < 50)) {
            printf("%25s%20s%20s\t %2d\t    %2.2f\n", head->surname, head->name, head->patronymic, head->age,
                   head->mark);
            d++;
        }
        head = head->next;
    }
    if (d == 0) {
        printf("Список пуст.\n");
    }
}

void printing(group *head) {
    group *p = head;
    printf("          Фамилия        |\t   Имя        |\t    Отчeство       |Возраст|Успеваемость|\n");
    while (p != NULL) {
        printf("%25s|%20s|%20s|\t %2d|\t   %2.2f|\n", p->surname, p->name, p->patronymic, p->age, p->mark);
        p = p->next;
    }
    printf("\n");
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int p, age, c = 0;
    char name[20];
    char surname[30], tmpsur[30];
    char patronymic[25];
    float mark;
    group *head = NULL;
    while (1) {
        printf("1. Просмотреть группу\n2. Добавить студента\n3. Поиск студентов\n4. Вывод по успеваемости\n5. Удаление студента\n6. Выход\n");
        scanf("%d", &p);
        switch (p) {
            case 1:
                if (head == NULL) {
                    printf("Список пуст.\n");
                } else {
                    printf("1.Отсортировать 2.Оставить как есть\n");
                    scanf("%d", &p);
                    if (p == 1) {
                        sort(head);
                    }
                    printing(head);
                }
                break;
            case 2:
                printf("1. Добавление нового студента в начало списка\n2. Добавление нового студента в конце списка\n3. Добавление нового студента после указанного по фамилии студента\n");
                scanf("%d", &p);
                if (p != 3) {
                    printf("Фамилия:\n");
                    scanf("%s", &surname);
                    printf("Имя:\n");
                    scanf("%s", &name);
                    printf("Отчество:\n");
                    scanf("%s", &patronymic);
                    printf("Возраст:\n");
                    scanf("%d", &age);
                    while (age > (2020 - 11 - 5)) {
                        printf("Эта особь слишком мала чтобы она поступила в университет. Еще раз:\n");
                        scanf("%d", &age);
                    }
                    printf("Средняя успеваемость:\n");
                    scanf("%f", &mark);
                    while (mark > 100 || mark < 0) {
                        printf("Успеваемость в пределах от 0 до 100. Еще раз:\n");
                        scanf("%f", &mark);
                    }
                }
                switch (p) {
                    case 1:
                        head = addstart(head, surname, name, patronymic, age, mark);
                        break;
                    case 2:
                        if (head == NULL) {
                            head = addstart(head, surname, name, patronymic, age, mark);
                        } else {
                            addend(head, surname, name, patronymic, age, mark);
                        }
                        break;
                    case 3:
                        if (head == NULL) {
                            printf("Список пуст. Нет фамилий, чтобы добавить после них\n");
                        } else {
                            addsurname(head);
                        }
                        break;
                }
                break;
            case 3:
                search(head);
                break;
            case 4:
                printctg(head);
                break;
            case 5:
                head = dlt(head);
                break;
            case 6 :
                return 1;
        }
    }
}
