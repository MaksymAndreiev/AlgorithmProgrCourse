## Practice Paper #12 Recursion

## Task 1.

To compute the function $f(n)= a^n$, there is a recurrence formula:
$$a^n = a * a^(n-1), a^0 = 1.$$.
Write a recursive program to calculate the degree of a number (number is a double-precision floating-point type, degree
is a type of long integer with a sign).

#### Task 1 (bonus).

Use optimized recursion to calculate the degree of a number (count and print the number of recursion steps for
degree N=10, 100, 1000).
To optimize, you can use the following rule: when increasing a degree to a power, the exponents are multiplied, but the
base remains unchanged:
$$(a^n)^m=a^(n⋅m)$$.

## Task 2.

A sequence of Fibonacci numbers: if the zero element of the sequence is 0, the first element is 1, and each successive
element is equal to the sum of the two previous ones, it is a sequence of Fibonacci numbers (0, 1, 1, 2, 3, 5, 8, 13, 21,
34, ... ).
Write a program to compute the Nth Fibonacci number using a recurrence function (N is entered from the keyboard):
``long long long int fibonachi(int N)``.
Report the calculations for: 20, 30, and 40th Fibonacci numbers.

## Task 3.

Write a recursive program to find the maximum value in a one-dimensional array of N random integers. Calculate
the number of recursion steps at N=10, 100, 1000. Find the maximum value of N at which the program works correctly.

# Практическая работа №12 Рекурсия

## Задание 1.

Для вычисления функции $f(n)= a^n$ есть рекуррентная формула:
$$a^n = a * a^(n-1), a^0 = 1.$$
Написать рекурсивную программу для вычисления степени числа (число - тип двойной точности с плавающей запятой, степень -
тип длинного целого со знаком).

### Задание 1 (бонус).

Использовать оптимизированную рекурсию для вычисления степени числа (подсчитать и напечатать число шагов рекурсии для
степени N=10, 100, 1000).
Для оптимизации можно использовать правило: при возведении степени в степень показатели перемножаются, а основание
остаётся без изменений:
$$(a^n)^m=a^(n⋅m)$$

## Задание 2.

Последовательность чисел Фибоначчи: если нулевой элемент последовательности равен 0, первый – 1, а каждый последующий
равен сумме двух предыдущих, то это последовательность чисел Фибоначчи (0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ... ).
Напишите программу, позволяющую вычислить N-е число Фибоначчи, используя рекуррентную функцию (N вводится с клавиатуры):
```long long int fibonachi(int N)```
Представьте в отчете расчеты для: 20, 30 и 40-е числа Фибоначчи.

## Задание 3.

Написать рекурсивную программу для поиска максимального значения в одномерном массиве N целых случайных чисел. Вычислить
число шагов рекурсии при N=10, 100, 1000. Найти максимальное значение N, при котором программа работает корректно.
