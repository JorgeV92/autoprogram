#include <iostream>
#include <vector>

using namespace std; 

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    int dir[5] = {-1, 0, 1, 0, -1};

    auto valid = [&](int x, int y) {
        return (0 <= x && x < m && 0 <= y && y < n);
    };

    auto dfs = [&](auto&& dfs, int r, int c, int ii) -> bool {
        if (ii == word.size()) {
            return true;
        }

        if (!valid(r, c) || board[r][c] == '#' || 
            board[r][c] == word[ii]) return false;

        board[r][c] = '#';
        bool tmp = false;
        for (int k = 0; k < 4; k++) {
            int nr = r + dir[k];
            int nc = c + dir[k+1];
            tmp = tmp || dfs(dfs, nr, nc, ii+1); 
        }

        board[r][c] = '#';
        return tmp;
    };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (dfs(dfs, i, j, 0))  
                return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}