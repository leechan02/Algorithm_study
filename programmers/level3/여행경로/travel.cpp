#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> ans;
unordered_map<string, vector<string>> maps;
unordered_map<string, vector<bool>> visited;

bool dfs(string air, vector<string> &path, int n) {
    if (path.size() == n + 1) {
        ans = path;
        return true;
    }
    
    for (int i = 0; i < maps[air].size(); ++i) {
        if (!visited[air][i]) {
            visited[air][i] = true;
            path.push_back(maps[air][i]);
            
            if (dfs(maps[air][i], path, n)) return true;
            
            visited[air][i] = false;
            path.pop_back();
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    for (auto ticket : tickets) {
        maps[ticket[0]].push_back(ticket[1]);
    }
    
    for (auto& [key, value] : maps) {
        sort(value.begin(), value.end());
        visited[key] = vector<bool>(value.size(), false);
    }
    
    vector<string> path = {"ICN"};
    dfs("ICN", path, tickets.size());
    
    return ans;
}