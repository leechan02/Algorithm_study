#include <iostream>

struct node {
  node *parent;
  int num;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N;
  std::cin >> N;

  int a, b;
  for (int i = 0; i < N; i++) {
    std::cin >> a >> b;
    insert(a, b);
  }
  return 0;
}