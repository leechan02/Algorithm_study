#include <iostream>
#include <map>

int main() {
  std::string str;
  std::cin >> str;

  std::map<char, int> alphabet;
  for (int i = 0; i < 26; ++i) {
    alphabet[i + 97] = 0;
  }

  for (int i = 0; i < str.size(); ++i) {
    ++alphabet[str[i]];
  }

  for (auto i : alphabet) {
    std::cout << i.second << " ";
  }
}