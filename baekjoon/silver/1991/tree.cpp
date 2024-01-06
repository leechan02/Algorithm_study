#include <iostream>
#include <vector>

std::vector<int> tree[26];

void preOrder(int now) {
  if (now == -1) return;

  std::cout << (char)(now + 'A');
  preOrder(tree[now][0]);
  preOrder(tree[now][1]);
}

void inOrder(int now) {
  if (now == -1) return;

  inOrder(tree[now][0]);
  std::cout << (char)(now + 'A');
  inOrder(tree[now][1]);
}

void postOrder(int now) {
  if (now == -1) return;

  postOrder(tree[now][0]);
  postOrder(tree[now][1]);
  std::cout << (char)(now + 'A');
}

int main() {
  int n;
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    char now, left, right;
    std::cin >> now >> left >> right;
    int node = now - 'A';

    if (left == '.') {
      tree[node].push_back(-1);
    } else {
      tree[node].push_back(left - 'A');
    }

    if (right == '.') {
      tree[node].push_back(-1);
    } else {
      tree[node].push_back(right - 'A');
    }
  }

  preOrder(0);
  std::cout << "\n";
  inOrder(0);
  std::cout << "\n";
  postOrder(0);
  std::cout << "\n";
}