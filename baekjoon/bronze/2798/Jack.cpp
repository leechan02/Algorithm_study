#include <iostream>
#include <vector>

int main(int ac, char **av) {
  int N, M;

  std::cin >> N >> M;

  std::vector<int> store;
  int value;
  for (int i = 0; i < N; i++) {
    std::cin >> value;
    store.push_back(value);
  }

  int max = 0;
  int tmp = 0;
  for (std::vector<int>::iterator i = store.begin(); i != store.end() - 2;
       i++) {
    for (std::vector<int>::iterator j = i + 1; j != store.end() - 1; j++) {
      for (std::vector<int>::iterator k = j + 1; k != store.end(); k++) {
        tmp = *i + *j + *k;
        if (tmp > max && tmp <= M) {
          max = tmp;
        }
      }
    }
  }
  std::cout << max;
  return 0;
}