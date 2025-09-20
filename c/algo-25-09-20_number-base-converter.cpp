/*
╔═════════════════════════════════════════════════════════════════════════════╗
  Authors:        Diyor Haydarov [alyreniko]
  Date:           September 20, 2025
  License:        MIT License
╟─────────────────────────────────────────────────────────────────────────────╢
  Description:
  Программа для преобразования чисел между произвольными системами счисления
  (от 2 до 36). Сначала число из исходной системы переводится в десятичную,
  затем из десятичной — в целевую систему. Выполняется проверка корректности
  цифр в исходной системе. Программа запускается из командной строки
  с аргументами:
        <число> <система_от> <система_в>
    Пример:
        ./converter 1A 16 2
    Вывод:
        11010
╚═════════════════════════════════════════════════════════════════════════════╝
*/

#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

int anyToDecimal(std::string num, int sysScale) {
    int currentDegree = 0;
    int result = 0;

    for (int i = num.length() - 1; i >= 0; --i) {
        char c = std::toupper(num[i]);
        int digit;
        if (isdigit(c)) {
            digit = c - '0';
        } else if (isalpha(c)) {
            digit = c - 'A' + 10;
        } else {
            return -1;
        }

        if (digit >= sysScale) {
            return -1;
        }

        result += digit * (int)std::pow(sysScale, currentDegree);
        currentDegree++;
    }

    return result;
}

std::string decimalToAny(int input, int sysScale) {
    input = abs(input);
    std::string result = "";
    do {
        int num = input % sysScale;
        char c = (num < 10) ? ('0' + num) : ('A' + num - 10);
        result = c + result;
    } while (input /= sysScale);

    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << argv[0] << " <number> <from_base> <to_base>" << std::endl;
        return 1;
    }

    std::string input_num = argv[1];
    int from_base = std::atoi(argv[2]);
    int to_base = std::atoi(argv[3]);

    if (from_base < 2 || from_base > 36 || to_base < 2 || to_base > 36) {
        std::cerr << "Base error: 2 <= base <= 36" << std::endl;
        return 1;
    }
    int decimal = anyToDecimal(input_num, from_base);
    if (decimal == -1) {
        std::cerr << "Invalid input for base " << from_base << std::endl;
        return 1;
    }
    std::string result = decimalToAny(decimal, to_base);
    std::cout << result << std::endl;

    return 0;
}
