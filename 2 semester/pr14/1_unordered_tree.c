#include <stdio.h>
#include <windows.h>
#include <time.h>

typedef struct tree {
    int key;
    struct tree *left;
    struct tree *right;
    struct tree *parent;
} node;

void init(int *array, int N) {
    int i;
    for (i = 0; i < N; i++) {
        array[i] = rand() % 100;
    }
}

node *create(node *root, int key) {
    node *tmp = malloc(sizeof(node));
    tmp->key = key;
    tmp->parent = NULL;
    tmp->left = tmp->right = NULL;
    root = tmp;
    return root;
}

node *add(node *root, int key) {
    node *root2 = root, *root3 = NULL;
    node *tmp = malloc(sizeof(node));
    tmp->key = key;
    while (root2 != NULL) {
        root3 = root2;
        root2 = root2->right;
    }
    tmp->parent = root3;
    tmp->left = NULL;
    tmp->right = NULL;
    root3->right = tmp;
    return root;
}

void preorder(node *root) {
    if (root == NULL) {
        return;
    }
    if (root->key) {
        printf("%d ", root->key);
    }
    preorder(root->right); //"Для проверки печатать все правые ветки"
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    int N, i;
    node *root = NULL;
    printf("N=");
    scanf("%d", &N);
    int array[N];
    init(array, N);
    root = create(root, array[0]);
    for (i = 1; i < N; i++) {
        root = add(root, array[i]);
    }
    printf("Прямой обход:");
    preorder(root);
    return 0;
}
