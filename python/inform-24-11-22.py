# ╔═════════════════════════════════════════════════════════════════════════════╗
#   Authors:        Diyor Haydarov [alyreniko]
#   Date:           November 22, 2024
#   License:        MIT License
# ╚═════════════════════════════════════════════════════════════════════════════╝

import math

# === Задача 1 ===
def get_input():
    return [int(input(f"Введите {i}: ")) for i in "MNL"]

def calculate_y(M, N, L):
    if 7 <= L <= 10:
        return [M + 5 * N, 2 * M + 5 * N]
    else:
        return [L + 0.5 * N, N + 0.7 * L]

def calculate_z(y):
    return min(y)**2 - math.sqrt(abs(max(y)))

def prog1():
    M, N, L = get_input()
    y = calculate_y(M, N, L)
    print("Результат задачи:", calculate_z(y))
    print()



# === Задача 2 ===
# Написать функцию, определяющую количество всех ненулевых цифр целого числа.
def count_nonzero_digits(n):
    return sum(1 for digit in str(abs(n)) if digit != '0')

def prog2():
    print("Количество всех ненулевых цифр:", count_nonzero_digits(int(input("Введите число: "))), end = "\n\n")


# === Задача 3 ===
# Дано натуральное число n. Можно ли представить его в виде суммы трех квадратов
# натуральных чисел? Если можно, то указать все тройки x, y, z таких натуральных
# чисел, что n = x^2 + y^2 + z^2. Решение оформить в виде отдельных функций.
def is_sum_of_three_squares(n): # функция того что можно ли предствить в виде суммы
    for x in range(1, n + 1):
        for y in range(x, n + 1):
            for z in range(y, n + 1):
                if x**2 + y**2 + z**2 == n:
                    return True
    return False

def find_squares(n): # находим и выводим эти самые суммы
    if is_sum_of_three_squares(n):
        result = []
        for x in range(1, n + 1):
            for y in range(x, n + 1):
                for z in range(y, n + 1):
                    if x**2 + y**2 + z**2 == n:
                        result.append((x, y, z))
        return result

def prog3():
    n = int(input("Введите число: "))
    result = find_squares(n)
    if result:
        print(f"Число {n} можно представить в виде суммы трёх квадратов: {result}")
    else:
        print(f"Число {n} не может быть представлено в виде суммы трёх квадратов.")

prog1()
prog2()
prog3()
