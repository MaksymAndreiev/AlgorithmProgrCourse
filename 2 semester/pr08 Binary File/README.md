## Practical Work #8 Binary File

## Task 1

Perform the following operations in one program:

- In the program, create a file (`file_in.dat`). Generate 10
  random numbers (0-100), display them on the screen and write them to the file. Close
  file with a pause (the program does not terminate!). Open the file in
  "Notepad" (do not close the program!), copy the "strange"
  icons (4-byte numbers in the form of 1-byte characters) into the report and close "Notepad".
  "Notepad". Do not end the program.
- Next, in the same program, open the file, read it and find the maximum and minimum numbers, not ending the program.
  maximum and minimum numbers without using the array. Print
  the maximum and minimum. Close the file and finish the program.

## Task 2

Create a static array of records (5 records) for product information:

````
struct product {
   name string [10];
   count integer;
   price double;
} product [N];
````

- Fill the array with data. Save the information from the array
  into a file. Open it in Notepad (do not terminate the program!).
  Copy 4-byte and 8-byte numbers in the form of 1-byte
  characters, field of type string[10] - original to the report. Close Notepad.
- Write and execute a function that completely replaces
  one of the records (search by name) record for another; for example,

  ````
  tmp.name:= 'Mask'; tmp. price:= 10.5; tmp.count:= 100;
  ````

Use the `seek()` function. Check the change in Notepad -
copy it into the report.

- Write and execute a function that inserts after
  each record in the file some "fake" record; e.g,
  
  ````
  tmp.name:= 'Mask'; tmp. price:= 10.5; tmp.count:= 100;).
  ````

Check the change in Notepad

# Практическая работа №8 Бинарный файл

## Задание 1

В одной программе выполнить следующие операции:

- В программе создать файл (`file_in.dat`). Сгенерировать 10
  случайных чисел (0-100), вывести их на экран и записать в файл. Закрыть
  файл с паузой (программа не заканчивает работу!). Открыть файл в
  «Блокноте» (программу при этом не закрывать!), скопировать «странные»
  значки (4-хбайтовые числа в виде 1-но байтовых символов) в отчет и закрыть
  «Блокнот». Программу не заканчивать.
- Далее в этой же программе открыть файл, прочитать его и найти
  максимальное и минимальное число, не используя массив. Напечатать
  максимум и минимум. Закрыть файл и закончить программу.

## Задание 2

Создать статический массив записей (5 записей) для информации о товарах:

````
struct product {
   name string [10];
   count integer;
   price double;
} product [N];
````

- Заполнить массив данными. Сохранить информацию из массива
  в файл. Открыть его в «Блокноте» (программу при этом не заканчивать!).
  Скопировать 4-х байтовые и 8-ми байтовые числа в виде 1-но байтовых
  символов, поле типа string[10] – оригинальное в отчет. Закрыть «Блокнот».
- Написать и выполнить функцию, который полностью заменяет
  одну из записей (поиск по наименованию) запись на другую; например,

  ````
  tmp.name:= 'Маска'; tmp. price:= 10.5; tmp.count:= 100;
  ````

Использовать функцию `seek()`. Проверить изменение в «Блокноте» -
скопировать в отчет.

- Написать и выполнить функцию, которая вставляет после
  каждой записи в файле некоторую «фейковую» запись; например,

  ````
  tmp.name:= 'Маска'; tmp. price:= 10.5; tmp.count:= 100;).
  ````

Проверить изменение в «Блокноте»