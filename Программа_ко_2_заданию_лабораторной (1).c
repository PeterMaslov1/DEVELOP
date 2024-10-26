#include <stdio.h>
#include <math.h>

// Функция для интегрирования
double f(double x) {
    return log(x);
}

// Функция для вычисления интеграла методом средних прямоугольников
double integrate(double a, double b, double epsilon) {
    double S = 0.0;
    double previousS;
    int n = 1;

    do {
        previousS = S;
        S = 0.0;
        double h = (b - a) / n;

        for (int i = 0; i < n; i++) {
            double x_middle = a + (i + 0.5) * h;
            S += f(x_middle);
        }

        S *= h;
        n *= 2;
    } while (fabs(S - previousS) > epsilon);

    return S;
}

int main() {
    double a, b, epsilon;

    // Ввод пределов интегрирования и точности
    printf("Введите нижний предел интегрирования a (должен быть > 0): ");
    if (scanf("%lf", &a) != 1 || a <= 0) {
        printf("Ошибка: некорректное значение a. Должно быть числом > 0.\n");
        return 1;
    }

    printf("Введите верхний предел интегрирования b (должен быть > a): ");
    if (scanf("%lf", &b) != 1 || b <= a) {
        printf("Ошибка: некорректное значение b. Должно быть числом > a.\n");
        return 1;
    }

    printf("Введите точность epsilon (должна быть > 0): ");
    if (scanf("%lf", &epsilon) != 1 || epsilon <= 0) {
        printf("Ошибка: некорректное значение epsilon. Должно быть числом > 0.\n");
        return 1;
    }

    // Вычисление интеграла
    double result = integrate(a, b, epsilon);
    printf("Значение интеграла: %.15lf\n", result);

    return 0;
}
  



