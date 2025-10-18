#include <iostream>
#include <fstream>
#include <string>

int findWord(std::string word, std::string path) {
  std::ifstream inputFile("in.txt");
  if (inputFile.is_open()) {
    std::string line;
    int line_num = 0;

    while (getline(inputFile, line)) {
      line_num++;
      if (line.find(word) != std::string::npos) {
        inputFile.close();
        return line_num;
      }
    }
  }
  inputFile.close();
  return -1;
}

int main() {
  std::cout << findWord("world", "in.txt") << std::endl;
  return 0;
}
