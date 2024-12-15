#include <stdio.h>   // подключаем stdio.h для printf
#include "student.h" // подключаем student.h для работы со студентами
#include "course.h"  // подключаем course.h для работы с курсами

int main() {
    // Создаём студентов
    Student *student1 = createStudent("Иван", 85.0f);  // создаём студента Ивана
    Student *student2 = createStudent("Мария", 92.0f); // создаём студента Марию
    Student *student3 = createStudent("Петр", 78.0f);  // создаём студента Петра
    Student *student4 = createStudent("Елена", 95.0f); // создаём студента Елену

    // Создаём курс
    Course *course1 = createCourse();  // Создаём новый курс

    // Добавляем студентов в курс
    addStudent(course1, student1); 
    addStudent(course1, student2); 
    addStudent(course1, student3); 
    addStudent(course1, student4);

    // Выводим информацию о курсе
    printCourse(course1); // вывод списка студентов в курсе
     // Находим лучшего студента
    Student *bestStudent = findBestStudent(course1); // находим лучшего студента в курсе
    printf("Лучший студент: %s, оценка: %.1f\n", bestStudent->name, bestStudent->grade); // Выводим информацию о лучшем студенте

     // Удаляем студента
    removeStudent(course1, student3); // Удаляем Петра из курса
    printf("Курс после удаления студента\n"); // сообщение
    printCourse(course1); // Вывод информации о курсе после удаления студента

    // Освобождаем память
    freeCourse(course1); // Освобождаем память, выделенную под курс и студентов
      // Устанавливаем в NULL, чтобы избежать висячих указателей
    student1 = NULL;
    student2 = NULL;
    student3 = NULL;
    student4 = NULL;

    return 0; // Завершение программы
}