#include <iostream>

int t,a,b;

int main() {
  std::ios_base::sync_with_stdio(0); std::cin.tie(0);

  std::cin >> t;
  while(t--) {
    std::cin >> a >> b;
    std::cout << a + b << "\n";
  }
}