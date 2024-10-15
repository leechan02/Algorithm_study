#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
  vector<int> status(n + 1, 1);

  for (int l : lost) {
    status[l]--;
  }

  for (int r : reserve) {
    status[r]++;
  }

  for (int i = 1; i <= n; i++) {
    if (status[i] == 0) {
      if (i - 1 >= 1 && status[i - 1] == 2) {
        status[i]++;
        status[i - 1]--;
      } else if (i + 1 <= n && status[i + 1] == 2) {
        status[i]++;
        status[i + 1]--;
      }
    }
  }

  int answer = 0;
  for (int i = 1; i <= n; i++) {
    if (status[i] >= 1) {
      answer++;
    }
  }

  return answer;
}