#include <iostream>
#include <queue>

std::queue<int> split2(std::queue<std::string> plus) {
  std::queue<int> ret;
  while (!plus.empty()) {
    std::string tmp = plus.front();
    int add = 0;
    for (int i = 0; i < tmp.size(); ++i) {
      std::string num;
      while (tmp[i] != '+' && i < tmp.size()) {
        num += tmp[i++];
      }
      add += std::atoi(num.c_str());
    }
    ret.push(add);
    plus.pop();
  }
  return ret;
}

std::queue<std::string> split(std::string str) {
  std::queue<std::string> ret;
  for (int i = 0; i < str.size(); ++i) {
    std::string tmp;
    while (str[i] != '-' && i < str.size()) {
      tmp += str[i++];
    }
    ret.push(tmp);
    tmp.clear();
  }
  return ret;
}

int main() {
  std::string tmp;
  std::cin >> tmp;

  std::queue<std::string> plus = split(tmp);
  std::queue<int> minus = split2(plus);
  int res = minus.front();
  minus.pop();
  while (!minus.empty()) {
    int tmp = minus.front();
    res -= tmp;
    minus.pop();
  }
  std::cout << res << '\n';
  return (0);
}