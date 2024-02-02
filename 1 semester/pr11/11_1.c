#include <stdio.h>

void init(int (*a)[2], const int M, const int N){
    int i, j;
    printf("Enter your numbers:\n");
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

int main(){
    int M=3, N=2;
    int k,c=0,i,j;
    int a[M][N];
    init(a, M, N);
    printf("Enter k: ");
    scanf("%d", &k);
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            if(a[i][j]==k){
                c++;
            }
        }
        printf("Number of k: %d", c);
    }
    return 0;
}