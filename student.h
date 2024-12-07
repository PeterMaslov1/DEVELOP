#ifndef STUDENT_H // чтобы не было многократного включения заголовочного файла
#define STUDENT_H

#include <stdio.h> // стандартная библиотека ввода/вывода
#include <string.h> // работа со строками (если используются строковые функции)
#include <stdbool.h> // тип bool (для true/false)

//   определение структуры Student
typedef struct {
    char name[50];     // имя студента (массив символов)
    int age;           // возраст студента (целое число)
    double avg_grade;  // средний балл студента (число с плавающей точкой)
} Student;

// Прототипы функций (объявления)
void change_avg_grade(Student *student, double new_grade); //    корректирует средний балл студента
bool is_excellent(const Student *student);                //   проверка студента на отличника


#endif // конец условного блока кода