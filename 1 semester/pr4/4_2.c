#include <stdio.h>
#include <math.h>

int main() {
    float y, x, z, d, e, f, g, h;
    printf("x=");
    scanf("%f", &x);
    printf("y=");
    scanf("%f", &y);
    z = y - 1;
    d = x - 1;
    e = 5 + y;
    if (x != 1 && y <= 5) {
        h = sqrt(e);
        f = z / d;
        g = f + h;
        printf("%f", g);
    } else {
        printf("error");
    }
    return 0;
}
