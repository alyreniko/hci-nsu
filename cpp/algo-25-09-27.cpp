#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <unordered_set>
#include <stack>

// Задача 1. Проверка палиндрома
// Напишите программу, которая считывает строку (до 100 символов) и
// проверяет, является ли она палиндромом (читается одинаково слева направо
// и справа налево). Игнорируйте пробелы и регистр символов.
int isPalindrome(std::string str) {
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    std::string reversedStr = str;
    std::reverse(reversedStr.begin(), reversedStr.end());
    return str == reversedStr ? 1 : 0;
}

// Задача 2. Подсчёт уникальных элементов
// Дана последовательность из N целых чисел (вводится с клавиатуры).
// Напишите программу, которая определит, сколько среди них уникальных
// чисел (т.е. таких, которые встречаются ровно один раз).
// Массив разных чисел короче.
int unocueCount(std::vector<int>& arr) {
    std::unordered_set<int> seen;
    std::unordered_set<int> duplicates;

    for (int num : arr) {
        seen.count(num) ? duplicates.insert(num) : seen.insert(num);
    }

    int uniqueCount = 0;
    for (int num : seen) {
        duplicates.count(num) == 0 ? uniqueCount++ : uniqueCount;
    }

    return uniqueCount;
}

// Задача 3. Перевёртыш числа
// Вводится положительное целое число. Напишите программу, которая
// запишет в новую переменную число в обратном порядке. Например, для
// 12345 сохранится 54321. (БЕЗ ИСПОЛЬЗОВАНИЯ ПЕРЕВОДА В
// СТРОКУ).
int reverseNumber(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

// Задача 4. Проверка сбалансированности скобок
// Вводится строка, которая содержит только символы '(' и ')'. Проверьте,
// являются ли скобки в строке сбалансированными (каждая открывающая
// скобка должна иметь соответствующую закрывающую в правильном
// порядке).
// Пример:
// Входные: (hello(everybody)
// Выходные: NO
bool isBalanced(std::string& str) {
    std::stack<char> stack;
    for (char c : str) {
        if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            if (stack.empty() || stack.top() != '(') {
                return false;
            }
            stack.pop();
        }
    }
    return stack.empty();
}

// Задача 5. Подсчёт цифр в числе
// Вводится целое число. Определите, сколько раз каждая цифра (0-9)
// встречается в записи этого числа.
void countDigits(int num) {
    std::vector<int> digits(10, 0);

    while (num > 0) {
        digits[num % 10]++;
        num /= 10;
    }

    std::cout << "Digit count: ";
    for (int i = 0; i < 10; i++) {
        std::cout << "[" << i << "]: " << digits[i] << "\n";
    }
    std::cout << std::endl;
}

int main() {
    // std::string str1;
    // std::cout << "Enter a string: ";
    // std::getline(std::cin, str1);
    // std::cout << "Is palindrome? " << (isPalindrome(str1) ? "Yes" : "No") << std::endl;

    // int N = 0;
    // std::cout << "Enter count of elements: ";
    // std::cin >> N;
    // int arr[N], i;
    // for(i=0; i < N; i++) {
    //     std::cout << "A[" << i << "] = ";
    //     std::cin >> arr[i];
    // }
    // std::vector<int> arrVec(arr, arr + N);
    // std::cout << "Unique elements count: " << unocueCount(arrVec) << std::endl;

    // int num;
    // std::cout << "Enter a number: ";
    // std::cin >> num;
    // std::cout << "Reversed number: " << reverseNumber(num) << std::endl;

    std::string str;
    std::cout << "Enter a string with parentheses: ";
    std::getline(std::cin, str);
    std::cout << "Is balanced? " << (isBalanced(str) ? "Yes" : "No") << std::endl;

    // int num;
    // std::cout << "Enter a number: ";
    // std::cin >> num;
    // countDigits(num);

    return 0;
}
