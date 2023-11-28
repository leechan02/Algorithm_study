#include <iostream>
#include <set>

int main() {
  int N, tmp;

  std::cin >> N;
  std::set<int> arr;
  for (int i = 0; i < N; ++i) {
    std::cin >> tmp;
    arr.insert(tmp);
  }

  for (std::set<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
    std::cout << *it << std::endl;
  }
}