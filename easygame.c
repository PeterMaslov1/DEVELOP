#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> // Для проверки ввода

int main() {
  srand(time(NULL));
  int secret_number = rand() % 100 + 1;
  int guess, attempts = 0;

  printf("Добро пожаловать в игру 'Угадай число'!\n");
  printf("Я загадал число от 1 до 100. Угадайте его за 10 попыток.\n");

  do {
    printf("Введите ваше число: ");
    if (scanf("%d", &guess) != 1) { // Проверка на корректный ввод числа
      printf("Некорректный ввод. Введите целое число.\n");
      while (getchar() != '\n'); // Очистка буфера ввода
      continue;
    }

    attempts++;

    if (guess < secret_number) {
      printf("Моё число больше.\n");
    } else if (guess > secret_number) {
      printf("Моё число меньше.\n");
    } 
  } while (guess != secret_number && attempts < 10);

  if (guess == secret_number) {
    printf("Поздравляю! Вы угадали за %d попыток!\n", attempts);
  } else {
    printf("Извините, но у вас закончились попытки. Моё число было %d.\n", secret_number);
  }

  return 0;
}