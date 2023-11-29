#include <iostream>
#include <sstream>
#include <vector>

int main() {
  int N, result = 0;
  std::string num;

  std::cin >> N;
  std::cin >> num;

  for (int i = 0; i < N; ++i) {
    std::stringstream ss;
    int tmp;

    ss << num[i];
    ss >> tmp;
    result += tmp;
  }
  std::cout << result << std::endl;

  return (0);
}