# Задача 1

nums = input("Введите цифры: ")

chet = 0
nechet = 0

for i in nums:
    if int(i) % 2 == 0:
        chet += 1
    else:
        nechet += 1

print(f"{chet} чётных и {nechet} нечетных")


#-------------------------

# Задача 2

nums = input("Введите цифры: ")

for i in nums[::-1]:
    print(i, end="")


#------------------------

# Задача 3

num = int(input("Введите цифры: "))

count = 0

for i in range(1, num + 1):
    if num % i == 0:
        count += 1

if count == 2:
    print("Да")
else:
    print("Нет")


#-------------------------

# Задача 4

start_c = input("Введите начало катушки: ")
end_c = input("Введите конец катушки: ")
count = 0

if len(start_c) == 6 and len(end_c) == 6:
    for i in range(int(start_c) + 1, int(end_c) + 1):
        a = [int(j) for j in str(i)]
        if sum(a[:3]) == sum(a[3:]):
            count += 1
else:
    print("Введено некорректное число.")

print(f"Кол-во счастливых билетов {count}")


#--------------------------

# Задача 5

num = int(input("Введите кол-во требуемых чисел: "))




digit1 = digit2 = 1

num = int(input("Введите кол-во требуемых чисел: "))

print(digit1, digit2, end=', ')

for i in range(2, num):
    digit1, digit2 = digit2, digit1 + digit2
    print(digit2, end=', ')


#--------------------------

# Задача 6

start_c = 32
end_c = 127

current = 32

for i in range(0, 10):
    for j in range(0, 10):
        print('%8s' % f"{current}-{chr(current)}", end="")
        current += 1 
        if current > end_c:
            break
    print()
