#include <stdio.h>
#include <math.h>

double func(double x) {
    return log(x);
}

double midpoint_rectangles_method(double a, double b, double E) {
    int n = 1; 
    double h, sum, prev_sum = 0.0;

    do {
        prev_sum = sum;
        sum = 0.0;
        h = (b - a) / n;

        for (int i = 0; i < n; i++) {
            sum += func(a + (i + 0.5) * h); 
        }
        sum *= h;

        n *= 2; 
    } while (fabs(sum - prev_sum) >= E); 

    return sum;
}

int main() {
    double a, b, E, result;

    printf("Введите пределы интегрирования (a и b): ");
    scanf("%lf %lf", &a, &b);

    printf("Введите значение точности E: ");
    scanf("%lf", &E);

    if (a <= 0 || b <= 0 || a >= b) {
        printf("Ошибка: Пределы интегрирования должны быть положительными и a должно быть меньше b.\n");
        return 1;
    }

    result = midpoint_rectangles_method(a, b, E);

    printf("Значение интеграла: %lf\n", result);

    return 0;
}