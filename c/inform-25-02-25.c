#include <stdio.h>
#include <math.h>
#include <stdlib.h>



// # # # # # # #
// # ЗАДАЧА  1 #
// # # # # # # #
// Даны две переменные целого типа: A и B. 
// Если их значения не равны, то присвоить каждой переменной 
// большее из этих значений, а если равны, то присвоить 
// переменным нулевые значения. Вывести новые значения переменных A и B.
void task1(void)
{
    int a, b, max;
    printf("Введите значение A: "); scanf("%d", &a);
    printf("Введите значение B: "); scanf("%d", &b);
    if (a != b)
    {
        max = (a > b) ? a : b;
        a = b = max;
    } else {
        a = b = 0;
    }
    
    printf("A = %d, B = %d\n", a, b);
}



// # # # # # # #
// # ЗАДАЧА  2 #
// # # # # # # #
// Даны целочисленные координаты трех вершин прямоугольника,
// стороны которого параллельны координатным осям. 
// Найти координаты его четвертой вершины.
void task2(void)
{
    int x1, y1, x2, y2, x3, y3, x4, y4;
    printf("Введите координату первой вершины:\n"); scanf("%d %d", &x1, &y1);
    printf("Введите координату второй вершины:\n"); scanf("%d %d", &x2, &y2);
    printf("Введите координату третьей вершины:\n"); scanf("%d %d", &x3, &y3);

    x4 = x1 ^ x2 ^ x3;
    y4 = y1 ^ y2 ^ y3;

    printf("Координаты четвертой вершины: %d %d\n", x4, y4);
}



// # # # # # # #
// # ЗАДАЧА  3 #
// # # # # # # #
// Даны координаты двух различных полей шахматной доски 
// x1, y1, x2, y2 , x3, y3 (целые числа, лежащие в диапазоне 1–8). 
// На поле (x1, y1) расположена белая фигура, на поле (x2, y2) – черная. 
// Определить, может ли белая фигура пойти на поле (x3, y3), 
// не попав при этом под удар черной фигуры. 
// Рассмотреть следующие варианты сочетаний белой и черной фигур:
// а) ладья и ладья     б) король и ферзь
int validate(int x, int y) {
    if (x >= 1 && x <= 8 && y >= 1 && y <= 8) return 1;
    printf("Ошибка: обе координаты должны быть от 1 до 8.\n");
    return 0;
}

int is_rook_move_valid(int x1, int y1, int x3, int y3) {
    return (x1 == x3 || y1 == y3);
}

int is_king_move_valid(int x1, int y1, int x3, int y3) {
    return (abs(x1 - x3) <= 1 && abs(y1 - y3) <= 1);
}

int is_black_rook_threat(int x2, int y2, int x3, int y3) {
    return (x2 == x3 || y2 == y3);
}
int is_black_queen_threat(int x2, int y2, int x3, int y3) {
    return (x2 == x3 || y2 == y3 || abs(x2 - x3) == abs(y2 - y3));
}

void mode1(int x1, int y1, int x2, int y2, int x3, int y3) {
    if (is_rook_move_valid(x1, y1, x3, y3) && !is_black_rook_threat(x2, y2, x3, y3)) {
        printf("Ход возможен.\n");
    } else {
        printf("Ход невозможен.\n");
    }
}

void mode2(int x1, int y1, int x2, int y2, int x3, int y3) {
    if (is_king_move_valid(x1, y1, x3, y3) && !is_black_queen_threat(x2, y2, x3, y3)) {
        printf("Ход возможен.\n");
    } else {
        printf("Ход невозможен.\n");
    }
}

void task3(void) {
    int x1, y1, x2, y2, x3, y3, mode;
    
    do { printf("Введите координаты белой фигуры (2 числа от 1 до 8):"); }         while (scanf("%d %d", &x1, &y1) != 2 || !validate(x1, y1));
    do { printf("Введите координаты черной фигуры (2 числа от 1 до 8):"); }        while (scanf("%d %d", &x2, &y2) != 2 || !validate(x2, y2));
    do { printf("Введите новое положение белой фигуры (2 числа от 1 до 8):"); }    while (scanf("%d %d", &x3, &y3) != 2 || !validate(x3, y3));

    printf("Выберите какой вариант программы нужен (введите число 1 или 2).\n[1] - ладья и ладья\n[2] - король и ферзь\nВведите число: "); scanf("%d", &mode);
    if (mode == 1) {
        mode1(x1, y1, x2, y2, x3, y3);
    } else if (mode == 2) {
        mode2(x1, y1, x2, y2, x3, y3);
    }
    else {
        printf("Введен некорректный режим.");
    }
}


// # # # # # # #
// # ЗАДАЧА  3 #
// # # # # # # #
// Мастям игральных карт условно присвоены следующие порядковые номера:
// пики – 1,трефы – 2,бубны – 3, червы – 4. 
// По заданному номеру определить название масти.
void task4(void) {
    int num;
    printf("Введите порядковый номер карты: "); scanf("%d", &num);
    switch (num) {
        case 1:
            printf("пики\n");
            break;
        case 2:
            printf("трефы\n");
            break;
        case 3:
            printf("бубны\n");
            break;
        case 4:
            printf("червы\n");
            break;
        default:
            printf("неверный порядковый номер\n");
    }
}



// Запуск задач
int main()
{
    task1();
    task2();
    task3();
    task4();
    return 0;
}
