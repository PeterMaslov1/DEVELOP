#include <stdio.h>
#include <math.h>

int main() {
    char operator;
    double num1, num2, result;

    printf("Введите оператор (+, -, *, /, sin, cos): ");
    scanf("%c", &operator);

    printf("Введите два числа: ");
    scanf("%lf %lf", &num1, &num2);

    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("Результат: %.2f\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Результат: %.2f\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Результат: %.2f\n", result);
            break;
        case '/':
            if (num2 == 0) {
                printf("Ошибка: деление на 0\n");
                return 1;
            }
            result = num1 / num2;
            printf("Результат: %.2f\n", result);
            break;
        case 'sin':
            result = sin(num1);
            printf("Синус %.2f = %.2f\n", num1, result);
            break;
        case 'cos':
            result = cos(num1);
            printf("Косинус %.2f = %.2f\n", num1, result);
            break;
        default:
            printf("Ошибка: неправильный оператор\n");
            return 1;
    }

    return 0;
}