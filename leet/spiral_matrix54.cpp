#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    int r = 0, c = 0;
    int idx = 0;
    vector<int> ans;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    vector<vector<bool>> vis(m, vector<bool>(n));

    auto valid = [&](int x, int y) -> bool {
        return (0 <= x & x < m && 0 <= y && y < n);
    };

    for (int k = n * m; k > 0; k--) {
        ans.push_back(mat[r][c]);
        vis[r][c] = true;

        int nr = r + dx[idx];
        int nc = c + dy[idx];

        if (!valid(nr, nc) || vis[nr][nc]) {
            idx = (idx + 1) % 4;
        }

        r += dx[idx];
        c += dy[idx];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    return 0;
}