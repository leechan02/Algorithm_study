#include <iostream>

std::string str;
std::string word;
int cnt;

int main() {
  std::getline(std::cin, str);
  std::getline(std::cin, word);

  auto pos = str.find(word, 0);
  while (pos != std::string::npos) {
    ++cnt;
    pos = str.find(word, pos + word.size());
  }
  std::cout << cnt << "\n";
}