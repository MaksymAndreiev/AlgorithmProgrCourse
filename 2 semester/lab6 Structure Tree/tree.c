#include <stdio.h>
#include <windows.h>

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

node *search(node *root, int key) {
    while (root) {
        if (root->key > key) {
            root = root->left;
            continue;
        } else if (root->key < key) {
            root = root->right;
            continue;
        } else {
            return root;
        }
    }
    return NULL;
}

node *minimum(node *root) {
    if (root->left == NULL) {
        return root;
    }
    return minimum(root->left);
}

node *maximum(node *root) {
    if (root->right == NULL) {
        return root;
    }
    return maximum(root->right);
}

node *dlt(node *root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        root->left = dlt(root->left, key);
    } else if (key > root->key) {
        root->right = dlt(root->right, key);
    } else if (root->left != NULL && root->right != NULL) {
        root->key = minimum(root->right)->key;
        root->right = dlt(root->right, root->key);
    } else {
        if (root->left != NULL) {
            root = root->left;
        } else if (root->right != NULL) {
            root = root->right;
        } else {
            root = NULL;
        }
    }
    return root;
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

void postorder(node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    if (root->key) {
        printf("%d ", root->key);
    }
}

void inorder(node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    if (root->key) {
        printf("%d ", root->key);
    }
    inorder(root->right);
}

int height(node *node) {
    if (node == NULL)
        return 0;
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
            return (lheight + 1);
        else return (rheight + 1);
    }
}

void printGivenLevel(node *root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->key);
    else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

void printLevelOrder(node *root) {
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++) {
        printGivenLevel(root, i);
    }
}

void print_menu() {
    printf("1.Добавить узел\n");
    printf("2.Найти узел\n");
    printf("3.Удалить узел\n");
    printf("4.Печать дерева\n");
    printf("5.Найти величину наибольшего элемента дерева.\n");
    printf("6.Выход\n");
    printf("Ваш выбор: ");
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int p, num;
    node *root = NULL;
    while (1) {
        print_menu();
        scanf("%d", &p);
        switch (p) {
            case 1:
                printf("Добавить число\t");
                scanf("%d", &num);
                if (root == NULL) {
                    root = create(root, num);
                } else {
                    root = add(root, num);
                }
                break;
            case 2:
                printf("Найти число\t");
                scanf("%d", &num);
                printf("Узел: ");
                if (search(root, num) == NULL) {
                    printf("нет\n");
                } else {
                    printf("%d\n", search(root, num)->key);
                }
                printf("Родитель: ");
                if (search(root, num)->parent == NULL) {
                    printf("нет\n");
                } else {
                    printf("%d\n", search(root, num)->parent->key);
                }
                printf("Левый потомок: ");
                if (search(root, num)->left == NULL) {
                    printf("нет\n");
                } else {
                    printf("%d\n", search(root, num)->left->key);
                }
                printf("Правый потомок: ");
                if (search(root, num)->right == NULL) {
                    printf("нет\n");
                } else {
                    printf("%d\n", search(root, num)->right->key);
                }
                break;
            case 3:
                printf("Удалить число\t");
                scanf("%d", &num);
                root = dlt(root, num);
                break;
            case 4:
                printf("Прямой обход:");
                preorder(root);
                printf("\n");
                printf("Обратный обход:");
                postorder(root);
                printf("\n");
                printf("Симметричный обход:");
                inorder(root);
                printf("\n");
                printf("Обход в ширину:");
                printLevelOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Величина наибольшего элемента дерева %d\n", maximum(root)->key);
                break;
            case 6:
                return 1;
        }
    }
    return 0;
}
