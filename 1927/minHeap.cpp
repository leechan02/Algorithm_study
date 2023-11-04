#include <iostream>
#include <vector>

class minHeap {
public:
  int pop() {
    if (heap.size() == 0)
      return 0;

    int ret = heap[0];
    int lastIdx = heap.size() - 1;

    std::swap(heap[0], heap[lastIdx]);
    heap.pop_back();

    int parent = 0;
    int child;
    while (true) {
      child = parent * 2 + 1;
      if (child + 1 <= lastIdx - 1 && heap[child] > heap[child + 1])
        child++;
      if (child > lastIdx - 1 || heap[child] > heap[parent])
        break;
      std::swap(heap[child], heap[parent]);
      parent = child;
    }
    return ret;
  }

  void push(int num) {
    heap.push_back(num);

    int i = heap.size() - 1;
    if (i == 0)
      return;

    int parent;
    while (i > 0) {
      parent = (i - 1) / 2;
      if (heap[i] < heap[parent])
        std::swap(heap[i], heap[parent]);
      else
        break;
      i = parent;
    }
  }

private:
  std::vector<int> heap;
};

int main() {
  minHeap minHeap;
  int N;
  scanf("%d", &N);

  for (int i = 0; i < N; ++i) {
    int num;
    scanf("%d", &num);

    if (num == 0) {
      printf("%d\n", minHeap.pop());
    } else {
      minHeap.push(num);
    }
  }
  return 0;
}
