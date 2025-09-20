import random


# Задача 1
def prog1():
    N = int(input("Задача 1.\nВведите число N: "))
    sequence = [random.randint(-15, 35) for _ in range(N)]

    sum_positive_odd_indices = 0
    for i in range(N):
        if i % 2 != 0 and sequence[i] > 0:
            sum_positive_odd_indices += sequence[i]

    print("Последовательность:", sequence)
    print("Сумма положительных элементов по нечетным индексам:", sum_positive_odd_indices)


# Задача 2
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
