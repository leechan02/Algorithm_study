#include <iostream>

bool isVowel(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
    return true;
  }
  return false;
}

bool checkFirst(std::string str) {
  for (int i = 0; i < str.size(); ++i) {
    if (isVowel(str[i])) {
      return true;
    }
  }
  return false;
}

bool checkSecond(std::string str) {
  for (int i = 2; i < str.size(); ++i) {
    if (isVowel(str[i]) && isVowel(str[i - 1]) && isVowel(str[i - 2])) {
      return false;
    } else if (!isVowel(str[i]) && !isVowel(str[i - 1]) &&
               !isVowel(str[i - 2])) {
      return false;
    }
  }
  return true;
}

bool checkLast(std::string str) {
  for (int i = 1; i < str.size(); ++i) {
    if ((str[i] != 'e' && str[i] != 'o') && str[i] == str[i - 1]) {
      return false;
    }
  }
  return true;
}

int main() {
  std::string str;

  while (std::cin >> str) {
    if (str == "end") {
      break;
    }
    if (checkFirst(str) && checkSecond(str) && checkLast(str)) {
      std::cout << "<" << str << "> is acceptable.\n";
    } else {
      std::cout << "<" << str << "> is not acceptable.\n";
    }
  }
}