// ╔═════════════════════════════════════════════════════════════════════════════╗
//   Authors:        Diyor Haydarov [alyreniko]
//   Date:           April 11, 2025
//   License:        MIT License
// ╚═════════════════════════════════════════════════════════════════════════════╝

#include <strings.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int createArray(int **arr, int *size) {
    printf("write size array: ");
    scanf("%d", size);
    if (size <= 0) return 1;
    *arr = malloc(*size * sizeof(int));
    if (!*arr) {
        return 1;
    }
    return 0;
}

int randomFillArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    return 0;
}

int findLastMinIndex(int *arr, int size) {
    int min = arr[0];
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] <= min) {
            min = arr[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

int searchCountEndsInFive(int *arr, int size) {
    int countEndsInFive = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 10 == 5) {
            countEndsInFive++;
        }
    }
    return countEndsInFive;
}

int searchCountMaxElement(int *arr, int size) {
    int max = arr[0];
    int maxCount = 0;

    return maxCount;
}

// Дан массив целых чисел, размер массива вводится с клавиатуры.
// Посчитать сумму элементов, имеющих четные индексы и
// расположенных после минимального элемента или последнего
// вхождения минимального элемента, если их несколько.
int task1(int *arr, int size) {
    int minIndex = findLastMinIndex(arr, size) + 1;
    int sum = 0;
    for (int i = minIndex; i < size; i++) {
        if (i % 2 == 0) {
            sum += arr[i];
        }
    }
    return sum;
}

// Дан массив целых чисел, размер массива вводится с клавиатуры. Перед
// каждым элементом массива, заканчивающимся на цифру 5 вставить
// число 20, затем в полученном массиве удалить все элементы равные
// максимальному элементу. Вывести промежуточное и конечное
// состояния массива на экран.
int task2(int *arr, int size) {
    int maxElem = arr[0];
    int maxElemCount = 0;
    int countEndsInFive = 0;

    // ищем максимальный элемент и кол-во заканчивающихся на 5
    for (int i = 0; i < size; i++) {
        if (arr[i] % 10 == 5) {
            countEndsInFive++;
        }
        if (arr[i] > maxElem) {
            maxElem = arr[i];
        }
    }

    // ищем кол-во максимальных
    for (int i = 0; i < size; i++) {
        if (arr[i] == maxElem) {
            maxElemCount++;
        }
    }

    //
    int writeIndex = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] != maxElem) {
            arr[writeIndex++] = arr[i];
        }
    }

    printArray(arr, size - maxElemCount);

    // выделяем память под новый массив
    int newArrSize = size + countEndsInFive - maxElemCount;
    arr = (int *)realloc(arr, newArrSize * sizeof(int));
    if (!arr) {
        printf("memory error\n");
        return 1;
    }

    // вставляем 20
    int readIndex = writeIndex - 1;
    writeIndex = newArrSize - 1;
    while (readIndex >= 0) {
        arr[writeIndex--] = arr[readIndex];
        if (arr[readIndex] % 10 == 5) {
            arr[writeIndex--] = 20;
        }
        readIndex--;
    }

    printArray(arr, newArrSize);

    return 0;
}

// С клавиатуры вводится последовательность целых чисел. Первый
// элемент последовательности – количество этих чисел, следующие –
// элементы массива (напр. 4 1 67 2 23). Заменить в данном массиве все
// элементы, начинающиеся с цифры 1, на значение максимального
// элемента и записать результат в новый массив.
int startsWithOne(int num) {
    char buffer[20];
    sprintf(buffer, "%d", abs(num));
    return buffer[0] == '1';
}

int task3() {
    int count;
    scanf("%d", &count);

    int *arr = malloc(count * sizeof(int));
    for (int i = 0; i < count; i++) {
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    for (int i = 1; i < count; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    for (int i = 0; i < count; i++) {
        if (startsWithOne(arr[i])) {
            arr[i] = max;
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}

int main() {
    srand((unsigned int)time(NULL));

    int size;
    int *arr;
    if (createArray(&arr, &size)) {
        printf("error creating array\n");
        return 1;
    }

    // randomFillArray(arr, size);
    // printArray(arr, size);
    // printf("%d\n", task1(arr, size));

    // randomFillArray(arr, size);
    // printArray(arr, size);
    // task2(arr, size);

    task3(); // не передаём аргументы т.к. в этой задаче своеобразное создание массива

    free(arr);
    return 0;
}
