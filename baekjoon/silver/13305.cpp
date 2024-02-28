#include <iostream>
#include <vector>

long long n, money, minOil;
long long dist[100004];
long long oil[100004];

int main() {
  std::cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    std::cin >> dist[i];
  }
  for (int i = 0; i < n; ++i) {
    std::cin >> oil[i];
  }

  minOil = oil[0];
  for (int i = 0; i < n - 1; ++i) {
    if (oil[i] < minOil) {
      minOil = oil[i];
    }
    money += minOil * dist[i];
  }
  std::cout << money << "\n";
}