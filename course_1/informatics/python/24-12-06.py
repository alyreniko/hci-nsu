import random


def prog1():
    N = 10
    a = [random.randint(-15, 35) for _ in range(N)]
    print(f"Последовательность: {a}")

    if a.index(min(a)) + a.index(max(a)) > 5:
        sum_positive = 0
        for i in range(N):
            if i % 2 != 0 and a[i] > 0:
                sum_positive += a[i]
        print("Сумма положительных элементов, стоящих на нечетных местах:", sum_positive)
    else:
        negative_count = 0
        for i in range(N):
            if a[i] < 0:
                negative_count += 1
        print("Количество отрицательных элементов:", negative_count)
import math

def prog2():
    N = 15
    sequence = [random.randint(-50, 50) for _ in range(N)]
    print("Последовательность:", sequence)

    bigger_than_right_neighbor = []
    for i in range(len(sequence) - 1):
        if sequence[i] > sequence[i + 1]:
            bigger_than_right_neighbor.append(i)
    print("Номера элементов, которые больше правого соседа:", bigger_than_right_neighbor)
    print("Количество таких элементов:", len(bigger_than_right_neighbor))

def prog3():
    def find_min(a):
        min_val = abs(a[0])
        min_index = 0
        for i in range(len(a)):
            if abs(a[i]) < min_val:
                min_val = abs(a[i])
                min_index = i
        return min_val, min_index

    N = 20
    a = [random.randint(1, 125) for _ in range(N)]
    print("Последовательность:", a)

    min_val, min_index = find_min(a)
    print(f"Минимальный по модулю элемент: a[{min_index}] = {min_val}")

    new_a = [x for x in a if x % min_val == 0]
    print("Новый массив из элементов, кратных минимальному по модулю:", new_a)

def prog4_1():
    a = [random.randint(-10, 10) for _ in range(10)]
    print("Исходный массив:", a)

    a = [x for x in a if x < 0 or x > 5]
    print("Новый массив:", a)

def prog4_2():
    a = [random.randint(-10, 10) for _ in range(10)]
    print("Исходный массив:", a)

    for i in range(0, 5):
        if i in a:
            a.remove(i)
    print("Новый массив:", a)

prog4_2()