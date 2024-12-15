#include "course.h" // подключаем заголовочный файл course.h
#include <stdlib.h> // malloc и free (выделение и освобождение памяти)
#include <stdio.h>  // для printf (вывод на экран)

// Функция для создания нового курса
Course* createCourse() {
    Course* newCourse = (Course*)malloc(sizeof(Course)); // выделение памяти+ под структуру Course
    newCourse->num_students = 0; // изначально в курсе нет студентов
    for (int i = 0; i < MAX_STUDENTS; i++) {
        newCourse->students[i] = NULL; // инициализация массива студентов NULL (пока нет студентов)
    }
    return newCourse; // возвращение указателя на созданный курс
}

// Функция для добавления студента в курс
void addStudent(Course* course, Student* student) {
    course->students[course->num_students] = student; // добавляем указатель на студента в массив
    course->num_students++; // увеличиваем количество студентов в курсе на 1
}

// Функция для удаления студента из курса
void removeStudent(Course* course, Student* student) {
  for (int i = 0; i < course->num_students; i++) { // Цикл по всем студентам
    if (course->students[i] == student) { // Нашли студента, которого нужно удалить
      for (int j = i; j < course->num_students - 1; j++) { // Сдвигаем последующих студентов на одну позицию влево
        course->students[j] = course->students[j + 1];
      }
      course->num_students--; // Уменьшаем общее количество студентов на 1
      break; // Завершение поиска
    }
  }
}

// Функция для вывода информации о курсе
void printCourse(Course* course) {
     printf("Курс. Студентов: %d\n", course->num_students); // Выводим общее количество студентов в курсе
     for (int i = 0; i < course->num_students; i++) { // Цикл по всем студентам в курсе
        printf("   - %s, оценка: %.1f\n", course->students[i]->name, course->students[i]->grade); // Выводим информацию о каждом студенте (имя и оценку)
     }
}

// Функция для освобождения памяти, выделенной под курс
void freeCourse(Course* course) {
    for (int i = 0; i < course->num_students; i++) { // Цикл по всем студентам в курсе
       freeStudent(course->students[i]); // Освобождаем память, выделенную под каждого студента (используем freeStudent из student.c)
       course->students[i] = NULL; // устанавливаем в NULL для избежания висячих указателей
    }
    free(course); // Освобождаем память, выделенную под сам курс
}

// Функция для поиска лучшего студента
Student* findBestStudent(Course *course){
    Student *bestStudent = course->students[0]; // Изначально считаем лучшим первого студента
    for(int i = 1; i < course->num_students; i++){ // Перебираем всех студентов, начиная со второго
        if(course->students[i]->grade > bestStudent->grade){ // Если нашли студента с более высокой оценкой
            bestStudent = course->students[i]; // Запоминаем его как лучшего
        }
    }
    return bestStudent; // Возвращаем указатель на лучшего студента
}