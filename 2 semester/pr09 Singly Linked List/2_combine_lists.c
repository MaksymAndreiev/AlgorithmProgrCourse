#include <stdio.h>
#include <string.h>
#include <windows.h>

typedef struct list {
    int num;
    struct list *next;
} list;

void print(list *head) {
    list *tmp = head;
    while (tmp != NULL) {
        printf("%d ", tmp->num);
        tmp = tmp->next;
    }
    printf("\n");
}

void add(list **head, int n) {
    list *p = *head;
    list *tmp;
    tmp = (list *) malloc(sizeof(list));
    tmp->num = n;
    tmp->next = NULL;
    if (p == NULL) {
        *head = tmp;
    } else {
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = tmp;
    }
}

list *combine(list *one, list *two) {
    list *node, *tmp;
    tmp = node = NULL;
    while (one && two) {
        if (one->num <= two->num) {
            if (tmp == NULL) {
                tmp = node = one;
            } else {
                tmp = tmp->next = one;
            }
            one = one->next;
        } else {
            if (tmp == NULL) {
                tmp = node = two;
            } else {
                tmp = tmp->next = two;
            }
            two = two->next;
        }
    }
    if (one) {
        if (tmp == NULL) {
            node = one;
        } else {
            tmp->next = one;
        }
    } else {
        if (tmp == NULL) {
            node = two;
        } else {
            tmp->next = two;
        }
    }
    return (node);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int p, n;
    list *head1 = NULL;
    list *head2 = NULL;
    list *head = NULL;
    add(&head1, 3);
    add(&head1, 7);
    add(&head1, 10);
    add(&head1, 12);
    add(&head1, 14);
    add(&head2, 6);
    add(&head2, 9);
    add(&head2, 13);
    add(&head2, 17);
    printf("Список 1: ");
    print(head1);
    printf("Список 2: ");
    print(head2);
    head = combine(head1, head2);
    printf("Объединение: ");
    print(head);
    return 0;
}
