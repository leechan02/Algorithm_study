#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

int ans;
struct level{
	string w; int i;
};

bool isChange(string cur, string word) {
    int num = 0;
    for (int i = 0; i < cur.size(); ++i) {
        if (cur[i] != word[i]) ++num;
        if (num > 1) return false;
    }
    return true;
}

void bfs(string begin, string target, vector<string> words) {
    auto it = find(words.begin(), words.end(), target);
    if (it == words.end()) return;
    
    queue<level> q;
    unordered_set<string> visited;
    q.push({begin, 0});
    visited.insert(begin);
    
    while (!q.empty()) {
        auto [cur, i] = q.front();
        q.pop();
        
        if (cur == target) {
            ans = i;
            return ;
        }
        
    	for (auto word : words) {
            if (visited.find(word) == visited.end() && isChange(cur, word)) {
                q.push({word, i + 1});
                visited.insert(word);
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    bfs(begin, target, words);
    return ans;
}