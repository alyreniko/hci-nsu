### Program 1
def ShiftLeft3(A, B, C): return B, C, A

A1, B1, C1 = ShiftLeft3(1, 2, 3)
print("Первый набор после сдвига:", A1, B1, C1)

A2, B2, C2 = ShiftLeft3(4, 5, 6)
print("Второй набор после сдвига:", A2, B2, C2)


### Program 2
def IsPalindrom(K):
    return True if str(K) == str(K)[::-1] else False

print("\n", IsPalindrom(343), "\n")


### Program 3
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


### Program 4
def Fact2(N):
    fact2 = 1
    while N > 0:
        fact2 *= N
        N -= 2
    return fact2

print("\n", Fact2(12))


### Program 5
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
