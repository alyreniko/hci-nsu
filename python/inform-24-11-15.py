# ╔═════════════════════════════════════════════════════════════════════════════╗
#   Authors:        Diyor Haydarov [alyreniko]
#   Date:           November 15, 2024
#   License:        MIT License
# ╚═════════════════════════════════════════════════════════════════════════════╝

# === Задача 1 ===
# Описать функцию ShiftLeft3(A, B, C), выполняющую левый циклический сдвиг:
# значение A переходит в C, значение C переходит в B, значение B переходит в A (A, B, C –
# вещественные параметры, являющиеся одновременно входными и выходными).
# С помощью этой функции выполнить левый циклический сдвиг для двух данных
# наборов из трех чисел: (A 1 , B 1 , C 1 ) и (A 2 , B 2 , C 2 ).
def ShiftLeft3(A, B, C): return B, C, A

A1, B1, C1 = ShiftLeft3(1, 2, 3)
print("Первый набор после сдвига:", A1, B1, C1)

A2, B2, C2 = ShiftLeft3(4, 5, 6)
print("Второй набор после сдвига:", A2, B2, C2)

# === Задача 2 ===
# Описать функцию IsPalindrom(K), возвращающую True, если целый параметр K (>0)
# является палиндромом (то есть его запись читается одинаково слева направо
# и справа налево), и False в противном случае.
def IsPalindrom(K):
    return True if str(K) == str(K)[::-1] else False

print("\n", IsPalindrom(343), "\n")


# === Задача 3 ===
def calcX(a, n, l):
    return ((a + n) / ((a - l) ** 2), a / (n * l))

def calcY(a, n, l):
    x_all = calcX(a, n, l)
    if x_all[0] == x_all[1]:
        return(x_all[0]/x_all[1])*(a-n)
    elif x_all[0] < x_all[1]:
        return(x_all[0]+x_all[1])
    elif x_all[0] > x_all[1]:
        return((a*x_all[0])+(n*x_all[1]))

def calcZ(a, n, l):
    x_all = calcX(a, n, l)
    return max(x_all) / sum(x_all)

a, n, l = 15, 13, 32
for func in [calcX, calcY, calcZ]: print(func(a, n, l))

### === Задача 4 ===
# Описать функцию Fact2(N) вещественного типа, вычисляющую двойной
# факториал:
# N!! = 1·3·5·…·N, если N – нечетное
# N!! = 2·4·6·…·N, если N – четное
# (N>0, параметр целого типа).
def Fact2(N):
    fact2 = 1
    while N > 0:
        fact2 *= N
        N -= 2
    return fact2

print("\n", Fact2(12))

### === Задача 5 ===
# Дано целое число n. Получить все целые числа меньшие n и взаимно простые с ним
# (два числа называются взаимно простыми, если их наибольший общий делитель
# равен 1). Решение оформить в виде отдельной функции.
def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def Prog(n):
    result = []
    for i in range(2, n):
        if gcd(i, n) == 1:
            result.append(i)
    return result
print("\n", Prog(25))
