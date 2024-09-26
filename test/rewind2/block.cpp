#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
struct pos {
    int y, x;
};
vector<pos> obs;

void checkBlockPos(const vector<vector<char>>& board) {
    obs.clear();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == '#') {
                obs.push_back({i, j});
            }
        }
    }
}

bool canDrop(vector<vector<char>>& board) {
    bool dropped = true;
    while (dropped) {
        dropped = false;
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == '*' && board[i + 1][j] == '-') {
                    board[i + 1][j] = '*';
                    board[i][j] = '-';
                    dropped = true;
                }
            }
        }
    }
    
    for (int j = 0; j < m; ++j) {
        if (board[n - 1][j] == '*') {
            return true;
        }
    }
    return false;
}

int backtrack(vector<vector<char>>& board, int index, int removed) {
    if (canDrop(board)) {
        return removed;
    }
    
    if (index >= obs.size()) {
        return INT_MAX;
    }
    
    int result = INT_MAX;
    
    result = min(result, backtrack(board, index + 1, removed));
    
    pos current = obs[index];
    board[current.y][current.x] = '-';
    result = min(result, backtrack(board, index + 1, removed + 1));
    board[current.y][current.x] = '#';
    
    return result;
}

int solution(vector<vector<char>> board) {
    n = board.size();
    m = board[0].size();
    checkBlockPos(board);
    
    int result = backtrack(board, 0, 0);
    return result == INT_MAX ? -1 : result;
}

int main() {
    vector<vector<char>> map = {
        {'*', '*', '*', '-'},
        {'#', '*', '*', '-'},
        {'*', '*', '*', '-'},
        {'-', '-', '-', '-'},
        {'-', '-', '#', '#'}
    };
    vector<vector<char>> map2 = {
        {'*', '*', '*'},
        {'*', '-', '*'},
        {'*', '-', '*'},
        {'-', '#', '-'},
        {'-', '#', '-'}
    };
    cout << solution(map) << endl;
    cout << solution(map2) << endl;
    return 0;
}