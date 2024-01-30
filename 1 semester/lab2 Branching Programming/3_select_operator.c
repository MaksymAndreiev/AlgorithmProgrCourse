#include <stdio.h>
#include <locale.h>

int main() {
    setLocale(LC_ALL, "Rus");
    int day, lect, pract;
    printf("Выберите день недели\n");
    printf("1) Понедельник\n");
    printf("2) Вторник\n");
    printf("3) Среда\n");
    printf("4) Четверг\n");
    printf("5) Пятница\n");
    printf("6) Суббота\n");
    printf("7) Воскресенье\n");
    scanf("%d", &day);
    switch (day) {
        case 1:
            lect = 1;
            pract = 1;
            printf("Количество лекций: %d, количесство практик: %d\n", lect, pract);
            break;
        case 2:
            lect = 1;
            pract = 3;
            printf("Количество лекций: %d, количесство практик: %d\n", lect, pract);
            break;
        case 3:
            lect = 2;
            pract = 0;
            printf("Количество лекций: %d, количесство практик: %d\n", lect, pract);
            break;
        case 4:
            lect = 3;
            pract = 1;
            printf("Количество лекций: %d, количесство практик: %d\n", lect, pract);
            break;
        case 5:
            lect = 0;
            pract = 2;
            printf("Количество лекций: %d, количесство практик: %d\n", lect, pract);
            break;
        case 6:
            lect = 0;
            pract = 0;
            printf("Количество лекций: %d, количесство практик: %d\nВыхродной!\n", lect, pract);
            break;
        case 7:
            lect = 0;
            pract = 0;
            printf("Количество лекций: %d, количесство практик: %d\nВыхродной!\n", lect, pract);
            break;
        default:
            printf("Предлагаю посмотреть на календарь еще раз. В неделе всего 7 цей. Выберите число от 1 до 7.\n");
            break;
    }
    return 0;
}