// ╔═════════════════════════════════════════════════════════════════════════════╗
//   Authors:        Diyor Haydarov [alyreniko]
//   Date:           March 4, 2025
//   License:        MIT License
// ╚═════════════════════════════════════════════════════════════════════════════╝

#include <stdio.h>
#include <math.h>

// # # # # # # #
// # ЗАДАЧА  1 #
// # # # # # # #
// Дано натуральное число N. Получить новое число М, которое
// образуется из числа N путем замены последней цифры на
// значение наибольшей цифры в записи числа N.
// Пример: если N =128452, то M = 128458.
void task1(void) {
    int n, m, max_digit, last_digit;
    scanf("%d", &n);
    while (n<=0) {
        scanf("%d", &n);
    }
    max_digit = -1;
    m = n;
    while (m > 0) {
        int digit = m % 10;
        if (digit > max_digit) {
            max_digit = digit;
        }
        m /= 10;
    }
    m = n;
    last_digit = n % 10;
    m -= last_digit;
    m += max_digit;

    printf("%d\n", m);
}

// # # # # # # #
// # ЗАДАЧА  2 #
// # # # # # # #
// Последовательность Хэмминга образуют натуральные числа, не
// имеющие других простых делителей, кроме 2, 3 и 5. Найти
// первый элемент, больший данного числа M, а также номер этого
// элемента в последовательности.
int is_hamming(int num) {
    while (num % 2 == 0) num /= 2;
    while (num % 3 == 0) num /= 3;
    while (num % 5 == 0) num /= 5;
    return (num == 1);
}

void task2(void) {
    int m;
    int count = 1;
    int num = 1;

    scanf("%d", &m);

    while (1) {
        if (is_hamming(num)) {
            if (num > m) {
                printf("Первое число: %d\n", num);
                printf("Номер в последовательности: %d\n", count);
                break;
            }
            count++;
        }
        num++;
    }
}

// # # # # # # #
// # ЗАДАЧА  3 #
// # # # # # # #
// Вычислить значение выражения
void task3(void) {
    int n, k;
    double sum = 0.0;
    scanf("%d", &n);
    for(k = 1; k <= n; k++) {
        sum += pow(-1, k) / ((2 * k + 1) * k);
    }
    printf("%.2f", sum);
}

// # # # # # # #
// # ЗАДАЧА  4 #
// # # # # # # #
// Выведите на экран все точные квадраты натуральных чисел, не
// превосходящие данного числа N. Выводить квадраты следует от
// меньшего к большему.
void task4() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i * i <= n; i++) {
        printf("%d ", i * i);
    }
}



// # # # # # # #
// # ЗАДАЧА  5 #
// # # # # # # #
// Дано целое число, не меньшее 2. Выведите его наименьший
// натуральный делитель, отличный от 1.
void task5() {
    int n;
    scanf("%d", &n);

    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            printf("%d\n", i);
            break;
        }
    }
}


// ЗАПУСК
int main(void) {
    // task1();
    // task2();
    // task3();
    // task4();
    // task5();
    return 0;
}
