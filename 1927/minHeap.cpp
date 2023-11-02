#include <iostream>

const int MAX_SIZE = 100001;

class MinHeap {
private:
  int data[MAX_SIZE];
  int size;

public:
  MinHeap() : size(0) {}

  int pop() {
    if (size == 0) {
      return 0;
    }

    int ret = data[0];
    int lastIdx = size - 1;

    data[0] = data[lastIdx];
    size--;

    int i = 0;
    while (true) {
      int leftChild = 2 * i + 1;
      int rightChild = 2 * i + 2;

      if (leftChild >= size) {
        break; // No children.
      }

      int smallerChild =
          (rightChild >= size || data[leftChild] <= data[rightChild])
              ? leftChild
              : rightChild;

      if (data[i] > data[smallerChild]) {
        std::swap(data[i], data[smallerChild]);
        i = smallerChild;
      } else {
        break;
      }
    }
    return ret;
  }

  void push(int n) {
    data[size] = n;
    int i = size;
    size++;

    while (i > 0) {
      int parent = (i - 1) / 2;
      if (data[parent] > data[i]) {
        std::swap(data[i], data[parent]);
        i = parent;
      } else {
        break;
      }
    }
  }
};

int main() {
  MinHeap heap;
  int N;
  std::cin >> N;

  for (int i = 0; i < N; ++i) {
    int num;
    std::cin >> num;

    if (num == 0) {
      std::cout << heap.pop() << '\n';
    } else {
      heap.push(num);
    }
  }
  return 0;
}
