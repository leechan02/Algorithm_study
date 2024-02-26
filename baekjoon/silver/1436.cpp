#include <iostream>
#define INF 987654321

int main() {
  int n;
  std::cin >> n;

  int cnt = 0;
  for (int i = 666; i <= INF; ++i) {
    if (std::to_string(i).find("666") != std::string::npos) {
      ++cnt;
      if (cnt == n) {
        std::cout << i << "\n";
        return (0);
      }
    }
  }
}