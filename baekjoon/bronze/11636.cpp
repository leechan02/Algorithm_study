#include <iostream>
#include <vector>

int t;

int main() {
  std::cin >> t;
  std::cin.ignore();
  while (t--) {
    std::vector<int> sequence;
    int number;
    while (std::cin >> number && number != 0) {
      sequence.push_back(number);
    }
    int importCount = 0;
    for (size_t i = 1; i < sequence.size(); ++i) {
      if (sequence[i] > 2 * sequence[i - 1]) {
        importCount += (sequence[i] - 2 * sequence[i - 1]);
      }
    }
    std::cout << importCount << "\n";
  }
}