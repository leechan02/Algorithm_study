#include <iostream>
#include <vector>

std::vector<int> node;

int find(int i) {
  if (node[i] == i) {
    return (i);
  } else {
    return (node[i] = find(node[i]));
  }
}

void unionfunc(int a, int b) {
  a = find(a);
  b = find(b);

  if (a != b) {
    node[b] = a;
  }
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

  int n, m;
  std::cin >> n >> m;

  node = std::vector<int>(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    node[i] = i;
  }

  for (int i = 1; i <= n; ++i) {
    for (int ii = 1; ii <= n; ++ii) {
      int isConnect;
      std::cin >> isConnect;
      if (isConnect) {
        unionfunc(i, ii);
      }
    }
  }

  int parent = 0;
  for (int i = 0; i < m; ++i) {
    int ii, iii;
    std::cin >> ii;
    iii = find(ii);
    if (parent != 0 && parent != iii) {
      std::cout << "NO\n";
      return (0);
    }
    parent = iii;
  }
  std::cout << "YES\n";
  return (0);
}