#include <iostream>
#include <map>

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int N;
  std::cin >> N;

  std::multimap<int, int> A;
  for (int i = 0; i < N; ++i) {
    int tmp;
    std::cin >> tmp;
    A.insert(std::make_pair(tmp, i));
  }

  int max = 0;
  std::multimap<int, int>::iterator it = A.begin();
  for (int i = 0; it != A.end(); ++it, ++i) {
    if (max < it->second - i) {
      max = it->second - i;
    }
  }
  std::cout << max  + 1 << '\n';
  return (0);
}