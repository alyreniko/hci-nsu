################
#~~ ЗАДАЧА 1 ~~#
################

# Дан файл f содержащий целые числа. Количество чисел в файле кратно 2.
# Числа задают координаты (в декартовой системе) точки. Записать в файл f1
# координаты точки и значение длины отрезка, имеющего минимальную длину
# и соединяющего точку с началом координат.

file = open("input_1.txt", "r")
file_out = open("output_1.txt", "w")

numbers_in_file = file.read()

slice_text = numbers_in_file.split()

index_number = 0
min_coords = (0, 0)
min_line = int(slice_text[index_number])**2 + int(slice_text[index_number + 1])**2

while index_number + 1 < len(slice_text):
    if int(slice_text[index_number])**2 + int(slice_text[index_number + 1])**2 < min_line**2:
        min_line = int(slice_text[index_number])**2 + int(slice_text[index_number + 1])**2
        min_coords = (int(slice_text[index_number]), int(slice_text[index_number + 1]))
    index_number += 1

file_out.write(f"Координаты точки: {min_coords}\nДлина отрезка: {min_line}")

file.close()
file_out.close()



################
#~~ ЗАДАЧА 2 ~~#
################

# Дан файл, содержащий целые числа. Изменить порядок чисел в файле так,
# чтобы сначала шли все нечетные числа, затем все четные (4 3 2 5 3 - 3 5 3 4 3.

file = open("input_2.txt", "r")

numbers_in_file = file.read()

slice_text = numbers_in_file.split()

file.close()

index = 0

new_list = []

while index < len(slice_text):
    if int(slice_text[index]) % 2 == 0:
        new_list.append(int(slice_text[index]))
    else:
        new_list.insert(0, int(slice_text[index]))
    index += 1

file = open("input_2.txt", "a")
file.write(f" — {' '.join(map(str, new_list))}")

file.close()

print(f"\nОтсортированный список: {new_list}")



################
#~~ ЗАДАЧА 3 ~~#
################

# Дан текстовый файл, содержащий квадратную матрицу целых числа(в первой
# строке файла записано - кол-во строк и столбцов). Считать данные из файла,
# вывести на экран в виде матрицы, в каждой строке поменять местами эл-ты
# стоящие на главной и побочной диагоналях и записать новое состоянии
# матрицы в другой файл

file = open("input_3.txt", "r")
file_out = open("output_3.txt", "w")

count_lines_and_columns = file.readline(2)[:-1]

matrix = []

# чтение и запись матрицы из файлы
for line in file:
    line = line[:-1]
    matrix.append(list(map(int, line.split())))

# вывод исходной матрицы
for row in matrix:
    print(" ".join(str(x) for x in row))

# замена элементов
for i in range(int(count_lines_and_columns)):
    matrix[i][i], matrix[i][int(count_lines_and_columns)-1-i] = matrix[i][int(count_lines_and_columns)-1-i], matrix[i][i]

# вывод новой матрицы
for row in matrix:
    print(" ".join(str(x) for x in row), file=file_out)

file.close()
file_out.close()



######################
#~~ ПРИМЕРЫ ФАЙЛОВ ~~#
######################

# ----input_1.txt----
# -4 2 5 9 4 3
# -------------------

# ----input_2.txt----
# 3 4 1 -2 4 -1
# -------------------

# ----input_3.txt----
# 3
# 1 2 3
# 4 5 6
# 7 8 9
# -------------------