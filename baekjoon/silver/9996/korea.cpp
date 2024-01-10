#include <algorithm>
#include <iostream>

int words;
std::string pattern;

int main() {
  std::cin >> words >> pattern;

  std::string front, back;
  auto it = std::find(pattern.begin(), pattern.end(), '*');
  auto dis = std::distance(pattern.begin(), it);
  front = pattern.substr(0, dis);
  back = pattern.substr(dis + 1, pattern.size() - 1);

  for (int i = 0; i < words; ++i) {
    std::string tmp, comFront, comBack;
    std::cin >> tmp;

    int t = tmp.size(), f = front.size(), b = back.size();
    if (t >= f && t >= b && t >= f + b) {
      comFront = tmp.substr(0, front.size());
      comBack = tmp.substr(tmp.size() - back.size(), tmp.size() - 1);
      if (comFront == front && comBack == back) {
        std::cout << "DA\n";
      } else {
        std::cout << "NE\n";
      }
    } else {
      std::cout << "NE\n";
    }
  }
}