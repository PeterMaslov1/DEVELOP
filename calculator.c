#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    printf("Добро пожаловать в продвинутый калькулятор на C!\n");
    printf("Доступные операции: +, -, *, /, **, sin, cos\n");
    printf("Введите 'выход' для завершения\n");

    while (1) {
        char expression[100];
        printf("Введите выражение: ");
        scanf("%s", expression);

        if (strcmp(expression, "выход") == 0) {
            printf("До свидания!\n");
            break;
        }

        double result = 0.0;
        char* endptr;
        double operand1 = strtod(expression, &endptr);

        if (endptr == expression) {
            printf("Неверный ввод. Пожалуйста, попробуйте еще раз.\n");
            continue;
        }

        char op = *endptr;
        double operand2 = strtod(endptr + 1, NULL);

        switch (op) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                if (operand2 == 0) {
                    printf("Ошибка: деление на ноль\n");
                    continue;
                }
                result = operand1 / operand2;
                break;
            case '^':
                result = pow(operand1, operand2);
                break;
            case 's':
                result = sin(operand1 * M_PI / 180.0);
                break;
            case 'c':
                result = cos(operand1 * M_PI / 180.0);
                break;
            default:
                printf("Неизвестная операция. Пожалуйста, попробуйте еще раз.\n");
                continue;
        }

        printf("Результат: %.2f\n", result);
    }

    return 0;
}
