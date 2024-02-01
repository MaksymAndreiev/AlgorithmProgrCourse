#include <stdio.h>

long int factorial(int N){
    long int i,f;
    for (f=1, i = 1; i <= N; i++) {
        f*=i;
    }
    return f;
}

int main(){
    int N;
    pritf("Enter a number: ");
    scanf("%d", &N);
    if((N<0)||(N>12)){
        pritf("Error");
    } else {
        pritf("%ld", factorial(N));
    }
    return 0;
}