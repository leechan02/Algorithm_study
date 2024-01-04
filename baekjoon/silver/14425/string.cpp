#include <iostream>
#include <set>

int main() {
  int n, s;
  std::cin >> n >> s;

  std::set<std::string> dic;
  for (int i = 0; i < n; ++i) {
    std::string tmp;
    std::cin >> tmp;
    dic.insert(tmp);
  }

  int result = 0;
  for (int i = 0; i < s; ++i) {
    std::string tmp;
    std::cin >> tmp;

    if (dic.find(tmp) != dic.end()) {
      ++result;
    }
  }
  std::cout << result << "\n";
  return (0);
}