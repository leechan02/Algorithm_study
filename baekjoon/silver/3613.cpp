#include <iostream>
#include <string>
#include <cctype>

std::string str;

int checkLanguage() {
  int under = 0, upper = 0;
  if (str[0] == '_' || str[str.size() - 1] == '_' || std::isupper(str[0])) return 2;
  for (int i = 0; i < str.size(); ++i) {
    if (i < str.size() - 1 && str[i] == '_' && str[i + 1] == '_') return 2;
    if (str[i] == '_') ++under;
    else if ('A' <= str[i] && str[i] <= 'Z') ++upper;
  }
  if ((under > 0 && upper > 0)) return 2;
  else if (upper > 0) return 1;
  else return 0;
}

void changeToJava() {
    std::string ret;
    bool toUpper = false;

    for (char ch : str) {
        if (ch == '_') {
            toUpper = true;
            continue;
        }
        if (toUpper) {
            ret += std::toupper(ch);
            toUpper = false;
        } else {
            ret += ch;
        }
    }
    std::cout << ret << "\n";
}

void changeToCpp() {
    std::string ret;

    for (char ch : str) {
        if (std::isupper(ch)) {
            ret += "_";
            ret += std::tolower(ch);
        } else {
            ret += ch;
        }
    }
    std::cout << ret << "\n";
}

int main() {
    std::cin >> str;
    int flag = checkLanguage();
    if (flag == 0) changeToJava();
    else if (flag == 1) changeToCpp();
    else std::cout << "Error!\n";
}
