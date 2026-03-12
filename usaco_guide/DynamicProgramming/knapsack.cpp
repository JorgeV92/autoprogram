#include <iostream>
#include <vector>

using namespace std;

struct item {
    int v, k;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int S, N;
    cin >> S >> N;
    vector<item> by_weight[2005];
    for (int i = 0; i < N; i++) {
        int v, w, k;
        cin >> v >> w >> k;
        if (w <= S) {
            by_weight[w].push_back({v, k});
        }
    }

    vector<pair<int,int>> distince_items;
    for (int w = 1; w <= S; w++) {
        if (by_weight[w].empty()) continue;
        sort(by_weight[w].begin(), by_weight[w].end(), [](const auto& a, const auto& b) {
            return a.v > b.v;
        });
        int max_copies = S / w;
        int count_taken = 0;
        for (auto& i : by_weight[w]) {
            int take = min(i.k, max_copies - count_taken);
            int k_reamining = take;
            int power = 1;
            while (k_reamining > 0) {
                int bundle_size = min(power, k_reamining);
                distince_items.push_back({w * bundle_size, i.v * bundle_size});
                k_reamining -= bundle_size;
                power *= 2;
            }
            count_taken += take;
        }
    }
    
    vector<long long> dp(S+1 ,0);
    for (auto & i : distince_items) {
        int w = i.first;
        int v = i.second;
        for (int j = S; j >= w; j--) {
            dp[j] = max(dp[j], dp[j-w] + v);
        }
    }

    cout << dp[S] << endl;

    return 0;
}