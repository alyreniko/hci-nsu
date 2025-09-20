# Задача 1
a, b = [int(input(f"Введите число {char}: ")) for char in "AB"]

if a >= b:
    print("no")
else:
    print("yes")

# Задача 2
n, m, k = [int(input(f"Введите число {char}")) for char in "NMK"]

if k < m*n and (k%m==0 or k%n==0):
    print('yes')
else:
    print('no')

# Задача 3
x, y = [int(input(f"Введите координату {char} для A:")) for char in "XY"]

if (x>=-1) and (y<=1) and (y>=0) and (y>=x**2):
    print("yes")
else:
    print("no")

# Задача 4
x1, y1 = [int(input(f"Введите {char} для координаты исходного положения: ")) for char in "XY"]
x2, y2 = [int(input(f"Введите {char} для координаты куда хотите сходить: ")) for char in "XY"]

all(i in range(1, 9) for i in (x1, y1, x2, y2)):
    if x1==x2 or y1==y2:
        print("yes")
    else:
        print("no")

# Задача 5
num_day = int(input(f"Введите номер дня недели: "))

match num_day:
    case 1:
        print("понедельник")
    case 2:
        print("вторник")
    case 3:
        print("среда")
    case 4:
        print("четверг")
    case 5:
        print("пятница")
    case 6:
        print("суббота")
    case 7:
        print("воскресенье")
    case _:
        print("введите верные данные")

