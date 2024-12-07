#include "student.h" // Включение заголовочного файла student.h

//   изменение среднего балла студента
void change_avg_grade(Student *student, double new_grade) {
    student->avg_grade = new_grade; // само изменение среднего балла студента
}

// проверка на отличника (>= 90.0)
bool is_excellent(const Student *student) {
    return student->avg_grade >= 86.0; //    возвращает true, если студент - отличник, иначе false
}