#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_EXPR_LEN 1000

// Прототипы функций
double evaluate_expression(const char **expression, int *error);
double evaluate_term(const char **expression, int *error);
double evaluate_factor(const char **expression, int *error);
double parse_number(const char **expression, int *error);
double parse_function(const char **expression, int *error);
int is_valid_expression(const char *expression);

int main() {
    char expression[MAX_EXPR_LEN];
    int error = 0;

    printf("Введите выражение для вычисления (поддерживаются +, -, *, /, ^, sin, cos, tan, скобки): ");
    fgets(expression, MAX_EXPR_LEN, stdin);
    expression[strcspn(expression, "\n")] = '\0';

    if (!is_valid_expression(expression)) {
        printf("Ошибка: выражение содержит недопустимые символы.\n");
        return 1;
    }

    const char *expr_ptr = expression;
    double result = evaluate_expression(&expr_ptr, &error);

    if (error || *expr_ptr != '\0') {
        printf("Ошибка: некорректное выражение.\n");
    } else {
        printf("Результат: %.10f\n", result);
    }

    return 0;
}

// Проверка на допустимые символы
int is_valid_expression(const char *expression) {
    for (const char *p = expression; *p != '\0'; p++) {
        if (!isdigit(*p) && !isspace(*p) && !strchr("+-*/^()sinco", *p)) {
            return 0; // Найден недопустимый символ
        }
    }
    return 1; // Все символы допустимы
}

double evaluate_expression(const char **expression, int *error) {
    double result = evaluate_term(expression, error);

    while (**expression == '+' || **expression == '-') {
        char op = *(*expression)++;
        double term = evaluate_term(expression, error);
        if (*error) return 0;

        result = (op == '+') ? result + term : result - term;
    }

    return result;
}

double evaluate_term(const char **expression, int *error) {
    double result = evaluate_factor(expression, error);

    while (**expression == '*' || **expression == '/') {
        char op = *(*expression)++;
        double factor = evaluate_factor(expression, error);
        if (*error) return 0;

        if (op == '*') {
            result *= factor;
        } else {
            if (factor != 0) {
                result /= factor;
            } else {
                *error = 1;
                printf("Ошибка: деление на ноль.\n");
                return 0;
            }
        }
    }

    return result;
}

double evaluate_factor(const char **expression, int *error) {
    double result;

    if (**expression == '-') {
        (*expression)++;
        result = -evaluate_factor(expression, error);
    } else if (**expression == '(') {
        (*expression)++;
        result = evaluate_expression(expression, error);
        if (**expression == ')') {
            (*expression)++;
        } else {
            *error = 1;
            printf("Ошибка: пропущена закрывающая скобка.\n");
        }
    } else if (isalpha(**expression)) {
        result = parse_function(expression, error);
    } else {
        result = parse_number(expression, error);
    }

    if (**expression == '^') {
        (*expression)++;
        double exponent = evaluate_factor(expression, error);
        result = pow(result, exponent);
    }

    return result;
}

double parse_number(const char **expression, int *error) {
    char *end;
    double number = strtod(*expression, &end);

    if (*expression == end) {
        *error = 1;
        printf("Ошибка: ожидалось число.\n");
        return 0;
    }

    *expression = end;
    return number;
}

double parse_function(const char **expression, int *error) {
    char func[4] = {0};
    int i = 0;

    while (isalpha(**expression) && i < 3) {
        func[i++] = *(*expression)++;
    }

    if (**expression == '(') {
        (*expression)++;
        double arg = evaluate_expression(expression, error);

        if (**expression == ')') {
            (*expression)++;
        } else {
            *error = 1;
            printf("Ошибка: пропущена закрывающая скобка в функции.\n");
            return 0;
        }

        if (strcmp(func, "sin") == 0) return sin(arg);
        else if (strcmp(func, "cos") == 0) return cos(arg);
        else if (strcmp(func, "tan") == 0) return tan(arg);
        else {
            *error = 1;
            printf("Ошибка: неизвестная функция '%s'.\n", func);
            return 0;
        }
    } else {
        *error = 1;
        printf("Ошибка: ожидается '(' после имени функции.\n");
        return 0;
    }
}