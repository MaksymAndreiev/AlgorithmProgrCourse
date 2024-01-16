#include <stdio.h>
#include <string.h>
#include <windows.h>

typedef struct Node {
    int num, size;
    struct Node *next;
    struct Node *prev;
    struct Node *head;
    struct Node *tail;
} Node;

Node *createDblLinkedList() {
    Node *tmp = (Node *) malloc(sizeof(Node));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
    return tmp;
}

Node *getNth(Node *list, int index) {
    Node *tmp = list->head;
    int i = 0;
    while (tmp && i < index) {
        tmp = tmp->next;
        i++;
    }
    return tmp;
}

int getIndex(Node *list, int data) {
    Node *tmp = list->head;
    int index = 0;
    while (tmp->num != data) {
        index++;
        tmp = tmp->next;
    }
    return index;
}

void pushFront(Node *list, int data) {
    Node *tmp = (Node *) malloc(sizeof(Node));
    if (tmp == NULL) {
        exit(1);
    }
    tmp->num = data;
    tmp->next = list->head;
    tmp->prev = NULL;
    if (list->head) {
        list->head->prev = tmp;
    }
    list->head = tmp;

    if (list->tail == NULL) {
        list->tail = tmp;
    }
    list->size++;
}

void pushBack(Node *list, int data) {
    Node *tmp = (Node *) malloc(sizeof(Node));
    if (tmp == NULL) {
        exit(3);
    }
    tmp->num = data;
    tmp->next = NULL;
    tmp->prev = list->tail;
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;

    if (list->head == NULL) {
        list->head = tmp;
    }
    list->size++;
}

int deleteNth(Node *list, int index) {
    Node *elm = NULL;
    int tmp;
    elm = getNth(list, index);
    if (elm == NULL) {
        exit(5);
    }
    if (elm->prev) {
        elm->prev->next = elm->next;
    }
    if (elm->next) {
        elm->next->prev = elm->prev;
    }
    tmp = elm->num;
    if (!elm->prev) {
        list->head = elm->next;
    }
    if (!elm->next) {
        list->tail = elm->prev;
    }
    free(elm);
    list->size--;
    return tmp;
}

Node *swap(Node *tmp1, Node *tmp2, Node *list) {
    Node *prev1, *prev2, *next1, *next2;
    prev1 = tmp1->prev;
    prev2 = tmp2->prev;
    next1 = tmp1->next;
    next2 = tmp2->next;
    if (tmp2 == next1) {
        tmp2->next = tmp1;
        tmp2->prev = prev1;
        tmp1->next = next2;
        tmp1->prev = tmp2;
        if (next2 != NULL) {
            next2->prev = tmp1;
        }
        if (tmp1 != list->head) {
            prev1->next = tmp2;
        }
    } else if (tmp1 == next2) {
        tmp1->next = tmp2;
        tmp1->prev = prev2;
        tmp2->next = next1;
        tmp2->prev = tmp1;
        if (next1 != NULL) {
            next1->prev = tmp2;
        }
        if (tmp2 != list->head) {
            prev2->next = tmp1;
        }
    } else {
        if (tmp1 != list->head) {
            prev1->next = tmp2;
        }
        tmp2->next = next1;
        if (tmp2 != list->head) {
            prev2->next = tmp1;
        }
        tmp1->next = next2;
        tmp2->prev = prev1;
        if (next2 != NULL) {
            next2->prev = tmp1;
        }
        tmp1->prev = prev2;
        if (next1 != NULL) {
            next1->prev = tmp2;
        }
    }
    /*if(tmp1==list->head){

    }
    if(tmp2==list->head){
        list->head=tmp1;
    }*/
    return (list);
}

void printDblNodeHead(Node *list) {
    Node *tmp = list->head;
    while (tmp) {
        printf("%d ", tmp->num);
        tmp = tmp->next;
    }
    printf("\n");
}

void printDblNodeTail(Node *list) {
    Node *tmp = list->tail;
    while (tmp) {
        printf("%d ", tmp->num);
        tmp = tmp->prev;
    }
    printf("\n");
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Node *list = createDblLinkedList();
    int p, del, n, idx, n1, n2;
    while (1) {
        printf("1)добавить элемент в список\n2)поменять местами два выбранных элемента\n3)удалить элемент в списке\n4)печать списка от головы к хвосту\n5)печать списка от хвоста к голове\n6)выход\n");
        scanf("%d", &p);
        switch (p) {
            case 1:
                printf("1)в начало\n2)в конец\n");
                scanf("%d", &p);
                printf("Введите элемент: \n");
                scanf("%d", &n);
                switch (p) {
                    case 1:
                        pushFront(list, n);
                        break;
                    case 2:
                        pushBack(list, n);
                        break;
                }
                break;
            case 2:
                printf("Введите 2 элемента:\n");
                scanf("%d", &n1);
                Node *tmp1 = getNth(list, getIndex(list, n1));
                scanf("%d", &n2);
                Node *tmp2 = getNth(list, getIndex(list, n2));
                if (tmp1 == list->head || tmp2 == list->head) {
                    printf("Не трогать голову.");
                }
                list = swap(tmp1, tmp2, list);
                break;
            case 3:
                printf("1)до выбранного\n2)после выбранного\n");
                scanf("%d", &p);
                printf("Введите элемент: \n");
                scanf("%d", &n);
                switch (p) {
                    case 1:
                        idx = getIndex(list, n);
                        if (idx == 0) {
                            printf("Нет элемента перед первым.\n");
                            break;
                        } else {
                            del = deleteNth(list, idx - 1);
                            printf("Удалили: %d\n", del);
                        }
                        break;
                    case 2:
                        idx = getIndex(list, n);
                        if (idx == list->size - 1) {
                            printf("Нет элемента после последнего\n");
                            break;
                        } else {
                            del = deleteNth(list, idx + 1);
                            printf("Удалили: %d\n", del);
                        }
                        break;
                }
                break;
            case 4:
                printDblNodeHead(list);
                break;
            case 5:
                printDblNodeTail(list);
                break;
            case 6:
                return 1;
        }
    }
    return 0;
}
