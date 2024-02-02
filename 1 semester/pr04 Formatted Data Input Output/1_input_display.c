#include <stdio.h>

int main() {
    int P;
    int L;
    float M;
    double S;
    float Z;
    int A;
    printf("Enter P\n");
    scanf("%d", &P);
    printf("Enter L\n");
    scanf("%d", &L);
    printf("Enter M\n");
    scanf("%f", &M);
    printf("Enter S\n");
    scanf("%lf", &S);
    printf("Enter Z\n");
    scanf("%f", &Z);
    printf("Enter A\n");
    scanf("%d", &A);
    printf("P=%d\t\t", P);
    printf("L=%d\n", L);
    printf("M=%.2f\t\t", M);
    printf("S=%.8lf\n", S);
    printf("Z=%.5f\t", Z);
    printf("A=%d", A);
    return 0;
}