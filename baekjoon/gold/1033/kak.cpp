#include <iostream>
#include <vector>
#include <tuple>

std::vector<std::tuple<int, int, int>> A[10];
long long lcm;
bool visited[10];
long long D[10];

void DFS(int node){
  visited[node] = true;

  for (auto i : A[node]) {
    int next = std::get<0>(i);
    if (!visited[next]) {
      D[next] = D[node] * std::get<2>(i) / std::get<1>(i);
      DFS(next);
    }
  }
}

long long gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return (gcd(b, a % b));
}

int main() {
  int n;
  std::cin >> n;
  lcm = 1;

  for (int i = 0; i < n; ++i) {
    int a, b, p, q;
    std::cin >> a >> b >> p >> q;
    A[a].push_back(std::make_tuple(b, p, q));
    A[b].push_back(std::make_tuple(a, q, p));

    lcm *= (p * q / gcd(p, q));
  }
  D[0] = lcm;
  DFS(0);
  long long mgcd = D[0];
  for (int i = 1; i < n; ++i) {
    mgcd = gcd(mgcd, D[i]);
  }
  for (int i = 0; i < n; ++i) {
    std::cout << D[i] / mgcd << " ";
  }
}