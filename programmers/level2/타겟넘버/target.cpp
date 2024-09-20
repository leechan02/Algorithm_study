#include <string>
#include <vector>
#include <iostream>

int t, ans;

void dfs(std::vector<int> &n, int level, int sum) {
    if (level == n.size()) {
        if (sum == t) ++ans;
        return;
    }
    
    for (auto i : {1, -1}) {
        sum += (i * n[level]);
        dfs(n, level + 1, sum);
        sum -= (i * n[level]);
    }
}

int solution(std::vector<int> numbers, int target) {
    t = target;
    
    dfs(numbers, 0, 0);
    
    return ans;
}