#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int rows, int cols, int array[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%5d ", array[i][j]);
        }
        printf("\n");
    }
}
void reloadSrand(void) {
    srand((unsigned)time(NULL));
}
// # # # # # # #
// # ЗАДАЧА  1 #
// # # # # # # #
// Заполнить целочисленный массив размерностью 10x10 случайными числами из
// диапазона [-50, 250], распечатать полученный массив. Поменять местами
// максимальный и минимальный элементы массива, вывести их значения, начальные
// и конечные координаты (индекс строки, индекс столбца) на экран.
void task1() {
    int array[10][10];
    int max_val, min_val;
    int max_i = 0, max_j = 0, min_i = 0, min_j = 0;
    int temp;

    reloadSrand();

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            array[i][j] = -50 + rand() % 301;
        }
    }

    printf("Исходный массив:\n");
    printArray(10, 10, array);

    max_val = array[0][0];
    min_val = array[0][0];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (array[i][j] > max_val) {
                max_val = array[i][j];
                max_i = i;
                max_j = j;
            }
            if (array[i][j] < min_val) {
                min_val = array[i][j];
                min_i = i;
                min_j = j;
            }
        }
    }

    temp = array[max_i][max_j];
    array[max_i][max_j] = array[min_i][min_j];
    array[min_i][min_j] = temp;

    printf("Max elem: %d\nStart coords: [%d, %d]\nEnd coords: [%d, %d]\n", max_val, max_i, max_j, min_i, min_j);
    printf("Min elem: %d\nStart coords: [%d, %d]\nEnd coords: [%d, %d]\n", min_val, min_i, min_j, max_i, max_j);
}



// # # # # # # #
// # ЗАДАЧА  2 #
// # # # # # # #
// Задан двумерный массив А из N строк и М столбцов, N=7, M=5. Элементы массива
// – случайные числа из диапазона [-125, 20]. Найти и продублировать строку с
// наименьшей суммой элементов.
void task2() {
    int array[7][5];
    int new_array[8][5];
    int min_sum, min_index = 0;
    int current_sum;

    reloadSrand();

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 5; j++) {
            array[i][j] = -125 + rand() % 146;
        }
    }

    printf("Исходный массив:\n");
    printArray(7, 5, array);

    min_sum = 0;
    for (int j = 0; j < 5; j++) {
        min_sum += array[0][j];
    }

    for (int i = 1; i < 7; i++) {
        current_sum = 0;
        for (int j = 0; j < 5; j++) {
            current_sum += array[i][j];
        }
        if (current_sum < min_sum) {
            min_sum = current_sum;
            min_index = i;
        }
    }

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 5; j++) {
            new_array[i][j] = array[i][j];
        }
    }

    for (int j = 0; j < 5; j++) {
        new_array[7][j] = array[min_index][j];
    }

    printf("Строка с наименьшей суммой элементов (%d) находится в строке %d\n", min_sum, min_index);
    printf("Массив после дублирования строки:\n");
    printArray(7, 5, array);
}



// # # # # # # #
// # ЗАДАЧА  3 #
// # # # # # # #
// Дана матрица размером 10х10, заполненная случайными числами из диапазона от -
// 35 до 35 включительно. Написать программу, которая переставляет строки и
// столбцы матрицы таким образом, чтобы наименьший элемент (или один из них)
// оказался в верхнем правом углу.
void swapRow(int array[10][10], int row1, int row2) {
    int temp;
    for (int col = 0; col < 10; col++) {
        temp = array[row1][col];
        array[row1][col] = array[row2][col];
        array[row2][col] = temp;
    }
}

void swapCol(int array[10][10], int col1, int col2) {
    int temp;
    for (int row = 0; row < 10; row++) {
        temp = array[row][col1];
        array[row][col1] = array[row][col2];
        array[row][col2] = temp;
    }
}

void task3(void) {
    int array[10][10];
    reloadSrand();

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            array[i][j] = rand() % 71 - 35;
        }
    }

    printf("Исходный массив:\n");
    printArray(10, 10, array);

    int min = array[0][0];
    int minRow = 0, minCol = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (array[i][j] < min) {
                min = array[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }
    printf("Mininimal elem: %d\nCoords: [%d, %d]\n", min, minRow+1, minCol+1);

    swapRow(array, minRow, 0);    
    swapCol(array, minCol, 9); 

    printf("Массив после:\n");
    printArray(10, 10, array);
}



int main(void) {
    task3();
}