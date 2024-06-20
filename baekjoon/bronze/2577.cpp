#include <iostream>
#include <string>

int a, b, c, ans;
int num[10];
std::string result;

int main() {
  std::cin >> a >> b >> c;
  ans = a * b * c;
  result = std::to_string(ans);

  for (auto i : result) {
    num[i - '0']++;
  }

  for (auto i : num) {
    std::cout << i << "\n";
  }
}