#include <stdio.h>
#include <string.h>
#include <windows.h>

typedef struct list {
    int num;
    struct list *next;
} list;

list *getNth(list *head, int n) {
    int counter = 0;
    while (counter < n && head) {
        head = head->next;
        counter++;
    }
    return head;
}

list *addstart(list *head, int n) {
    list *tmp = (list *) malloc(sizeof(list));
    tmp->num = n;
    tmp->next = head;
    return tmp;
}

void addend(list *head, int n) {
    list *tmp = (list *) malloc(sizeof(list));
    tmp->num = n;
    tmp->next = NULL;
    list *p = head;
    if (p == NULL) {
        head = tmp;
    } else {
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = tmp;
    }
}

list *addset(list *head, int idx, int n) {
    int i = 0;
    list *p = head;
    while ((i < idx - 1) && p->next != NULL) {
        p = p->next;
        i++;
    }
    list *tmp = (list *) malloc(sizeof(list));
    tmp->num = n;
    if (head->next) {
        tmp->next = p->next;
    } else {
        tmp->next = NULL;
    }
    p->next = tmp;
    return head;
}

void search(list *head) {
    int i, t, c = 0;
    printf("Что вы хотите найти:\n");
    scanf("%d", &t);
    while (head) {
        if (t == head->num) {
            c++;
            printf("Нашел: %d\n", head->num);
            break;
        }
        head = head->next;
    }
    if (c == 0) {
        printf("Не нашел\n");
    }
}

int check(list *head, int n) {
    list *tmp = head;
    if (tmp == NULL) {
        return 0;
    } else {
        while (tmp != NULL) {
            if (n == tmp->num) {
                return 1;
            }
            tmp = tmp->next;
        }
    }
    return 0;
}

int idx(list *head, int n) {
    list *tmp = head;
    int i = 0;
    if (tmp == NULL) {
        return 0;
    } else {
        while (tmp != NULL) {
            i++;
            if (n == tmp->num) {
                return i;
            }
            tmp = tmp->next;
        }
    }
}

void print(list *head) {
    list *tmp = head;
    while (tmp != NULL) {
        printf("%d ", tmp->num);
        tmp = tmp->next;
    }
    printf("\n");
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int p, n, tmpn;
    list *head = NULL, *ptr;
    while (1) {
        printf("1)добавление нового значения в начало списка\n2)добавление нового значения в конец списка\n3)добавление нового значения после указанного значения в списке\n4)печать всех узлов списка\n5)поиск значения в списке\n6)выход\n");
        scanf("%d", &p);
        switch (p) {
            case 1:
                printf("Новое значение:\n");
                scanf("%d", &n);
                if (check(head, n) == 1) {
                    printf("повторение значений в списке запрещено\n");
                } else {
                    head = addstart(head, n);
                }
                break;
            case 2:
                printf("Новое значение:\n");
                scanf("%d", &n);
                if (check(head, n) == 1) {
                    printf("повторение значений в списке запрещено\n");
                } else {
                    addend(head, n);
                }
                break;
            case 3:
                printf("Значение, после которого надо добавить новoe:\n");
                scanf("%d", &tmpn);
                if (check(head, tmpn) == 0) {
                    printf("нет элемента\n");
                } else {
                    printf("Новое значение:\n");
                    scanf("%d", &n);
                    if (check(head, n) == 1) {
                        printf("повторение значений в списке запрещено\n");
                    } else {
                        head = addset(head, idx(head, tmpn), n);
                    }
                }
                break;
            case 4:
                print(head);
                break;
            case 5:
                search(head);
                break;
            case 6:
                return 1;
        }
    }
}
