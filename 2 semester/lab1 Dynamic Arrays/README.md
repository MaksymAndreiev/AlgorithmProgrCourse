Algorithmization and Programming - Lab Work #1

# Laboratory Work #1 Dynamic Arrays

## Task

Organize the functionality of the following two-level menu:

1. change data.
2. Display the data by country.
3. Display a summary table.
4. Exit the program.


1. **Change data.**
   - Both arrays are initially empty (no memory is allocated for them).
   - When selecting "1", the user is given the opportunity to enter the name of the country
     and the number of medals of each type.
   - If the entered country is already in the list, the name is not added again, and the medals are added to the medals in the list.
     are added to the medals in the row that corresponds to the specified country.
   - If the entered country is not in the list, the program adds the name of this country to the list of
     countries and the medals received by it in the table with medals.
   - After any changes in the tables, provide for sorting of medals and countries in
     according to the rating.
2. **Display data on the country (number of medals and place in the ranking).**\.
   The user specifies the country (writes the name) - the program displays a "mini-table"

   | Place | Country  | Gold | Silver | Bronze | Total |
   |-------|----------|------|--------|--------|-------|
   | 3     | Canada   | 11   | 8      | 10     | 29    |

3. **Display the summary table.**\
   If you select "3", the medal table is displayed for all countries that are in it
   is displayed on the screen:

   #### Total medal standings and full medal table.

   | Place | Country     | Gold | Silver | Bronze | Total |
   |-------|-------------|------|--------|--------|-------|
   | 1     | Norway      | 14   | 14     | 11     | 39    |
   | 2     | Germany     | 14   | 10     | 7      | 31    |
   | 3     | Canada      | 11   | 8      | 10     | 29    |
   | 4     | USA         | 9    | 8      | 6      | 23    |
   | 5     | Netherlands | 8    | 6      | 6      | 20    |

Алгоритмизация и программирование – лабораторная работа №1

# Лабораторная работа №1 Динамические массивы

## Задание

Организовать функциональность следующего двухуровнего меню:

1. Изменить данные.
2. Вывести данные по стране.
3. Вывести сводную таблицу.
4. Выход из программы.


1. **Изменить данные.**
    - Оба массива изначально пустые (память под них не выделена).
    - При выборе пункта «1» пользователю предоставляется возможность ввести название страны
      и количество медалей каждого типа.
    - Если введенная страна уже есть в списке, то название повторно не добавляется, а медали
      прибавляются к медалям в строке, которая соответствует указанной стране.
    - Если введенной страны в списке нет, программа добавляет название этой страны в список
      стран и полученные ею медали в таблицу с медалями.
    - После любых изменений в таблицах предусмотреть сортировку медалей и стран в
      соответствии с рейтингом.
2. **Вывести данные по стране (количество медалей и место в рейтинге).**\
   Пользователь указывает страну (пишет название) – программа выводит «мини-табличку»

   | Место | Страна | Золото | Серебро | Бронза | Всего |
   |-------|--------|--------|---------|--------|-------|
   | 3     | Канада | 11     | 8       | 10     | 29    |

3. **Вывести сводную таблицу.**\
   При выборе пункта «3» на экран выводится таблица медалей по всем странам, которые в ней
   записаны:

   #### Общий медальный зачет и полная таблица медалей

   | Место | Страна      | Золото | Серебро | Бронза | Всего |
   |-------|-------------|--------|---------|--------|-------|
   |   1   | Норвегия    |   14   |   14    |   11   | 39    |
   |   2   | Германия    |   14   |   10    |   7    | 31    |
   |   3   | Канада      |   11   |   8     |   10   | 29    |
   |   4   | США         |   9    |   8     |   6    | 23    |
   |   5   | Нидерланды  |   8    |   6     |   6    | 20    |

