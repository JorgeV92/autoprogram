#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Return the maximum score of a valid node sequence with a length of 4.
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<vector<int>> g(n);
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        for (int i = 0; i < n; i++) {
            sort(g[i].begin(), g[i].end(), [&scores](auto i, auto j){
                return scores[j] < scores[i];
            });

            if (g[i].size() > 3) {
                g[i].resize(3);
            }
        }
        int mx = -1;
        for (const auto& e : edges) {
            int a = e[0];
            int b = e[1];
            for (int c : g[a]) {
                for (int d : g[b]) {
                    if (c != b && c != d && a != d) {
                        int total = scores[a] + scores[b] + scores[c] + scores[d];
                        mx = max(mx, total);
                    }
                }
            }
        }
        return mx;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    return 0;
}