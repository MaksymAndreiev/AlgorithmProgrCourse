#include <stdio.h>

int main() {
    double a, b;
    char t;

    printf("Enter two real numbers a and b: ");
    scanf("%lf %lf", &a, &b);

    printf("Enter the operation (+/-): ");
    scanf(" %c", &t);

    switch (t) {
        case '+':
            printf("Operation (+)= %.2lf\n", a + b);
            break;
        case '-':
            printf("Operation (-)= %.2lf\n", a - b);
            break;
        default:
            printf("Unknown operation!\n");
            break;
    }

    return 0;
}
