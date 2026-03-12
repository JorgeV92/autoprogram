#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <ranges>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    using pii = pair<int,int>;
    vector<pii> pos{{0,0}};
    while (!pos.empty()) {
        sort(pos.begin(), pos.end());
        pos.erase(unique(pos.begin(), pos.end()), pos.end());
        char minc = std::ranges::min(pos | std::views::transform([&](auto& p) {
            return grid[p.first][p.second];
        }));
        cout << minc;
        decltype(pos) nxtpos;
        for (auto [r, c] : pos) {
            if (grid[r][c] == minc) {
                if (r + 1 < n) nxtpos.emplace_back(r+1, c);
                if (c + 1 < n) nxtpos.emplace_back(r, c+1);
            }
        }
        pos = nxtpos;
    }
    
    return 0;
}