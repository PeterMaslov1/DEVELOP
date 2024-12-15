#include "student.h" // подключаем заголовочный файл student.h
#include <stdlib.h> // malloc и free (выделение и освобождение памяти)
#include <string.h> // для strcpy (копирование строк)

// Функция для создания нового студента
Student* createStudent(const char *name, float grade) {
    Student *newStudent = (Student*)malloc(sizeof(Student)); // Выделение памяти под структуру Student
    newStudent->grade = grade; // записываем оценку в структуру
    size_t nameLen = strlen(name) + 1; // вычисляем длину имени + 1 (для нулевого символа)
    newStudent->name = (char*)malloc(nameLen * sizeof(char)); // выделяем память под имя
    strcpy(newStudent->name, name); // копируем имя в выделенную память
    return newStudent; // возвращаем указатель на созданного студента
}

// Функция для обновления оценки студента
void updateGrade(Student* student, float newGrade) {
    student->grade = newGrade; // обновляем оценку студента
}

// Функция для проверки, является ли студент отличником
int isExcellent(Student *student) {
    return (student->grade >= EXCELLENT_GRADE); // возвращаем 1, если оценка >= EXCELLENT_GRADE, иначе 0
}

// Функция для освобождения памяти, выделенной под студента
void freeStudent(Student *student) {
    free(student->name); // Освобождаем память, выделенную под имя студента
    free(student);      // Освобождаем память, выделенную под структуру Student
}