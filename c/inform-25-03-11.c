// ╔═════════════════════════════════════════════════════════════════════════════╗
//   Authors:        Diyor Haydarov [alyreniko]
//   Date:           March 11, 2025
//   License:        MIT License
// ╚═════════════════════════════════════════════════════════════════════════════╝

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// # # # # # # #
// # ЗАДАЧА  1 #
// # # # # # # #
// Заполнить одномерный целочисленный массив из 10 элементов и вывести на экран.
// a) значения элементов ввести с клавиатуры,
void task1a(void) {
    const int N = 10;
    int A[N], i;
    printf("Введите 10 элементов массива:\n");
    for(i=0; i < N; i++) {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }
    for (i = 0; i < N; i++ ) {
        printf("A[%d] = %d; ", i, A[i]);
    }
}
// b) заполнить случайными числами из диапазона [0, 50).
void task1b(void) {
    srand((unsigned)time(NULL));
    const int N = 10;
    int A[N], i;
    for (i = 0; i < N; i++ ) {
        A[i] = rand()%50;
        printf("A[%d] = %d; ", i, A[i]);
    }
}

// # # # # # # #
// # ЗАДАЧА  2 #
// # # # # # # #
// Дана последовательность целых чисел длины N, заданных случайным образом из
// диапазона от -50 до 70 включительно. Поменять местами первый и максимальный
// элементы этой последовательности. Решить задачу для N=10.
void task2(void) {
    srand((unsigned)time(NULL));
    const int N = 10;
    int A[N], i, max_index = 0, max_value = -50, temp;
    printf("Исходный массив:\n");
    for (i = 0; i < N; i++ ) {
        A[i] = (rand() % (70 - -50 + 1)) + -50;
        printf("A[%d] = %3d; ", i, A[i]);
    }
    for(i=0; i<N; i++) {
        if (A[i] > max_value) {
            max_value = A[i];
            max_index = i;
        }
    }
    temp = A[0];
    A[0] = max_value;
    A[max_index] = temp;
    printf("\nИзмененный массив:\n");
    for (i = 0; i < N; i++ ) {
        printf("A[%d] = %3d; ", i, A[i]);
    }
}

// # # # # # # #
// # ЗАДАЧА  3 #
// # # # # # # #
// Дан массив из 10 целых чисел, заданных случайно из диапазона от 45 до 95.
// Посчитайте сумму четных элементов, расположенных после минимального
// элемента или первого вхождения минимального элемента, если их несколько.
void task3(void) {
    srand((unsigned)time(NULL));
    const int N = 10;
    int A[N], i, min_index = 0, min_value = 95, sum = 0;
    printf("Исходный массив:\n");
    for (i = 0; i < N; i++ ) {
        A[i] = (rand() % (95 - 45 + 1)) + 45;
        printf("A[%d] = %3d; ", i, A[i]);
    }
    for(i=0; i<N; i++) {
        if (A[i] < min_value) {
            min_value = A[i];
            min_index = i;
        }
    }
    for(i=min_index; i<N; i++) {
        if (A[i] % 2 == 0) {
            sum += A[i];
        }
    }
    printf("\nСумма четных элементов: %d\n", sum);
}

int main(void) {
    // task1a();
    // task1b();
    // task2();
    // task3();
    return 0;
}
