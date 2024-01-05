#include <iostream>
#include <map>

int main() {
  int n, s;
  std::cin >> n >> s;

  std::map<std::string, int> dic;
  for (int i = 0; i < n; ++i) {
    std::string tmp;
    std::cin >> tmp;
    dic[tmp] = 1;
  }

  int result = 0;
  for (int i = 0; i < s; ++i) {
    std::string tmp;
    std::cin >> tmp;

    if (dic[tmp] == 1) {
      ++result;
    }
  }
  std::cout << result << "\n";
  return (0);
}