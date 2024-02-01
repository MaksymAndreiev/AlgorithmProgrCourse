Algorithmization and Programming - lab work #2

# Laboratory Work #2 Structures

Develop a data structure of type **struct** to represent information about an academic group of students, as follows:

- last name,
- first name,
- patronymic,
- date of birth,
- average academic performance in the range from 0 to 100 points (real number). Surname, first name and patronymic are
  separate fields.

Date of birth should be entered in the format string "dd.mm.yyyyy" (e.g., 12.03.1998), and the day, month and year
should be stored in separate fields (of the type "dd.mm.yyyyy").
be stored in separate fields (of type integer) of ***nested record***.

# **Task:**

- Use a dynamic array of structures (records) to store information about an academic group.
- Organize the functionality of the following two-level menu:

Menu Function Description:

**Point 1.** Add student

- when entering, sort the array by surname.

**Point 2. .** Search for student information (submenu):

- user enters last name,

- all information on all students with this surname is displayed (see item 4.).

- user enters two integers in the range from 0 to 100 (inclusive),

- the list of students whose average score is in this range is displayed (see p.4.).
  range (see item 4.).

- the user enters the day and month of birth in the format "dd.mm",

- the information about students whose date of birth coincides with the entered one is displayed (see p.4.).

**Point 3.** Delete the student with the specified number (if such a student exists).

**Point 4.** Display information about all students (on the screen):

| Surname    | First name | Patronymic  | Date of birth | Average academic performance |
|------------|------------|-------------|---------------|------------------------------|
| Kravchenko | Sergey     | Sergeyevich | 01.01.2020    | 95                           |

Алгоритмизация и программирование – лабораторная работа №2

# Лабораторная работа №2 Структуры

Разработать структуру данных типа **struct** для представления информации об академической группе студентов, а
именно:

- фамилия,
- имя,
- отчество,
- дата рождения,
- средняя успеваемость в диапазоне от 0 до 100 баллов (вещественное число). Фамилия, имя и отчество - отдельные поля.

Дата рождения должна вводится строкой формата «дд.мм.гггг» (например, 12.03.1998), при этом день, месяц и год должны
храниться в отдельных полях (типа integer) ***вложенной записи***.

# **Задание:**

- Использовать динамический массив структур (записей) для хранения информации об академической группе.
- организовать функциональность следующего двухуровнего меню:

Описание функций меню:

**Пункт 1.** Добавить студента

- при вводе сортировка массива по фамилии.

**Пункт 2. .** Поиск информации о студенте (подменю):

- пользователь вводит фамилию,

- выводится вся информация по всем студентам с такой фамилией (см п.4.).

- пользователь вводит два целых числа в диапазоне от 0 до 100 (включительно),

- выводится список студентов, средний балл которых в этом
  диапазоне (см п.4.).

- пользователь вводит день и месяц рождения в формате "дд.мм",

- выводится информация о студентах, дата рождения которых совпадает с введенными (см п.4.).

**Пункт 3.** Удалить студента с указанным номером (если такой студент существует).

**Пункт 4.** Выводится информацию о всех студентах (на экран):

| Фамилия   | Имя    | Отчество  | Дата рождения | Средняя успеваемость |
|-----------|--------|-----------|---------------|----------------------|
| Кравченко | Сергей | Сергеевич | 01.01.2020    | 95                   |
