#include <stdio.h> // ввод/вывод
#include "student.h" // добавление заголовочного файла, который отвечает за операции со студентами
#include "course.h" // операции с курсом

int main() {
    // тесты
    Student s1 = {"Алиса", 20, 85.5};
    Student s2 = {"Даня", 21, 92.0};
    Course c1 = {"Программирование на C", 0, 0.0};

    add_student(&c1, &s1);
    add_student(&c1, &s2);

    printf("Лучший студент: %s (%.1f)\n", find_best_student(&c1)->name, find_best_student(&c1)->avg_grade);

    change_avg_grade(&s1, 90.0);
    if (is_excellent(&s1)) {
        printf("%s - отличник\n", s1.name);
    }

    return 0;
}