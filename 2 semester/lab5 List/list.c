#include <stdio.h>
#include <windows.h>

#define STACK_MAX_SIZE 5
#define MULTIPLIER 2
typedef struct Stack {
    int d;
    struct Stack *p;
} Stack;
typedef struct Stack_scnd {
    int *mas;
    int size;
    int maxsize;
} Stack_2;
typedef struct Queuemas {
    int *mas;
    int size, front, rear, maxsize;
} Queuemas;
typedef struct Queue {
    int d;
    struct Queue *p;
} Queue;

int mainMenu() {
    int p;
    printf("1.Стек - массив\n2.Стек - ОЛС\n3.Очередь - массив\n4.Очередь - ОЛС\n5.Выход\n");
    printf("Пункт меню: ");
    scanf("%d", &p);
    return p;
}

int addMenu() {
    int p;
    printf("1. Вставить\n2. Удалить\n3. Распечатать \n4. Показать верхний\n5. Очистить\n6. Проверить, пусто ли\n7. Выход из пункта\n");
    printf("Пункт подменю: ");
    scanf("%d", &p);
    return p;
}

Stack *first(int d) {
    Stack *tmp = (Stack *) malloc(sizeof(Stack));
    tmp->d = d;
    tmp->p = 0;
    return tmp;
}

Stack_2 *init(Stack_2 *top) {
    int i;
    top->size = 0;
    top->maxsize = STACK_MAX_SIZE;
    top->mas = (int *) malloc(top->maxsize * sizeof(int));
    for (i = 0; i < STACK_MAX_SIZE; i++) {
        top->mas[i] = 0;
    }
    return top;
}

Queue *firstq(int d) {
    Queue *pv = (Queue *) malloc(sizeof(Queue));
    pv->d = d;
    pv->p = 0;
    return pv;
}

Queuemas *initq(Queuemas *q) {
    int i;
    q->size = 0;
    q->maxsize = STACK_MAX_SIZE;
    q->front = q->rear = 0;
    q->mas = (int *) malloc(q->maxsize * sizeof(int));
    for (i = 0; i < STACK_MAX_SIZE; i++) {
        q->mas[i] = 0;
    }
    return q;
}

void resize(Stack_2 *top) {
    int i;
    int newmax = top->maxsize;
    newmax *= MULTIPLIER;
    top->mas = (int *) realloc(top->mas, newmax * sizeof(int));
    for (i = top->maxsize; i < newmax; i++) {
        top->mas[i] = 0;
    }
    top->maxsize = newmax;
}

void resz(Queuemas *q) {
    int i;
    int newmax = q->maxsize;
    newmax *= MULTIPLIER;
    q->mas = (int *) realloc(q->mas, newmax * sizeof(int));
    if (q->rear != q->maxsize) {
        for (i = 0; i < (q->maxsize - q->front); i++)
            q->mas[q->front + 5 + i] = q->mas[q->front + i];
    }
    q->front + 5;
    for (i = q->rear; i < q->rear + 5; i++) {
        q->mas[i] = 0;
    }
    q->maxsize = newmax;
}

void push(Stack **top, int d) {
    Stack *pv = (Stack *) malloc(sizeof(Stack));
    pv->d = d;
    pv->p = *top;
    *top = pv;
}

void push2(Stack_2 *top, int data) {
    if (top->size >= top->maxsize) {
        resize(top);
    }
    top->mas[top->size] = data;
    top->size++;
}

void add(Queue **pend, int d) {
    Queue *pv = (Queue *) malloc(sizeof(Queue));
    pv->d = d;
    pv->p = 0;
    (*pend)->p = pv;
    *pend = pv;
}

void addMas(Queuemas *q, int data) {
    int i;
    if (q->size == q->maxsize) {
        resz(q);
    } else if (q->rear == q->maxsize && q->rear != q->size) {
        q->rear = 0;
        while (q->rear < q->front) {
            if (q->mas[q->rear] == 0) {
                break;
            } else {
                q->rear++;
            }
        }
    }
    q->mas[q->rear] = data;
    q->rear++;
    q->size++;
}

int pop(Stack **top) {
    int temp = (*top)->d;
    Stack *pv = *top;
    (*top) = (*top)->p;
    free(pv);
    return temp;
}

int pop2(Stack_2 *top) {
    int elem;
    if ((top->size) > 0) {
        top->size--;
        elem = top->mas[top->size];
        top->mas[top->size] = 0;
        return elem;
    } else {
        printf("Стек пуст!\n");
        return 0;
    }
}

int del(Queue **pbeg) {
    int temp = (*pbeg)->d;
    Queue *pv = *pbeg;
    *pbeg = (*pbeg)->p;
    free(pv);
    return temp;
}

int delqmas(Queuemas *q) {
    int elem;
    if (q->front == q->rear && q->size == 0) {
        printf("Очередь пуста.\n");
        return 0;
    } else {
        elem = q->mas[q->front];
        q->mas[q->front] = 0;
        q->front++;
        q->size--;
        return elem;
    }
}

int getTop(Stack *top) {
    if (top != NULL) {
        return top->d;
    } else {
        printf("Стек пуст!\n");
        return 0;
    }
}

int getTop2(Stack_2 *top) {
    if ((top->size) > 0) {
        return top->mas[top->size - 1];
    } else {
        printf("Стек пуст!\n");
        return 0;
    }
}

int getTop4(Queue *pend) {
    if (pend != NULL) {
        return pend->d;
    } else {
        printf("Очередь пуст!\n");
        return 0;
    }
}

void deleteStack(Stack **top) {
    free(*top);
    *top = NULL;
    if (*top == NULL) {
        printf("Очищено\n");
    }
}

void deleteStack2(Stack_2 **top) {
    free(*top);
    *top = NULL;
    if (*top == NULL) {
        printf("Очищено\n");
    }
}

void deleteQueue(Queue **pbeg, Queue **pend) {
    free(*pbeg);
    free(*pend);
    *pbeg = *pend = NULL;
    if (*pbeg == NULL && *pend == NULL) {
        printf("Очищено\n");
    }
}

void deleteQueue2(Queuemas **q) {
    free(q);
    q = NULL;
    if (*q == NULL) {
        printf("Очищено\n");
    }
}

void print(Stack *top) {
    Stack *q = top;
    while (q) {
        printf("%d ", q->d);
        q = q->p;
    }
    printf("\n");
}

void printStack2(Stack_2 *top) {
    int i;
    for (i = 0; i < top->maxsize; i++) {
        printf("%d ", top->mas[i]);
    }
    printf("\n");
}

void printq(Queue *pbeg) {
    while (pbeg) {
        printf("%d ", pbeg->d);
        pbeg = pbeg->p;
    }
    printf("\n");
}

void printqmas(Queuemas *q) {
    int i;
    for (i = 0; i < q->maxsize; i++) {
        printf("%d ", q->mas[i]);
    }
    printf("\n");
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Stack *top = NULL;
    Stack_2 *top2 = NULL;
    Queue *pbeg = NULL;
    Queue *pend = pbeg;
    Queuemas *q = NULL;
    int t = 0, f = 0;
    while (1) {
        switch (mainMenu()) {
            case 1:
                top2 = (Stack_2 *) malloc(sizeof(Stack_2));
                top2 = init(top2);
                while (f == 0) {
                    switch (addMenu()) {
                        case 1:
                            printf("Ввести число: ");
                            scanf("%d", &t);
                            push2(top2, t);
                            break;
                        case 2:
                            printf("Удалили %d\n", pop2(top2));
                            break;
                        case 3:
                            printStack2(top2);
                            break;
                        case 4:
                            if (getTop2(top2) != 0) {
                                printf("Верхний элемент стека: %d\n", getTop2(top2));
                            }
                            break;
                        case 5:
                            deleteStack2(&top2);
                            top2 = (Stack_2 *) malloc(sizeof(Stack_2));
                            top2 = init(top2);
                            break;
                        case 6:
                            if (top2->size == 0) {
                                printf("Пусто.\n");
                            } else {
                                printf("Не пусто.\n");
                            }
                            break;
                        case 7:
                            f = 1;
                            break;
                    }
                }
                f = 0;
                break;
            case 2:
                while (f == 0) {
                    switch (addMenu()) {
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
                            print(top);
                            break;
                        case 4:
                            if (getTop(top) != 0) {
                                printf("Верхний элемент стека: %d\n", getTop(top));
                            }
                            break;
                        case 5:
                            deleteStack(&top);
                            break;
                        case 6:
                            if (top == NULL) {
                                printf("Пусто.\n");
                            } else {
                                printf("Не пусто.\n");
                            }
                            break;
                        case 7:
                            f = 1;
                            break;
                    }
                }
                f = 0;
                break;
            case 3:
                q = (Queuemas *) malloc(sizeof(Queuemas));
                q = initq(q);
                while (f == 0) {
                    switch (addMenu()) {
                        case 1:
                            printf("Ввести число: ");
                            scanf("%d", &t);
                            addMas(q, t);
                            break;
                        case 2:
                            delqmas(q);
                            break;
                        case 3:
                            printqmas(q);
                            break;
                        case 4:
                            printf("Верхний элемент очереди: %d\n", q->mas[q->front]);
                            break;
                        case 5:
                            deleteQueue2(&q);
                            q = (Queuemas *) malloc(sizeof(Queuemas));
                            q = initq(q);
                            break;
                        case 6:
                            if (q->size == 0) {
                                printf("Пусто.\n");
                            } else {
                                printf("Не пусто.\n");
                            }
                            break;
                        case 7:
                            f = 1;
                    }
                }
                f = 0;
                break;
            case 4:
                while (f == 0) {
                    switch (addMenu()) {
                        case 1:
                            printf("Ввести число: ");
                            scanf("%d", &t);
                            if (pbeg == NULL) {
                                pbeg = firstq(t);
                                pend = pbeg;
                            } else {
                                add(&pend, t);
                            }
                            break;
                        case 2:
                            printf("Удалили %d\n", del(&pbeg));
                            break;
                        case 3:
                            printq(pbeg);
                            break;
                        case 4:
                            printf("Верхний элемент очереди: %d\n", getTop4(pend));
                            break;
                        case 5:
                            deleteQueue(&pbeg, &pend);
                            break;
                        case 6:
                            if (pbeg == pend == 0) {
                                printf("Пусто.\n");
                            } else {
                                printf("Не пусто.\n");
                            }
                            break;
                        case 7:
                            f = 1;
                    }
                }
                f = 0;
                break;
            case 5:
                return 1;
        }
    }
    return 0;
}
