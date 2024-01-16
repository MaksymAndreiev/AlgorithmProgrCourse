#include <stdio.h>
#include <windows.h>

typedef struct Stack {
    int d;
    struct Stack *p;
} Stack;
typedef struct Queue {
    int d;
    struct Queue *p;
} Queue;

Stack *first(int d) {
    Stack *tmp = (Stack *) malloc(sizeof(Stack));
    tmp->d = d;
    tmp->p = 0;
    return tmp;
}

void push(Stack **top, int d) {
    Stack *pv = (Stack *) malloc(sizeof(Stack));
    pv->d = d;
    pv->p = *top;
    *top = pv;
}

int pop(Stack **top) {
    int temp = (*top)->d;
    Stack *pv = *top;
    (*top) = (*top)->p;
    free(pv);
    return temp;
}

void print(Stack *top) {
    Stack *q = top;
    while (q) {
        printf("%d ", q->d);
        q = q->p;
    }
    printf("\n");
}

Queue *firstq(int d) {
    Queue *pv = (Queue *) malloc(sizeof(Queue));
    pv->d = d;
    pv->p = 0;
    return pv;
}

void add(Queue **pend, int d) {
    Queue *pv = (Queue *) malloc(sizeof(Queue));
    pv->d = d;
    pv->p = 0;
    (*pend)->p = pv;
    *pend = pv;
}

int del(Queue **pbeg) {
    int temp = (*pbeg)->d;
    Queue *pv = *pbeg;
    *pbeg = (*pbeg)->p;
    free(pv);
    return temp;
}

void printq(Queue *pbeg) {
    while (pbeg) {
        printf("%d ", pbeg->d);
        pbeg = pbeg->p;
    }
    printf("\n");
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Stack *top = NULL;
    Queue *pbeg = NULL;
    Queue *pend = pbeg;
    int p, t;
    while (1) {
        printf("1. Вставить элемент в стек;\n2. Удалить элемент из стека\n3. Вставить элемент в очередь\n4. Удалить элемент из очереди\n5. Получить количество элементов\n6. Выйти\n");
        scanf("%d", &p);
        switch (p) {
            case 1:
                printf("Ввести число: ");
                scanf("%d", &t);
                if (top == NULL) {
                    top = first(t);
                } else {
                    push(&top, t);
                }
                break;
            case 2:
                printf("Удалили %d\n", pop(&top));
                break;
            case 3:
                printf("Ввести число:");
                scanf("%d", &t);
                if (pbeg == NULL) {
                    pbeg = firstq(t);
                    pend = pbeg;
                } else {
                    add(&pend, t);
                }
                break;
            case 4:
                printf("Удалили %d\n", del(&pbeg));
                break;
            case 5:
                printf("1. Стек\n2. Очередь\n");
                scanf("%d", &p);
                if (p == 1) {
                    print(top);
                } else if (p == 2) {
                    printq(pbeg);
                } else {
                    printf("error");
                    break;
                }
                break;
            case 6:
                return 1;
        }
    }
    return 0;
}
