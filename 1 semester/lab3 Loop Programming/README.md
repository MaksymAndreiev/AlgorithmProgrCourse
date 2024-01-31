Algorithmization and Programming - lab work #3

## Laboratory work #3 Programming loops

## **Task 1:**

An integer N (>0) is given. Find the sum $N^2 + (N+1)^2 + (N+2)^2 + \ldots + (2N)^2$.

## **Task 2:**

Given an integer N and a set of integers: A1, A2, ..., AN. Calculate the arithmetic mean of all positive numbers.

## **Task 3:**

Calculate the product of $\frac{1}{2} \cdot \frac{3}{4} \cdot \frac{5}{6}. \cdot \ldots$ to the nearest $10^{-4}$.

## **Task 4:**

Find the sum of the series:
$$S = \sum_{i=1}^{\infty} {\frac{1}{i(i+1)}$$.
by numerical summation (approximation), using some sufficiently large number N instead of infinity. The error of the
computation depends on this.
Perform the following calculations:

- Using a variable $S_f$ of type `float`, write a program to sum a series into it.
- Add a new variable $S_d$ of type double and summarize the same series using it (output both sums in the same output
  statement). Calculate the difference between $S_d$ and $S_f$ for N=1,000, N=10,000 and N=50,000. Explain the results
  obtained.
- Perform the calculations for N=1,000,000. How will the sum of the series change compared to smaller values of N? Is
  such a change possible in exact arithmetic for a series consisting of positive summands? Explain the reason for the
  observed change and suggest a way to solve the problem.
- Change the order of summarizing the series to the reverse order. Compare the results of two cycles (forward and
  reverse order of summation) and draw conclusions.
  **Note**. In the output statement, add printing the value of the expression: $T=(1-1/(N+1))$.

Алгоритмизация и программирование – лабораторная работа №3

# Лабораторная работа №3 Программирование циклов

## **Задание 1:**

Дано целое число N (>0). Найти сумму $N^2 + (N+1)^2 + (N+2)^2 + \ldots + (2N)^2$.

## **Задание 2:**

Дано целое число N и набор целых чисел: A1, A2, …, AN. Вычислить среднее арифметическое всех положительных чисел.

## **Задание 3:**

Вычислить произведение $\frac{1}{2} \cdot \frac{3}{4} \cdot \frac{5}{6} \cdot \ldots$ с точностью до $10^{-4}$.

## **Задание 4:**

Найти сумму ряда:
$$S = \sum_{i=1}^{\infty} \frac{1}{i(i+1)}$$
с помощью численного суммирования (приближенно), используя вместо бесконечности некоторое достаточно большое число N. От
этого зависеть погрешность вычислений.
Выполнить следующие вычисления:
• Используя переменную $S_f$ типа `float`, напишите программу суммирования в нее ряда.
• Добавьте новую переменную $S_d$ типа double и суммируйте тот же ряд с ее помощью (выводить обе суммы в одном операторе
вывода). Вычислить разницу между $S_d$ и $S_f$ для N=1 000, N=10 000 и N=50 000. Объяснить полученные результаты.
• Проведите вычисления для N=1 000 000. Как изменится сумма ряда по сравнению с меньшими значениями N? Возможно ли в
точной арифметике такое изменение для ряда, состоящего из положительных слагаемых? Объясните причину наблюдающегося
изменения и предложите способ разрешить проблему.
• Измените порядок суммирования ряда на обратный. Сравните результаты работы двух циклов (прямого и обратного порядка
суммирования), сделайте выводы.
**Примечание**. В операторе вывода добавте печать значения выражения: $T=(1-1/(N+1))$.
