#include <iostream>
#include <vector>

using namespace std; 

vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
    if (f.empty() || s.empty()) {
        return {};
    }
    int n = f.size(), m = s.size();
    int i = 0, j = 0;
    vector<vector<int>> out;
    while (i < n && j < m) {
        int start = max(f[i][0], s[j][0]);
        int end = min(f[i][1], s[j][1]);
        if (start <= end) {
            out.push_back({start, end});
        }
        if (f[i][1] <= s[j][1]) {
            i++;
        } else {
            j++;
        }
    }
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}