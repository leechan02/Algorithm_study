#include <iostream>
#include <sstream>
#include <vector>

int main() {
  double N, tmp, max = 0;
  std::vector<double> exam;

  std::cin >> N;

  for (int i = 0; i < N; ++i) {
    std::cin >> tmp;
    if (tmp > max) {
      max = tmp;
    }
    exam.push_back(tmp);
  }

  double result = 0;
  for (std::vector<double>::iterator it = exam.begin(); it != exam.end();
       ++it) {
    result += (*it / max * 100);
  }
  std::cout << result / N << std::endl;
  return (0);
}