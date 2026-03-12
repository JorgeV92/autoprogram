#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

vector<vector<int>> grid;
int dir[5] = {-1,0,1,0,-1};
int n, m;
int color, old_color;

bool valid(int r, int c) {
    return (0 <= r && r < n && 0 <= c && c < m);
}

void dfs(int r, int c) {
    grid[r][c] = color;
    for (int k = 0; k < 4; k++) {
        int nr = r + dir[k];
        int nc = c + dir[k+1];
        if (valid(nr, nc) && grid[nr][nc] == old_color) {
            dfs(nr, nc);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& img, 
                             int sr, int sc, int newColor)  {
    if (img[sr][sc] == newColor) return img;
    n = img.size();
    m = img[0].size();
    old_color = img[sr][sc];
    color = newColor;
    dfs(sr, sc);
    return grid;
}

vector<vector<int>> floodFill(vector<vector<int>>& img, 
                             int sr, int sc, int newColor) {

    if (img[sr][sc] == newColor) return img;
    int old_color = img[sr][sc];
    using pii = pair<int,int>;
    int dir[5] = {-1,0,1,0,-1};
    queue<pii> q;
    q.push({sr, sc});

    auto valid = [&](int x, int y) {
        return (0 <= x && x < img.size() && 0 <= y && y < img[0].size());
    };
    
    img[sr][sc] = newColor;
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nr = r + dir[k];
            int nc = c + dir[k+1];

            if (valid(nr, nc) && img[nr][nc] == old_color) {
                img[nr][nc] = newColor;
                q.push({nr,nc});
            }
        }   
    }

    return img;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}