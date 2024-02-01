#include <stdio.h>

int main() {
    int a = 2147483647;
    int b = -2147483648;
    unsigned int c = 4294967295;
    unsigned int d = 0;
    a++;
    b--;
    c++;
    d--;
    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
    printf("%d\n", d);
    return 0;
}