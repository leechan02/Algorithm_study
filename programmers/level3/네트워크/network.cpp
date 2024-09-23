#include <string>
#include <vector>
#include <iostream>

int num;
bool visited[201][201];

void dfs(std::vector<std::vector<int>> com, int i) {
    for (int j = 0; j < num; ++j) {
        if (visited[i][j] == true || com[i][j] == 0) continue;
        visited[i][j] = true;
        dfs(com, j);
    }
}

int solution(int n, std::vector<std::vector<int>> computers) {
    int answer = 0;
    num = n;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
        	if (visited[i][j] == false && computers[i][j] == 1) {
        		dfs(computers, i);
            	++answer;
        	}
        }
    }
    return answer;
}