#include <stdio.h>
#include <windows.h>
#include <time.h>

typedef struct tree {
    int key;
    struct tree *left;
    struct tree *right;
    struct tree *parent;
} node;

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
        if (key < root2->key) {
            root2 = root2->left;
        } else {
            root2 = root2->right;
        }
    }
    tmp->parent = root3;
    tmp->left = NULL;
    tmp->right = NULL;
    if (key < root3->key) root3->left = tmp;
    else root3->right = tmp;
    return root;
}

void addone(node *root) {
    if (!root) {
        return;
    }
    if (!root->left && !root->right) {
        root->key += 1;
    }
    addone(root->left);
    addone(root->right);
}

void deleteone(node *root) {
    if (!root) {
        return;
    }
    if (root->left || root->right) {
        root->key -= 1;
    }
    deleteone(root->left);
    deleteone(root->right);
}

void preorder(node *root) {
    if (root == NULL) {
        return;
    }
    if (root->key) {
        printf("%d ", root->key);
    }
    preorder(root->left);
    preorder(root->right);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    int N = 3 + rand() % 20, i;
    node *root = NULL;
    root = create(root, 1 + rand() % 100);
    for (i = 1; i < N; i++) {
        root = add(root, 1 + rand() % 100);
    }
    printf("Прямой обход:");
    preorder(root);
    printf("\n");
    addone(root);
    deleteone(root);
    printf("Прямой обход:");
    preorder(root);
    printf("\n");
    return 0;
}
