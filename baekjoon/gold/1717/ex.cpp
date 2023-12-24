#include <iostream>
#include <vector>

std::vector<int> parent;

int find(int a) {
  if (a == parent[a]) {
    return (a);
  } else {
    return (parent[a] = find(parent[a]));
  }
}

void unionfunc(int a, int b) {
  a = find(a);
  b = find(b);

  if (a != b) {
    parent[b] = a;
  }
}

bool checkSame(int a, int b) {
  a = find(a);
  b = find(b);

  if (a == b) {
    return true;
  }
  return false;
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

  int n, m;
  std::cin >> n >> m;
  parent.resize(n + 1);

  for (int i = 0; i <= n; ++i) {
    parent[i] = i;
  }
  for (int i = 0; i < m; ++i) {
    int question, a, b;
    std::cin >> question >> a >> b;

    if (question == 0) {
      unionfunc(a, b);
    } else {
      if (checkSame(a, b)) {
        std::cout << "YES\n";
      } else {
        std::cout << "NO\n";
      }
    }
  }
}