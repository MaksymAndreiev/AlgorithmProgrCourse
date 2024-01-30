#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Rus");
    float x, y, a, b, c;
    printf("Введите х и у\n");
    scanf("%f %f", &x, &y);
    a=x*x;
    b=y*y;
    c=a+b;
    if((c>=1)&&(c<=9)){
        printf("Точка принадлежит");
    } else{
        printf("Точка не принадлежит");
    }
}