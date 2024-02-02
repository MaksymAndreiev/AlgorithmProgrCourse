#include <stdio.h>

int main() {
    float num1, num2;
    do {
        printf("Enter two numbers(enter 0 0 to exit):\n");
        scanf("%f %f", &num1, &num2);
        if ((num1 == 0) && (num2 == 0)) {
            printf("Good bye!");
            break;
        } else {
            if (num1 > num2) {
                printf("SOS");
            } else {
                printf("Wonderful\n");
            }
        }
    } while (num1 < num2);
    return 0;
}
