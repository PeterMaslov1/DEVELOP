#include <stdio.h>

double calculate_series(double E) {
    double sum = 0.0;      
    double term = 1.0;     
    int n = 1;

    while (term >= E) {     
        term /= n;         
        sum += term;       
        n++;
    }
    
    return sum;
}

int main() {
    double E;
    
    
    printf("Введите значение точности E (например, 0.000001): ");
    if (scanf("%lf", &E) != 1 || E <= 0) {
        printf("Ошибка: введите положительное число для E.\n");
        return 1;
    }

    
    double result = calculate_series(E);
    printf("Сумма ряда с точностью до %lf: %.15lf\n", E, result);

    return 0;
}