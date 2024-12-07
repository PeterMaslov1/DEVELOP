#ifndef COURSE_H // чтобы не было многократного включения заголовочного файла
#define COURSE_H

#include <stdio.h>
#include <string.h> // библиотека для работы со строками (если используются строковые функции)
#include "student.h" // включение определения структуры Student

// Определение структуры Course
typedef struct {
    char name[50];          // название курса
    int num_students;       // количество студентов на курсе
    double max_avg_grade;   // максимальный средний балл на курсе
    Student students[100];  // массив для хранения информации о студентах
} Course;

// Прототипы функций
void add_student(Course *course, const Student *student); // добавление студента на курс
Student* find_best_student(const Course *course);         // нахождение студента с наивысшим средним баллом

#endif // конец условного блока кода