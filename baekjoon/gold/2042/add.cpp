#include <iostream>
#include <vector>
#include <cmath>

std::vector<long long> tree;

void setTree(int i) {
  while (i != 1) {
    tree[i / 2] += tree[i];
    --i;
  }
}

void changeValue(int index, long long value) {
  long long diff = value - tree[index];

  while (index > 0) {
    tree[index] = tree[index] + diff;
    index = index / 2;
  }
}

long long getSum(int b, int c) {
  long long partSum = 0;

  while (b <= c) {
    if (b % 2 == 1) {
      partSum += tree[b];
      ++b;
    }
    if (c % 2 == 0) {
      partSum += tree[c];
      --c;
    }
    b /= 2;
    c /= 2;
  }
  return partSum;
}

int main() {
  int n, m, k;
  std::cin >> n >> m >> k;
  int treeHeight = 0;
  int length = n;

  while (length != 0) {
    length /= 2;
    ++treeHeight;
  }
  int treeSize = int(std::pow(2, treeHeight + 1));
  int leftNodeStartindex = treeSize / 2 - 1;
  tree.resize(treeSize + 1);

  for (int i = leftNodeStartindex + 1; i <= leftNodeStartindex + n; ++i) {
    std::cin >> tree[i];
  }
  setTree(treeSize - 1);

  for (int i = 0; i < m + k; ++i) {
    long long a, b, c;
    std::cin >> a >> b >> c;

    if (a == 1) {
      changeValue(leftNodeStartindex + b, c);
    } else {
      b += leftNodeStartindex;
      c += leftNodeStartindex;
      std::cout << getSum(b, c) << "\n";
    }
  }
}