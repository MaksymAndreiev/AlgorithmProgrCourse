Algorithmization and Programming - lab work #3

# Laboratory Work #3 Files

Develop a data structure of type **struct** to represent information about an academic group of students, as follows:

- last name,
- first name,
- patronymic,
- date of birth,
- average academic performance in the range from 0 to 100 points (real number). Surname, first name and patronymic are
  separate fields.

Date of birth should be entered in the format string "dd.mm.yyyyyy" (e.g., 12.03.1998), and the day, month and year
should be stored in separate fields (of type integer) of ***nested record***.

**Task:**

Implement storing, outputting, adding, deleting and searching students from an array of structures lab work #2 using a
binary file. Dynamic array of structures Use to exchange information between the file and the program.

**Requirements**:

- Organize the functionality of the following two-level menu:

1. add student
2. search for a student
3. delete a student
4. categorization
5. group printing
6. exit

**Point 1**. Add a new student to existing students with saving to file + sorting by last name. Initially, load data
from the file (if it exists) into the working array. exists).\
**Point 2**. Initially load data from a file (if it exists) into the working array.
Search for complete information (submenu):

1. by student's surname\
   // user enters the surname, all information is displayed on the screen\
   // for this student and namesakes;
2. by grade range\
   // user inputs two numbers in the range from 0 to 100, the screen displays\
   // the list of students whose average grade falls within this range);
3. by date of birth\
   // the user enters the day and month of birth (in the format "dd.mm"),\
   // the screen displays information about a student or several students,\
   // whose date of birth coincides with the entered ones);

**Point 3**. Delete a student with the specified number (if such a student exists) from the working array. Initially,
load data from the file (if it exists) into the working array. After deletion, overwrite all files.\
**Point 4**. A separate file is created for each category, into which students with the corresponding academic
performance are written by pressing item 4. Item 4 also has a sub-menu (3 sub-items) to view students of individual
categories.

1. with high score\
   // all information about students with grades from 70 to 100 is displayed on the console;
2. with low score\
   // all information about students with scores from 50 to 69 is displayed on the console;
3. no credit\
   // the console displays all information about students with scores from 0 to 49.

**Point 5**. Print information about all students from the working array. Initially, load data from a file (if it
exists) into the working array.

The user has the right to select any menu item immediately after starting the program.
The program should work adequately and not " crash ".

Алгоритмизация и программирование – лабораторная работа №3

# Лабораторная работа №3 Файлы

Разработать структуру данных типа **struct** для представления информации об академической группе студентов, а
именно:

- фамилия,
- имя,
- отчество,
- дата рождения,
- средняя успеваемость в диапазоне от 0 до 100 баллов (вещественное число). Фамилия, имя и отчество - отдельные поля.

Дата рождения должна вводится строкой формата «дд.мм.гггг» (например, 12.03.1998), при этом день, месяц и год должны
храниться в отдельных полях (типа integer) ***вложенной записи***.

**Задание:**

Реализовать хранение, вывод, добавление, удаление и поиск студентов из массива структур
лабораторной работы №2 с использованием бинарного файла. Динамический массив структур
использовать для обмена информацией между файлом и программой.

**Требования**:

- Организовать функциональность следующего двухуровнего меню:

1. добавление студента
2. поиск студента
3. удаление студента
4. классификация по категориям
5. печать группы
6. выход

**Пункт 1**. Добавлять нового студента к уже существующим с сохранением в файл +
сортировка по фамилии. Изначально в рабочий массив загрузить данные из файла (если он
существует).\
**Пункт 2**. Изначально в рабочий массив загрузить данные из файла (если он существует).
Обеспечить поиск полной информации (подменю):

1. по фамилии студента\
   // пользователь вводит фамилию, на экран выводится вся информация\
   // по этому студенту и однофамильцам;
2. по диапазону успеваемости\
   // пользователь вводит два числа в диапазоне от 0 до 100, на экран выводится\
   // список студентов, средний балл которых попадает в этот диапазон);
3. по дате рождения\
   // пользователь вводит день и месяц рождения (в формате "дд.мм"),\
   // на экран выводится информация о студенте или нескольких студентах,\
   // дата рождения которых совпадает с введенными);

**Пункт 3**. Удалить из рабочего массива студента с указанным номером (если такой
существует). Изначально в рабочий массив загрузить данные из файла (если он существует). После
удаления переписать все файлы.\
**Пункт 4**. На каждую категорию создается отдельный файл, в который по нажатию пункта 4
записываются студенты с соответствующей успеваемостью. В пункте 4 также имеется подменю (3
подпункта) для просмотра студентов отдельных категорий.

1. с высоким баллом\
   // на консоль выводится вся информация о студентах с баллами от 70 до 100;
2. с низким баллом\
   // на консоль выводится вся информация о студентах с баллами от 50 до 69;
3. без зачета\
   // на консоль выводится вся информация о студентах с баллами от 0 до 49

**Пункт 5**. Распечатать информацию о всех студентах из рабочего массива. Изначально в
рабочий массив загрузить данные из файла (если он существует).

Пользователь имеет право сразу после запуска программы выбрать любой пункт меню.
Программа должна работать адекватно и не «вылетать».