#include <stdio.h>
#include <locale.h>

void guesser() {
    int n, a, b, c, d, i, guess, cheat;
    n = (rand() + rand()) % 10000;
    a = n / 1000;
    b = (n / 100) % 10;
    c = (n % 100) / 10;
    d = n % 10;
    for (i = 0; i < 5; i++) {
        if (a == b) {
            a++;
        }
        if (a == c) {
            a++;
        }
        if (a == d) {
            a++;
        }
        if (b == c) {
            b++;
        }
        if (b == d) {
            b++;
        }
        if (c == d) {
            d++;
        }
        n = a * 1000 + b * 100 + c * 10 + d;
    }
    printf("Введите четырехзначное число ниже:\n");
    for (i = 0; guess != n; i++) {
        scanf("%d", &guess);
        if ((guess < 1000) || (guess > 9999)) {
            printf("Уважаемый пользователь! Четырехзначное число предполагает то, что в числе 4 цифры!\n");
            continue;
        }
        if (((guess - n) <= 10) && ((guess - n) > 0) || (((n - guess) <= 10) && ((n - guess) > 0))) {
            printf("Очень близко!!\n");
        }
        if (guess < n) {
            printf("Это число меньше загаданного\n");
            printf("Введите число ниже:\n");
        }
        if (guess > n) {
            printf("Это число больше загаданного\n");
            printf("Введите число ниже:\n");
        }
        if (guess == n) {
            printf("Поздравляем, Вы угадали!\n");
            break;
        }
        if (i == 4) {
            printf("Хотите подсказку?\n1 )Да\n2) Нет\n");
            scanf("%d", &cheat);
            if (cheat == 1) {
                printf("Первая цифра это %d\n", a);
            }
        }
        if (i == 9) {
            printf("Хотите подсказку?\n1 )Да\n2) Нет\n");
            scanf("%d", &cheat);
            if (cheat == 1) {
                printf("Вторая цифра это %d\n", b);
            }
        }
        if (i == 14) {
            printf("Хотите подсказку?\n1 )Да\n2) Нет\n");
            scanf("%d", &cheat);
            if (cheat == 1) {
                printf("Третья цифра это %d\n", c);
            }
        }
    }
}

int main() {
    int quit;
    setlocale(LC_ALL, "Rus");
    here:
    guesser();
    printf("Возникло ли у вас желание попытать удачу снова?\n1) Да\n2) Нет\n");
    scanf("%d", &quit);
    if (quit == 1) {
        goto here;
    } else {
        return 0;
    }
}