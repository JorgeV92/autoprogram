#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <climits>

using namespace std;

// We have total of N items each item at a cost of v and has k copies and each copy weighs w. 
// We have a box than can hold S weight, we want the maximum V  items in the box such that we dont exceed S.   
//


int main() {

    int s, n;
    cin >> s >> n;
    
    map<int, vector<pair<int,int>>> by_weight;    

    for (int i = 0; i < n; i++) {
        int val, w, amt;
        cin >> val >> w >> amt;
        if (w <= s && amt > 0) {
            by_weight[w].push_back({val, amt});
        }
    }

    // dp[i][j] - is the max value we can get using
    // j weight and the first i weight types    
    vector<vector<long long>> dp(by_weight.size() + 1, vector<long long>(s+1, INT32_MIN)); 
    dp[0][0] = 0;
    int at = 1;
    for (auto&[w, items] : by_weight) {
        // sort items in reverse order by value
        //sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
        //    return a.first > b.first;
        //});

        sort(items.begin(), items.end(), greater<pair<int,int>>());
        for (int i = 0; i <= s; i++) {
            dp[at][i] = dp[at-1][i]; // dont take the item;
            int copies = 0;
            int type_at = 0;
            int curr_used = 0;
            long long profit = 0;

            // go through as many items until we run out of items or usable
            // weight 
            while ((copies + 1) * w <= i && type_at < items.size()) {
                copies++;
                profit += items[type_at].first;
                if (dp[at-1][i - copies * w] != INT32_MIN) {
                    dp[at][i] = max(dp[at][i], dp[at-1][i - copies * w] + profit);
                }

                curr_used++;
                if (curr_used == items[type_at].second) {
                    curr_used = 0;  
                    type_at++;
                }
            }
        }
        at++;
    }

    cout << *max_element(dp.back().begin(), dp.back().end()) << endl;

    return 0;
}
