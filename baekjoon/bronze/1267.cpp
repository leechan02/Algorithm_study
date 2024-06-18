#include <iostream>
#include <vector>

int n, tmp, y, m;
std::vector<int> call;

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> tmp;
    call.push_back(tmp);
  }

  for (auto i : call) {
    if (i < 30) {
      y += 10;
    } else {
      y += ((i / 30) + 1) * 10;
    }
    if (i < 60) {
      m += 15;
    } else {
      m += ((i / 60) + 1) * 15;
    }
  }

  if (y > m) {
    std::cout << "M " << m << "\n";
  } else if (m > y) {
    std::cout << "Y " << y << "\n";
  } else {
    std::cout << "Y M " << y << "\n";
  }
}