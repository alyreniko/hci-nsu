import random
matrix = [[random.randint(-10, 10) for _ in range(4)] for _ in range(4)]
# Для проверки корректности выполнения программы
# укажу матрицу, можете закомментировать и исполоьзовать через random
matrix = [
    [5, -3, 2, 8],
    [7, -1, 0, -4],
    [4, 6, -2, 3],
    [1, -9, 7, -5]
]

################
#~~ ЗАДАЧА 1 ~~#
################

# Дана матрица размера N x M и целое число К. Найти среднее арифметическое
# нечетных элементов K-й строки данной матрицы и количество отрицательных
# элементов К-го столбца.

def process_matrix(matrix, k):
    k -= 1  # Поскольку индексация с нуля, нам нужно уменьшить k на 1
    if k < 0 or k >= len(matrix) or k >= len(matrix[0]):
        return "Ошибка: неверный индекс строки или столбца"
    row, col = matrix[k], [row[k] for row in matrix]
    avg_odd = sum(x for x in row) / len(row)
    neg_count = sum(1 for x in col if x < 0)
    return avg_odd, neg_count

print(process_matrix(matrix, 2), end="\n\n")



################
#~~ ЗАДАЧА 2 ~~#
################

# Дана матрица размера N x M. Найти номер ее столбца с наибольшим количеством
# четных элементов и вывести данный номер, а также значение наибольшего
# количества.

def find_column_with_max_evens(matrix):
    max_evens = 0
    column_index = -1
    
    for j in range(len(matrix)):
        even_count = sum(1 for i in range(len(matrix)) if matrix[i][j] % 2 == 0)
        if even_count > max_evens:
            max_evens, column_index = even_count, j
    
    return column_index + 1, max_evens  # +1 для понимания человека (индексация)

column, count = find_column_with_max_evens(matrix)
print(f"Номер столбца: {column}, Количество чётных элементов: {count}", end="\n\n")


################
#~~ ЗАДАЧА 3 ~~#
################

# Дана матрица размера N x N. Поменять местами первую строку и строку с
# минимальным количеством четных элементов. Написать 3 функции (заполнение,
# смена, вывод).

# Заполнение матрицы
def fill_matrix(n):
    return [[random.randint(-10, 10) for _ in range(n)] for _ in range(n)]

# Нахождение строки с минимальным количеством четных элементов
def find_row_with_min_evens(matrix):
    return min(range(len(matrix)), key=lambda i: sum(1 for x in matrix[i] if x % 2 == 0))

# Смена местами первую строку и строку с
# минимальным количеством четных элементов
def swap_rows(matrix, row_index):
    matrix[0], matrix[row_index] = matrix[row_index], matrix[0]

# Вывода матрицы
def print_matrix(matrix):
    for row in matrix:
        print(row)

n = 4
matrix = fill_matrix(n)

print("Исходная матрица:")
print_matrix(matrix)

min_even_row = find_row_with_min_evens(matrix)
swap_rows(matrix, min_even_row)

print(f"\nМатрица после смены первой строки и строки с минимальным количеством четных элементов (строка {min_even_row + 1}):")
print_matrix(matrix)
