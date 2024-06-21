#include <iostream>
#include <list>
#include <string>

int n;
std::string input;

int main() {
  std::cin >> n;

  while (n--) {
    std::list<char> password;
    std::cin >> input;

    auto it = password.begin();
    for (int i = 0; i < input.size(); ++i) {
      if (input[i] == '<') {
        if (it != password.begin()) --it;
      } else if (input[i] == '>') {
        if (it != password.end()) ++it;
      } else if (input[i] == '-') {
        if (it != password.begin()) {
          --it;
          it = password.erase(it);
        }
      } else {
        it = password.insert(it, input[i]);
        ++it;
      }
    }

    for (auto it : password) std::cout << it;
    std::cout << "\n";
  }
}