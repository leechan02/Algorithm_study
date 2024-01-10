#include <iostream>
#include <algorithm>

int a[5];

void print() {
  for (int i = 0; i < 3; ++i) {
    std::cout << a[i] << " ";
  }
  std::cout << "\n";
}

void makePer(int depth) {
  if (depth == 3) {
    print();
    return ;
  }
  for (int i = depth; i < 5; ++i) {
    std::swap(a[i], a[depth]);
    makePer(depth + 1);
    std::swap(a[i], a[depth]);
  }
}

int main() {
  for (int i = 0; i < 5; ++i) {
    a[i] = i + 1;
  }
  makePer(0);
}