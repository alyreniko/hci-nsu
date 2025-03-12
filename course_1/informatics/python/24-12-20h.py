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

# Дана матрица размера N x N. Найти максимальный и минимальный элементы
# главной диагонали и сумму элементов побочной диагонали.

count_lines_and_columns = len(matrix)
max_element = matrix[0][0]
min_element = matrix[0][0]

for i in range(int(count_lines_and_columns)):
    if matrix[i][i] > max_element:
        max_element = matrix[i][i]
    if matrix[i][i] < min_element:
        min_element = matrix[i][i]

sum_diagonal = 0
for i in range(int(count_lines_and_columns)):
    sum_diagonal += matrix[i][int(count_lines_and_columns)-1-i]

print(f"Максимальный элемент главной диагонали: {max_element}")
print(f"Минимальный элемент главной диагонали: {min_element}")
print(f"Сумма элементов побочной диагонали: {sum_diagonal}")



################
#~~ ЗАДАЧА 2 ~~#
################

# Дана матрица размера N x M. Продублировать строку, содержащую минимальный
# элемент матрицы.

print("Исходная матрица:")
for row in matrix:
    print(row)

min_element = matrix[0][0]
row_index = 0

for i in range(len(matrix)):
    for j in range(len(matrix[0])):
        if matrix[i][j] < min_element:
            min_element = matrix[i][j]
            row_index = i

matrix.insert(row_index + 1, matrix[row_index])

print("\nМатрица после дублирования строки с минимальным элементом:")
for row in matrix:
    print(row)



################
#~~ ЗАДАЧА 3 ~~#
################

# Дана матрица размера N x M. Удалить из нее все столбцы, содержащие
# минимальный элемент матрицы. Для вычисления минимума использовать
# функцию.

print("Исходная матрица:")
for row in matrix:
    print(row)

min_element = matrix[0][0]
column_index = 0

for i in range(len(matrix)):
    for j in range(len(matrix[0])):
        if matrix[i][j] < min_element:
            min_element = matrix[i][j]
            column_index = j

matrix = [row[:column_index] + row[column_index + 1:] for row in matrix]

print("\nМатрица после удаления столбцов с минимальными элементами:")
for row in matrix:
    print(row)