#ifndef COURSE_H
#define COURSE_H

#include "student.h" // добавляем student.h, чтобы использовать структуру student

#define MAX_STUDENTS 100 // Максимальное количество студентов в курсе

// Структура курса
typedef struct Course {
    Student* students[MAX_STUDENTS]; // массив указателей на студентов
    int num_students;               // количество студентов в курсе
} Course;

// Функции для работы с курсами
Course* createCourse();                  // создать новый курс
void addStudent(Course* course, Student* student); // добавить студента в курс
void removeStudent(Course* course, Student* student);  // удалить студента из курса
void printCourse(Course* course);       // вывести информацию о курсе
void freeCourse(Course* course);      // освободить память, выделенную для курса
Student* findBestStudent(Course *course);  // поиск лучшего студента

#endif