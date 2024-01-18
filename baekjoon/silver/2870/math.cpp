#include <iostream>
#include <set>

bool isNum(char c) {
  if (c >= '0' && c <= '9') {
    return true;
  }
  return false;
}

struct Compare {
  bool operator()(const std::string &a, const std::string &b) const {
    if (a.size() == b.size()) {
      return a < b;
    }
    return a.size() < b.size();
  }
};

int main() {
  int n;
  std::cin >> n;

  std::multiset<std::string, Compare> set;
  while (n--) {
    std::string str;
    std::cin >> str;

    for (int i = 0; i < str.size(); ++i) {
      int j = i;
      while (isNum(str[j])) {
        ++j;
      }
      if (isNum(str[i])) {
        while (str[i] == '0' && i < j - 1) {
          ++i;
        }
        set.insert(str.substr(i, j - i));
        i = j;
      }
    }
  }

  for (auto i : set) {
    std::cout << i << "\n";
  }
}