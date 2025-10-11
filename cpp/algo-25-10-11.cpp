#include <iostream>
#include <fstream>
#include <cstdlib>
#include <fmt/core.h>
#include <ostream>
#include <string>

std::string decimalToBinary(int input) {
    input = abs(input);
    std::string result = "";

    do {
        int num = input % 2;
        char c = (num < 10) ? ('0' + num) : ('A' + num - 10);
        result = c + result;
    } while (input /= 2);

    return result;
}

int main() {
  int max = 0;
  int currentMax = 0;

  std::ifstream inputFile("in.txt");
  if (inputFile.is_open()) {
    std::string line;

    std::string binary = "";

    while (getline(inputFile, line)) {
      std::cout << line << std::endl;

      try {
        binary = decimalToBinary(std::stoi(line));
      } catch (const std::exception& e) {}
    }



    for (char c : binary) {
      if (c == '1') {
        currentMax++;
        if (max < currentMax) max = currentMax;
      } else currentMax = 0;
    }
  }

  std::ofstream out;
  out.open("out.txt");
  if (out.is_open()) out << max << std::endl;

  inputFile.close();
  out.close();
  return 0;
}
