#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void append(int *array, int *len, int item) {
    (*len)++;
    array = (int *)realloc(array, (*len) * sizeof(int));
    if (!array) {
        perror("memory error");
        return;
    }
    array[*len - 1] = item;
}

int insert(int **array, int *len, int item, int index) {
    if (index < 0 || index > *len) return -1;

    int *new_array = realloc(*array, (*len + 1) * sizeof(int));
    if (!new_array) {
        perror("memory error");
        return -1;
    }

    *array = new_array;
    for (int i = *len; i > index; i--) {
        (*array)[i] = (*array)[i - 1];
    }

    (*array)[index] = item;
    (*len)++;
    return 0;
}

int remove_(int *array, int *len, int item) {
    bool isFind = false;
    for (int i = 0; i < *len; i++) {
        if (array[i] == item && isFind == false) {
            isFind = true;
        }
        if (isFind == true && i != (*len - 1)) {
            array[i] = array[i + 1];
        }
        if (i == (*len - 1)) {
            (*len)--;
            array = (int *)realloc(array, (*len) * sizeof(int));
            if (!array) {
                perror("memory error");
                return -1;
            }
        }
    }
    return 0;
}

void clear(int **array, int *len) {
    *len = 0;
    free((*array));
    (*array) = NULL;
}

int index_(int *array, int len, int item) {
    for (int i = 0; i < len; i++) {
        if (array[i] == item) return i;
    }
    return -1;
}

int pop(int *array, int *len, int index, bool *flag) {
    if (index < 0 || index >= *len) {
        *flag = false;
        return -1;
    }

    int num = array[index];
    for (int i = index; i < *len - 1; i++) {
        array[i] = array[i + 1];
    }

    (*len)--;

    *flag = true;
    return num;
}

int count(int *array, int len, int item) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (array[i] == item) count++;
    }
    return count;
}

void reverse(int *array, int len) {
    for (int i = 0; i < len / 2; i++) {
        int j = len - 1 - i;
        if (i != j) {
            array[i] ^= array[j];
            array[j] ^= array[i];
            array[i] ^= array[j];
        }
    }
}

void printArray(int *array, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array_len, range_start, range_end;
    printf("write len array: "); scanf("%d", &array_len);
    if (array_len <= 0) {printf("len less than 1"); return -1;}

    printf("start generation: "); scanf("%d", &range_start);
    printf("end generation: "); scanf("%d", &range_end);
    if (range_end < range_start) {printf("the end is less than the beginning"); return -1;}

    int *array = (int *)calloc(array_len, sizeof(int));
    if (!array) {perror("memory error"); return -1;}

    srand(time(NULL));
    for (int i = 0; i < array_len; i++) { array[i] = range_start + rand() % (range_end - range_start + 1);}

    printf("generated array:\n");
    printArray(array, array_len);

    int appendint = 27;
    append(array, &array_len, appendint);
    printf("append %d:\n", appendint);
    printArray(array, array_len);

    int insertindex = 3;
    int insertint = 76;
    insert(&array, &array_len, insertint, insertindex);
    printf("insert %d into [%d]:\n", insertint, insertindex);
    printArray(array, array_len);

    printf("count number %d: %d\n", insertint, count(array, array_len, appendint));
    printf("index number %d: [%d]\n", appendint, index_(array, array_len, appendint));

    int removeint = 13;
    remove_(array, &array_len, removeint) ? printf("array after remove %d:\n", removeint) : printf("%d not found\n", removeint);

    bool flag = false; int popindex = 0;
    int popint = pop(array, &array_len, popindex, &flag);
    printf("pop %d into [%d]:\n", popint, popindex);
    printArray(array, array_len);

    reverse(array, array_len);
    printf("reverse array:\n");
    printArray(array, array_len);

    return 0;
}
