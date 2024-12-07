#include "course.h" //   включение заголовочного файла course.h

//  добавление студента на курс
void add_student(Course *course, const Student *student) {
    if (course->num_students < 100) { // проверка наличия места в массиве
        course->students[course->num_students] = *student; // добавление студента в массив(группу)
        course->num_students++; // увеличение количества студентов
        if (student->avg_grade > course->max_avg_grade) { // обновление максимального среднего балла, если это необходимо
            course->max_avg_grade = student->avg_grade;
        }
    } else {
        fprintf(stderr, "Курс заполнен!\n"); //  обработка случая, когда курс заполнен
    }
}

// поиск студента с наивысшим средним баллом
Student* find_best_student(const Course *course) {
    if (course->num_students == 0) return NULL; // обработка пустого курса
    Student* best = &(course->students[0]); // пусть первый студент - лучший изначально
    for (int i = 1; i < course->num_students; i++) {
        if (course->students[i].avg_grade > best->avg_grade) { //   сравнение оценок для поиска лучшего студента
            best = &(course->students[i]);
        }
    }
    return best; //   возвращение указателя на лучшего студента
}