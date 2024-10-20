#include <stdio.h>

double factorial(int n) {
    double fact = 1.0;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    double E, term, sum = 0.0;
    int n = 1;

    printf("Введите значение точности E: ");
    scanf("%lf", &E);

    do {
        term = 1.0 / factorial(n);
        sum += term;
        n++;
    } while (term >= E);

    printf("Сумма ряда: %lf\n", sum);

    return 0;
}