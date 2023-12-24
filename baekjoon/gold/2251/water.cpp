#include <iostream>
#include <queue>

int Sender[] = {0, 0, 1, 1, 2, 2};
int Receiver[] = {1, 2, 0, 2, 0, 1};

bool visited[201][201];
bool answer[201];
int now[3];

void BFS() {
  std::queue<std::pair<int , int>> queue;
  queue.push(std::make_pair(0, 0));
  visited[0][0] = true;
  answer[now[2]] = true;

  while (!queue.empty()) {
    std::pair<int, int> p = queue.front();
    queue.pop();
    int a = p.first;
    int b = p.second;
    int c = now[2] - a - b;

    for (int k = 0; k < 6; ++k) {
      int next[] = {a, b, c};
      next[Receiver[k]] += next[Sender[k]];
      next[Sender[k]] = 0;

      if (next[Receiver[k]] > now[Receiver[k]]) {
        next[Sender[k]] = next[Receiver[k]] - now[Receiver[k]];
        next[Receiver[k]] = now[Receiver[k]];
      }
      if (!visited[next[0]][next[1]]) {
        visited[next[0]][next[1]] = true;
        queue.push(std::make_pair(next[0], next[1]));
        if (next[0] == 0) {
          answer[next[2]] = true;
        }
      }
    }
  }
}

int main() {
  std::cin >> now[0] >> now[1] >> now[2];
  BFS();

  for (int i = 0; i < 201; ++i) {
    if (answer[i]) {
      std::cout << i << " ";
    }
  }
  return (0);
}