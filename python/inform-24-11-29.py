# ╔═════════════════════════════════════════════════════════════════════════════╗
#   Authors:        Diyor Haydarov [alyreniko]
#   Date:           November 29, 2024
#   License:        MIT License
# ╚═════════════════════════════════════════════════════════════════════════════╝

# В тексте задания под терминами «массив» и «последовательность» подразумевается
# список. Встроенные функции для работы со списками не использовать!

import random

# === Задача 1 ===
# Дано натуральное число N и последовательность a1, a2, …, aN целых чисел,
# заданных случайным образом из диапазона от -15 до 35 включительно. Найти
# сумму положительных элементов массива, стоящих на нечетных местах. Задачу
# решить для N = 10.
def prog1():
    N = int(input("Задача 1.\nВведите число N: "))
    sequence = [random.randint(-15, 35) for _ in range(N)]

    sum_positive_odd_indices = 0
    for i in range(N):
        if i % 2 != 0 and sequence[i] > 0:
            sum_positive_odd_indices += sequence[i]

    print("Последовательность:", sequence)
    print("Сумма положительных элементов по нечетным индексам:", sum_positive_odd_indices)


# === Задача 2 ===
# Дано натуральное число N и последовательность a1, a2, …, aN целых чисел.
# Элементы последовательности – случайные числа из диапазона от 21 до 314
# включительно. Поменять местами минимальный и максимальный элементы
# последовательности Задачу решить для N = 15.
def prog2():
    N = int(input("\n\nЗадача 2.\nВведите число N: "))
    sequence = [random.randint(21, 314) for _ in range(N)]
    print("Изначальная последовательность:", sequence)

    min_index = 0
    max_index = 0
    for i in range(N):
        if sequence[i] < sequence[min_index]:
            min_index = i
        if sequence[i] > sequence[max_index]:
            max_index = i

    sequence[min_index], sequence[max_index] = sequence[max_index], sequence[min_index]

    print("Последовательность в результате:", sequence)
    print("Максимальный индекс:", sequence[max_index])
    print("Минимальный индекс: ", sequence[min_index])


# Задача 3
# Дано натуральное число N и последовательность a1, a2, …, aN целых чисел,
# заданных случайным образом из диапазона от -11 до 42 включительно. Проверить,
# верно ли, что количество четных и нечетных чисел расположенных между
# минимальным и максимальным элементами последовательности одинаково. Если
# одинаково, то вывести 0, если нет, то вывести 1. Решение оформить в виде
# функции. Задачу решить для N = 10.
def prog3():
    N = int(input("\n\nЗадача 3.\nВведите число N: "))
    sequence = [random.randint(-11, 42) for _ in range(N)]

    min_index = 0
    max_index = 0
    for i in range(N):
        if sequence[i] < sequence[min_index]:
            min_index = i
        if sequence[i] > sequence[max_index]:
            max_index = i

    even_count = 0
    odd_count = 0
    start_index = min_index if min_index < max_index else max_index
    end_index = max_index if max_index > min_index else min_index
    for i in range(start_index + 1, end_index):
        if sequence[i] % 2 == 0:
            even_count += 1
        else:
            odd_count += 1

    return 0 if even_count == odd_count else 1


# Задача 4
# В одномерном массиве длины N, заполненном случайными целыми числами из
# диапазона от -81 до 9 включительно найти минимальный элемент. Удалить его,
# передвинув все оставшиеся элементы массива на одну позицию влево. Задачу
# решить для N = 10.
def prog4():
    N = int(input("\n\nЗадача 4.\nВведите число N: "))
    sequence = [random.randint(-81, 9) for _ in range(N)]
    print("Изначальная последовательность:", sequence)

    min_index = 0
    min_value = sequence[0]
    for i in range(N):
        if sequence[i] < min_value:
            min_value = sequence[i]
            min_index = i

    for i in range(min_index, N - 1):
        sequence[i] = sequence[i + 1]

    sequence.pop()

    print("После удаления мин. элемента:", sequence)

prog1()
prog2()
print(prog3())
prog4()
