/*
╔═════════════════════════════════════════════════════════════════════════════╗
  Authors:        Diyor Haydarov [alyreniko]
  Date:           September 13, 2025
  License:        MIT License
╚═════════════════════════════════════════════════════════════════════════════╝
*/

#include <cctype>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>

// === Задача 1 ===
// Напишите функцию reverseWords (text):
// - Сохраняй порядок слов.
// - Переворачивай символы внутри каждого слова,
// - Знаки препинания остаются на своих местах (приклеены к словам).
int reverseWords(std::string str) {
    int j = 0;
    for (int i = 0; i < str.length(); ) {
        while (i < str.length() && !std::isalpha(str[i])) i++;
        j = i;
        while (j < str.length() && std::isalpha(str[j])) j++;
        std::reverse(str.begin() + i, str.begin() + j);
        i = j;
    }
    std::cout << str;
    return 0;
}

// === Задача 2 ===
// Напиши функцию generatePassword(length).
// Генерация пароля соответственно из разных символов и цифр, при желании знаков.
std::string generatePassword(int lenght) {
    const int start_ascii_table = 33;
    const int end_ascii_table = 122;

    std::string result = "";

    for (int i = 0; i < lenght; i++) {
        result += start_ascii_table + rand() % (end_ascii_table - start_ascii_table + 1);
    }

    return result;
}

// === Задача 3 ===
// Есть любой массив, например int mas[] = (1,5,5,7,2,4,1,1) Нужно убрать все повторы из него.
int removeDuplicates(std::vector<int>& array) {
    std::vector<int> result;
    std::unordered_set<int> seen;

    for (int x : array) {
        if (seen.insert(x).second) {
            result.push_back(x);
        }
    }

    array = std::move(result);

    for (int value : array) {
        std::cout << value << " ";
    }

    return 0;
}

// === Задача 4 ===
// Посчитать все четные и нечетные цифры в числе 1052144 (любое число, просто для примера)
int countEvenOdd(int num) {
    int even_count = 0, odd_count = 0;
    num = abs(num);
    do {
        (num % 10 % 2 ? odd_count : even_count)++;
    } while (num /= 10);
    std::cout << "Even: " << even_count << "\nOdd: " << odd_count;
    return 0;
}

// === Задача 5 ===
// (ДОПОЛНИТЕЛЬНО) Шифр Цезаря (шифрование и расшифровка)
// Напиши две функции, на зашифровку и дешифровку (где текст, сам текст, где shift
// там сдвиг посимвольный):
// caesarEncrypt(text, shift)
// caesar Decrypt(text, shift)
std::string caesarEncrypt(const std::string& str, int shift) {
    std::string result;
    shift = (shift % 26 + 26) % 26;

    for (char c : str) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            result += (c - base + shift) % 26 + base;
        } else {
            result += c;
        }
    }

    return result;
}

std::string caesarDecrypt(const std::string& str, int shift) {
    return caesarEncrypt(str, -shift);
}


void printTask(int& x) {
    std::cout << "\n\n=== Task " << ++x << " ===\n";
}
int main() {
    int x = 0;
    printTask(x);
    reverseWords(std::string(",Hola Amigo!"));
    printTask(x);
    std::cout << generatePassword(24);
    printTask(x);
    std::vector<int> vect = {1, 2, 2, 5, 4, 4, 3, 2};
    removeDuplicates(vect);
    printTask(x);
    countEvenOdd(12252);
    printTask(x);
    std::cout << caesarEncrypt("Hello World (ABCD)", 27); // shift = 27-26 = 1
    printTask(x);
    std::cout << caesarDecrypt("Ifmmp Xpsme (BCDE)", 27) << std::endl; // shift = 27-26 = 1
}
