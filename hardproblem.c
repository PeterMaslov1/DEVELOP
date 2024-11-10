#include <stdio.h>
#include <stdlib.h>

void spiralOrder(int **matrix, int rows, int cols, int *result, int *resultIndex) {
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {
        // Move right
        for (int i = left; i <= right; i++) {
            result[*resultIndex] = matrix[top][i];
            (*resultIndex)++;
        }
        top++;

        // Move down
        for (int i = top; i <= bottom; i++) {
            result[*resultIndex] = matrix[i][right];
            (*resultIndex)++;
        }
        right--;

        if (top <= bottom && left <= right) {
            // Move left
            for (int i = right; i >= left; i--) {
                result[*resultIndex] = matrix[bottom][i];
                (*resultIndex)++;
            }
            bottom--;

            // Move up
            for (int i = bottom; i >= top; i--) {
                result[*resultIndex] = matrix[i][left];
                (*resultIndex)++;
            }
            left++;
        }
    }
}

int main() {
    int rows = 3, cols = 3;
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Заполняем матрицу (Пример 1)
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = data[index++];
        }
    }

    int resultSize = rows * cols;
    int *result = (int *)malloc(resultSize * sizeof(int));
    int resultIndex = 0;

    spiralOrder(matrix, rows, cols, result, &resultIndex);

    printf("Матрица в спиральном порядке: ");
    for (int i = 0; i < resultSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Освобождаем память
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(result);

    return 0;
}