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

node *dlt(node *root, int key) {
    node *p = root, *l = NULL, *m = NULL;
    l = search(root, key);
    if (l->right == NULL && l->right == NULL) {
        l == NULL;
    }
    if (l->right == NULL) {
        m = l->parent;
        if (l == m->right) {
            m->right == NULL;
            m->right = l->left;
        } else {
            m->left == NULL;
            m->left = l->left;
        }
    }
    if (l->left == NULL) {
        m = l->parent;
        if (l == m->right) {
            m->right == NULL;
            m->right = l->right;
        } else {
            m->left == NULL;
            m->left = l->right;
        }
    }
    if (l->right && l->left) {
        if (l->right->left == NULL) {
            m = l->parent;
            if (l == m->left) {
                m->left == NULL;
                m->left = l->right;
                l->right = l->right->right;
                m->left->left = l->left;
            } else {
                m->right == NULL;
                m->right = l->right;
                l->right = l->right->right;
                m->right->left = l->left;
            }
        }
        if (l->right->left) {
            m = l->parent;
            if (l == m->left) {
                m->left == NULL;
                node *lc = minimum(l->right);
                l->key = lc->key;
                l->right = dlt(l->right, lc->key);
                m->left = l;
            } else {
                m->right = NULL;
                node *lc = minimum(l->right);
                l->key = lc->key;
                l->right = dlt(l->right, lc->key);
                m->right = l;
            }
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

int count(node *root) {
    int c = 0;
    if (root->left) {
        c += 1 + count(root->left);
    }
    if (root->right) {
        c += count(root->right);
    }
    return c;
}

void swap(node *root) {
    if (root->left && root->right) {
        int tmp;
        swap(root->left);
        swap(root->right);
        tmp = root->left->key;
        root->left->key = root->right->key;
        root->right->key = tmp;
    } else {
        return;
    }
}

void print_menu() {
    printf("1.Добавить узел\n");
    printf("2.Переписать узел\n");
    printf("3.Удалить узел\n");
    printf("4.Печать дерева\n");
    printf("5.Посчитать и напечатать количество узлов дерева, являющихся левыми дочерними\n");
    printf("6.Для каждого узла дерева, имеющего два дочерних узла, поменять местами их значения\n");
    printf("7.Выход\n");
    printf("Ваш выбор: ");
}

int main(int argc, char **argv) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int p, num, number;
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
                    if (search(root, num) == NULL) {
                        root = add(root, num);
                    } else {
                        printf("Повтор запрещен");
                    }
                }
                break;
            case 2:
                printf("Переписать число\t");
                scanf("%d", &num);
                printf("Новое число\t");
                scanf("%d", &number);
                search(root, num)->key = number;
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
                printf("%d\n", count(root));
                break;
            case 6:
                swap(root);
                break;
            case 7:
                return 1;
        }
    }
    return 0;
}

