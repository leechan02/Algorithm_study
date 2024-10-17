#include <stack>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
  int n = numbers.size();
  vector<int> answer(n, -1);
  stack<int> s;

  for (int i = n - 1; i >= 0; --i) {
    while (!s.empty() && s.top() <= numbers[i]) {
      s.pop();
    }

    if (!s.empty()) {
      answer[i] = s.top();
    }

    s.push(numbers[i]);
  }

  return answer;
}