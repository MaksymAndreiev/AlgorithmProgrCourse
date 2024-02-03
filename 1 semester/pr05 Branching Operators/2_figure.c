#include <stdio.h>
#include <math.h>

int pointInFigureA(double x, double y) {
    double distanceToCenter = sqrt(x * x + y * y);
    if (distanceToCenter <= 1.0) {
        double rotatedX = x * cos(-M_PI / 4) - y * sin(-M_PI / 4);
        double rotatedY = x * sin(-M_PI / 4) + y * cos(-M_PI / 4);

        if (fabs(rotatedX) <= 0.5 && fabs(rotatedY) <= 0.5) {
            return 1;
        }
    }

    return 0;
}

int main() {
    double x, y;

    printf("Enter the coordinates (x y) of the point: ");
    scanf("%lf %lf", &x, &y);

    if (pointInFigureA(x, y)) {
        printf("The point belongs to the figure A\n");
    } else {
        printf("The point is outside of the figure A\n");
    }

    return 0;
}
