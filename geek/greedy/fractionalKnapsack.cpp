#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    int n = val.size();
    using pii = pair<int,int>;
    vector<pii> f;
    for (int i = 0 ; i < n; i++) {
        f.push_back({val[i], wt[i]});
    }
    sort(f.begin(), f.end(), [](const auto& a, const auto& b) {
        double a1 = (1.0 * a.first) / a.second;
        double b1 = (1.0 * b.first) / b.second;
        return a1 > b1;
    });
    double res = 0.0;
    for (int i = 0; i < n; i++) {
        if (f[i].second <= capacity) {
            res += f[i].first;
            capacity -= f[i].second;
        } else {
            res += (1.0*f[i].first / f[i].second) * capacity;
            break;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;
    
    cout << fractionalKnapsack(val, wt, capacity) << endl;

    return 0;
}