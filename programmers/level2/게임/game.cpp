#include <vector>
#include <queue>
#include <iostream>

int ans, n, m, ny, nx;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int map[101][101];

struct pos {
    int y, x;
};

void bfs(int y, int x) {
    std::queue<pos> q;
    q.push({y, x});
    map[0][0] = 1;
    
    while (!q.empty()) {
       	auto cur = q.front(); q.pop();
    for (int i = 0; i < 4; ++i) {
       	ny = cur.y + dy[i];
       	nx = cur.x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || map[ny][nx] > 0) continue;
        map[ny][nx] = map[cur.y][cur.x] + 1;
        q.push({ny, nx});
    }
    }
}

int solution(std::vector<std::vector<int> > maps) {
    n = maps.size();
    m = maps[0].size();
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (maps[i][j] == 0) {
                map[i][j] = 1;
            } else {
                map[i][j] = 0;
            }
        }
    }
    
    bfs(0, 0);
    
    map[n - 1][m - 1] == 0 ? ans = -1 : ans = map[n -1][m - 1];
    
    return ans;
}