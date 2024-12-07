#include <stdio.h> // ввод/вывод
#include "student.h" // добавление заголовочного файла, который отвечает за операции со студентами
#include <stdbool.h> // тип bool для true/false
#include "course.h" // операции с курсом

int main() {
    // тесты для определения отличника
    Student student1 = {"Алиса", 20, 89.9};
    printBoolResult("Test is_excellent (below threshold)", is_excellent(&student1)); // ожидаемый вывод: false

    Student student2 = {"Даня", 21, 90.0};
    printBoolResult("Test is_excellent (at threshold)", is_excellent(&student2)); // ожидаемый вывод: true

    Student student3 = {"Вася", 22, 95.5};
    printBoolResult("Test is_excellent (above threshold)", is_excellent(&student3)); // ожидаемый вывод: true


    // тесты изменения среднего балла
    Student student4 = {"Коля", 23, 80.0};
    change_avg_grade(&student4, 90.0);
    printf("Test change_avg_grade (valid): %.1f\n", student4.avg_grade); // Ожидаемый вывод: 90.0

    Student student5 = {"Соня", 24, 75.0};
    change_avg_grade(&student5, -5.0); //   обработка некорректного значения
    printf("Test change_avg_grade (invalid): %.1f\n", student5.avg_grade); // Ожидаемый вывод: -5.0 (или сообщение об ошибке)


    // Тесты добавления студентов и поиска отличника
    Course course1 = {"Course 1", 0, 0.0};
    Student student6 = {"Денис", 25, 88.0};
    add_student(&course1, &student6);
    printf("Test add_student: Number of students = %d\n", course1.num_students);  // ожидаемый вывод: 1

    Student* bestStudent = find_best_student(&course1);
    if(bestStudent != NULL){
        printf("Test find_best_student: Best student = %s\n", bestStudent->name);  //  ожидаемый вывод: Денис
    } else {
        printf("Test find_best_student: Course is empty\n");
    }


    return 0;
}


