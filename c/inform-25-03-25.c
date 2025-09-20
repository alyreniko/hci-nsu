#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y) {
    return (!y) ? gcd(y, x % y) : x;
}

void reduce_fraction(int *a, int *b) {
    int gcd_v = gcd(*a, *b);
    if (gcd_v != 0) {
        *a /= gcd_v;
        *b /= gcd_v;
    }
}

int abs_arr(int arr[], int n) {
    int count = 0;
    for(int i=0; i<n; i++) {
        if(arr[i]<0){
            arr[i] = abs(arr[i]);
            count++;
        }
    }
    return count;
}

void swap(int *array, int len, int indexA, int indexB) {
    int temp = array[indexA];
    array[indexA] = array[indexB];
    array[indexB] = temp;
}

int min_max(int *array, int len, int flag) {
    int min = array[0];
    int max = array[0];
    int max_index = 0;
    int min_index = 0;
    for(int i=0; i<len; i++){
        if(array[i] < min){
            min = array[i];
            min_index = i;
        }
        if(array[i] > max){
            max = array[i];
            max_index = i;
        }
    }
    return (!flag) ? min_index : max_index;
}

void sum_digits(int * x) {
    int num = *x;
    int sum = 0;
    if (num < 0) num = -num;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    *x = sum;
}


int sequence_multipliers(int x) {
    if (x >= 1000000) return -1;

    int k = 1;
    while (k * (k + 1) * (k + 2) <= x) {
        if (k * (k + 1) * (k + 2) == x) {
            return k;
        }
        k++;
    }
    return -1;
}

int main(void) {
// ЗАДАЧА 1 / 2
    // int x, y;
    // scanf("%d", &x);
    // scanf("%d", &y);
    // reduce_fraction(&x, &y);
    // printf("%d %d\n", x, y);
    // printf("%d\n", gcd(x, y));

// ЗАДАЧА 3
    // int arr[] = {10, -93, 22, 75, 12};
    // int count = abs_arr(arr, 5);
    // printf("%d ", count);

// ЗАДАЧА 4
    // int arr[] = {10, -93, 22, 75, 12};
    // swap(arr, 5, 1, 3);

// ЗАДАЧА 5
    // int flag;
    // int arr[] = {10, -93, 22, 75, 12};
    // scanf("%d", &flag);
    // printf("result: %d\n", min_max(arr, 5, flag));

// ЗАДАЧА 6
    // int x;
    // scanf("%d", &x);
    // sum_digits(&x);
    // printf("%d\n", x);

// ЗАДАЧА 7
    // int x;
    // scanf("%d", &x);
    // x = sequence_multipliers(x);
    // printf("%d\n", x);

// ВЫВОД МАССИВА
    // for (int i = 0; i < 5; i++) {
    //     printf("%d ", arr[i]);
    // }
    return 0;
}