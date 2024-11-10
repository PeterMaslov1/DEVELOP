#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define PI 3.14159265358979323846

int main() {
  char operation;
  double num1, num2, result;

  while (1) {
    printf("Введите операцию (+, -, *, /, ^, sin, cos, tan, q): ");
    scanf(" %c", &operation);

    if (operation == 'q') {
      break;
    }

    if (operation == 's' || operation == 'c' || operation == 't') {
      printf("Введите число: ");
      if (scanf("%lf", &num1) != 1) {
        printf("Некорректный ввод!\n");
        while (getchar() != '\n'); 
        continue; 
      }
    } else {
      printf("Введите первое число: ");
      if (scanf("%lf", &num1) != 1) {
        printf("Некорректный ввод!\n");
        while (getchar() != '\n'); 
        continue; 
      }
      printf("Введите второе число: ");
      if (scanf("%lf", &num2) != 1) {
        printf("Некорректный ввод!\n");
        while (getchar() != '\n'); 
        continue; 
      }
    }

    switch (operation) {
      case '+':
        result = num1 + num2;
        break;
      case '-':
        result = num1 - num2;
        break;
      case '*':
        result = num1 * num2;
        break;
      case '/':
        if (num2 == 0) {
          printf("Ошибка: Делить на ноль нельзя!\n");
          continue; 
        }
        result = num1 / num2;
        break;
      case '^':
        result = pow(num1, num2);
        break;
      case 's':
        result = sin(num1 * PI / 180); 
        break;
      case 'c':
        result = cos(num1 * PI / 180);
        break;
      case 't':
        result = tan(num1 * PI / 180);
        break;
      default:
        printf("Неверная операция!\n");
        continue;
    }

    printf("Результат: %lf\n", result);
  }

  printf("До свидания!\n");
  return 0;
}