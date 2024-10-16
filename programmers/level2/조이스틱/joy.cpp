#include <algorithm>
#include <string>

using namespace std;

int solution(string name) {
  int n = name.size();
  int move = n - 1;

  int answer = 0;

  for (int i = 0; i < n; ++i) {
    answer += min(name[i] - 'A', 'Z' - name[i] + 1);

    int next_idx = i + 1;
    while (next_idx < n && name[next_idx] == 'A') {
      ++next_idx;
    }

    move = min(move, i + n - next_idx + min(i, n - next_idx));
  }

  answer += move;
  return answer;
}