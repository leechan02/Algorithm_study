#include <iostream>
#include <string>

int len;
std::string str;

bool recursive(std::string s) {
  if (s.size() == 1) return 1;
  len = s.size() / 2;

  for (int i = 0; i <= len; ++i) {
    if (s[i] != s[s.size() - i - 1]) return 0;
  }

  if (!recursive(s.substr(0, len))) return 0;
  if (!recursive(s.substr(s.size() - len, len))) return 0;
  return 1;
}

int main() {
  std::cin >> str;

  recursive(str) ? std::cout << "AKARAKA" : std::cout << "IPSELENTI";
}