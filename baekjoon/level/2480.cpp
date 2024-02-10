#include <iostream>
#include <algorithm>

int first, second, third, max;

int main() {
  std::cin >> first >> second >> third;

  if (first == second && first == third && second == third) {
    std::cout << 10000 + first * 1000 << "\n";
  } else if (first != second && first != third && second != third) {
    max = std::max(first, second);
    max = std::max(max, third);
    std::cout << max * 100 << "\n";
  } else {
    if (first == second || first == third) {
      max = first;
    } else {
      max = second;
    }
    std::cout << 1000 + max * 100 << "\n";
  }
}