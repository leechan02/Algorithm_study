#include <iostream>
#include <vector>

std::vector<int> people;

int find(int index) {
  if (index == people[index]) {
    return (index);
  } else {
    return (people[index] = find(people[index]));
  }
}

void unionfunc(int a, int b) {
  a = find(a);
  b = find(b);

  if (a != b) {
    people[b] = a;
  }
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

  int n, m;
  std::cin >> n >> m;

  int truth;
  std::cin >> truth;

  std::vector<int> whoKnow;
  for (int i = 0; i < truth; ++i) {
    int tmp;
    std::cin >> tmp;
    whoKnow.push_back(tmp);
  }

  people = std::vector<int>(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    people[i] = i;
  }

  std::vector<int> party[m];
  for (int i = 0; i < m; ++i) {
    int howMany;
    std::cin >> howMany;
    for (int ii = 0; ii < howMany; ++ii) {
      int tmp;
      std::cin >> tmp;
      party[i].push_back(tmp);
    }
  }

  for (int i = 0; i < m; ++i) {
    for (int ii = 0; ii < party[i].size() - 1; ++ii) {
      int iii = ii + 1;
      unionfunc(party[i][ii], party[i][iii]);
    }
  }


  int ans = m;
  for (int i = 0; i < m; ++i) {
    for (int ii = 0; ii < whoKnow.size(); ++ii) {
      int com = find(whoKnow[ii]);
      if (com == find(party[i][0])) {
        --ans;
        break;
      }
    }
  }
  std::cout << ans << '\n';
  return (0);
}