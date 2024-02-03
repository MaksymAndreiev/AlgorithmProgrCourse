#include <stdio.h>

int main() {
    int N = 20, i, ii;
    int v[N];
    int c[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    printf("Rate this movie:\n");
    for (i = 0; i < N; i++) {
        printf("%d)", i + 1);
        scanf("%d", &v[i]);
        switch (v[i]) {
            case 1: {
                c[0]++;
                break;
            }
            case 2: {
                c[1]++;
                break;
            }
            case 3: {
                c[2]++;
                break;
            }
            case 4: {
                c[3]++;
                break;
            }
            case 5: {
                c[4]++;
                break;
            }
            case 6: {
                c[5]++;
                break;
            }
            case 7: {
                c[6]++;
                break;
            }
            case 8: {
                c[7]++;
                break;
            }
            case 9: {
                c[8]++;
                break;
            }
            case 10: {
                c[9]++;
                break;
            }
        }
    }
    printf("Rating\tNumber of ratings\n");
    for (i = 0, ii = 1; (i < 10) && (ii <= 10); i++, ii++) {
        printf("%d\t%d\n", ii, c[i]);
    }
    printf("Total: %d", N);
    return 0;
}
