#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int m, n;
std::string str;
std::vector<bool> s;

int main() {
  std::ios_base::sync_with_stdio(0);std::cin.tie(0); std::cout.tie(0);
  std::cin >> m;
  s = std::vector<bool>(21, false);

  while (m--) {
    std::cin >> str;
    if (str == "all") {
      std::fill(s.begin(), s.end(), true);
    } else if (str == "empty") {
      std::fill(s.begin(), s.end(), false);
    } else {
      std::cin >> n;
      if (str == "add") {
        s[n] = true;
      } else if (str == "remove") {
        s[n] = false;
      } else if (str == "check") {
        s[n] ? std::cout << "1\n" : std::cout << "0\n";
      } else {
        s[n] = !s[n];
      }
    }
  }
}
