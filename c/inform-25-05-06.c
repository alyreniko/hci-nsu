// ╔═════════════════════════════════════════════════════════════════════════════╗
//   Authors:        Diyor Haydarov [alyreniko]
//   Date:           May 6, 2025
//   License:        MIT License
// ╚═════════════════════════════════════════════════════════════════════════════╝

#include <stdio.h>
#include <stdlib.h>

// Дан файл f содержащий целые числа. Записать в файл f1
// компоненты исходного файла, запись числа которых состоит только
// из нечетных цифр.
int isAllOddDigits(int num) {
    char str[20];
    sprintf(str, "%d", num);

    int start = 0;
    if (str[0] == '-') {
        start++;
    }

    for (int i = start; str[i]; i++) {
        if ((str[i] - '0') % 2 == 0) {
            return 0;
        }
    }
    return 1;
}

void task1() {
    FILE *f = fopen("f.txt", "r");
    FILE *f1 = fopen("f1.txt", "w");

    if (!f || !f1) {
        perror("error");
        return;
    }

    int num;
    while (fscanf(f, "%d", &num) == 1) {
        if (isAllOddDigits(num)) {
            fprintf(f1, "%d\n", num);
        }
    }

    fclose(f);
    fclose(f1);
}

// Дан файл f содержащий целые числа. Количество чисел в файле
// кратно 4. Первые два числа задают координаты (в декартовой
// системе) левого нижнего угла прямоугольника, следующие два
// числа – правого верхнего (стороны прямоугольника параллельны
// осям координат). Записать в файл f1 координаты только квадратов.
void task2() {
    FILE *f = fopen("f.txt", "r");
    FILE *f1 = fopen("f1.txt", "w");

    if (!f || !f1) {
        perror("error");
        return;
    }

    int x1, y1, x2, y2;
    while (fscanf(f, "%d %d %d %d", &x1, &y1, &x2, &y2) == 4) {
        if (abs(x2 - x1) == abs(y2 - y1) && abs(x2 - x1) != 0) {
            fprintf(f1, "%d %d %d %d\n", x1, y1, x2, y2);
        }
    }

    fclose(f);
    fclose(f1);
}

// Дан файл f1 содержащий матрицу целых чисел 10х10 и файл f2
// содержащий 10 целых чисел. Изменить данные в файле f
// следующим образом: если в матрице есть столбец, количество
// нечетных элементов которого равна количеству нечетных чисел
// файла f2, тогда вставить данные из файла f2 перед данным
// столбцом в матрице со сдвигом остальных столбцов.
// Дополнительных файлов не использовать.
void task3() {
    FILE *f1 = fopen("f1.txt", "r+");
    FILE *f2 = fopen("f2.txt", "r");

    if (!f1 || !f2) {
        perror("error");
        return;
    }

    int oddCountColumn = 0;
    int oddCountF2 = 0;

    // чтение матрицы
    int matrix[10][20];
    int columns = 10;
    for (int row = 0; row < columns; row++)
        for (int col = 0; col < columns; col++)
            fscanf(f1, "%d", &matrix[row][col]);

    // чтение цифр из f2
    int numbersF2[10];
    for (int i = 0; i < 10; i++) {
        fscanf(f2, "%d", &numbersF2[i]);
        oddCountF2 += numbersF2[i] % 2;
    }

    for (int col = 0; col < columns; col++) {
        int oddCountColumn = 0;
        for (int row = 0; row < 10; row++)
            oddCountColumn += matrix[row][col] % 2;
        if (oddCountColumn == oddCountF2) {
            for (int move_col = columns++; move_col > col; move_col--)
                for (int row = 0; row < 10; row++)
                    matrix[row][move_col] = matrix[row][move_col - 1];
            for (int row = 0; row < 10; row++)
                matrix[row][col] = numbersF2[row];
            col++;
        }
    }

    // перезапись матрицы в f1
    rewind(f1);
    for (int row = 0; row < 10; row++, fprintf(f1, "\n"))
        for (int col = 0; col < columns; col++)
            fprintf(f1, "%d ", matrix[row][col]);

    fclose(f1);
    fclose(f2);
}

int main() {
    // task1();
    // task2();
    task3();
    return 0;
}
