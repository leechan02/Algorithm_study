#include <iostream>
#include <unordered_map>

struct Node {
  int num;
  Node *parent;
};

std::unordered_map<int, Node *> nodeMap;

Node *createNode(int i) {
  Node *ret = new Node;

  ret->num = i;
  ret->parent = NULL;
  nodeMap[i] = ret;
  return ret;
}

void insertNode(int a, int b){
  Node *aNode = nodeMap.count(a) ? nodeMap[a] : createNode(a);
  Node *bNode = nodeMap.count(b) ? nodeMap[b] : createNode(b);

  if (!aNode->parent && a != 1) {
    aNode->parent = bNode;
  } else if (!bNode->parent && b != 1) {
    bNode->parent = aNode;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N, a, b;
  std::cin >> N;

  createNode(1);
  for (int i = 0; i < N - 1; i++) {
    std::cin >> a >> b;
    insertNode(a, b);
  }

  for (int i = 2; i <= N; i++) {
    if (nodeMap[i]->parent) {
      std::cout << nodeMap[i]->parent->num << "\n";
    }
  }
  return 0;
}