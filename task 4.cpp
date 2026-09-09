#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");
    printf("Сумма положительных значений в каждом столбце двумерного массива\n\n");

    int rows = 3, cols = 4;
    int **arr;  
    int i, j;

    
    arr = (int**)malloc(rows * sizeof(int*));
    for (i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }

    srand((unsigned int)time(NULL));

    printf("Исходный массив 3x4:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            arr[i][j] = rand() % 91 - 50;  
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\nСумма положительных элементов по столбцам:\n");
    for (j = 0; j < cols; j++) {
        int sum = 0;
        for (i = 0; i < rows; i++) {
            if (arr[i][j] > 0) { 
                sum += arr[i][j];
            }
        }
        printf("Столбец %d: %d\n", j + 1, sum);
    }

    printf("\nСумма положительных элементов по строкам:\n");
    for (i = 0; i < rows; i++) {
        int sum = 0;
        for (j = 0; j < cols; j++) {
            if (arr[i][j] > 0) {  
                sum += arr[i][j];
            }
        }
        printf("Строка %d: %d\n", i + 1, sum);
    }

    
    for (i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}