#include <stdio.h>

int fib(int N) {
    int i, var1, var2;
    var1 = 0;
    var2 = 0;
    for (i = 0; i < N; i++) {
        var1 = var1 + var2;
        var2 = var1 - var2;
    }
    return var2;
}

int main() {
    int N;
    printf("Enter a number of position:\n");
    scanf("%d", &N);
    printf("Your Fibonacci number: %d", fib(N));
    return 0;
}
