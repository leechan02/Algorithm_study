#include <iostream>

class Node {
  public:
    Node *next[26];
    bool isEnd;
  
  public:
    Node() : isEnd(false) {
      std::fill(next, next + 26, nullptr);
    }

    ~Node() {
      for (auto& child : next) {
        delete child;
      }
    }

    void insert(const char *key) {
      if (*key == 0) {
        isEnd = true;
      } else {
        int nextIndex = *key - 'a';
        if (next[nextIndex] == nullptr) {
          next[nextIndex] = new Node();
        }
        next[nextIndex]->insert(key + 1);
      }
    }

    Node *find(const char *key) {
      if (*key == 0) {
        return this;
      }
      int nextIndex = *key - 'a';

      if (next[nextIndex] == nullptr) {
        return nullptr;
      }
      return next[nextIndex]->find(key + 1);
    }
};

int main() {
  int n, m;
  std::cin >> n >> m;
  Node *root = new Node();

  while (n--) {
    char text[501];
    std::cin >> text;
    root->insert(text);
  }

  int count = 0;
  while (m--) {
    char text[501];
    std::cin >> text;
    Node *result = root->find(text);

    if (result && result->isEnd) {
      count++;
    }
  }
  std::cout << count << "\n";
}