# PROG 1
a = int(input("Введите A: "))
b = int(input("Введите B: "))
c = int(input("Введите C: "))

cache = {'a':a, 'b':b, 'c':c}

a = cache['c']
b = cache['a']
c = cache['b']

print(f"a = {a}\nb = {b}\nc = {c}")



# PROG 2
x = int(input("Введите число X: "))

x2 = x*x
x4 = x2*x2
x8 = x4*x4
x10 = x8*x2
x20 = x10*x10

print(f"x^4 = {x4}\nx^20 = {x20}")



# PROG 3
num = list(input("Введите пятизначное число: "))

num[0], num[-2] = num[-2], num[0]

print(''.join(num))



# PROG 4
import math

x1 = int(input("Введи x1: "))
y1 = int(input("Введи y1: "))
x2 = int(input("Введи x2: "))
y2 = int(input("Введи y2: "))

print(int(math.sqrt((x1 - x2)**2 + (y1 - y2)**2)))



# PROG 5
import math

a = 7
b = 10**15
alf = 1.25

x = math.tan(a/(2*b))+alf
fi = (math.log(a-x))/(math.log(abs(a-x)))

print(fi)

