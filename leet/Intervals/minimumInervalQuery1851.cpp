#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& q) {
    using pii = pair<int,int>;
    vector<pii> Q;
    for (int i = 0; i < q.size(); i++) {
        Q.push_back({q[i], i});
    }
    sort(intervals.begin(), intervals.end());
    sort(Q.begin(), Q.end());
    priority_queue<pii,vector<pii>,greater<pii>> h;
    vector<int> out(Q.size(), -1);
    int i = 0;
    for (int j = 0; j < Q.size(); j++) {
        int cur = Q[j].first;
        while (i < intervals.size() && intervals[i][0] <= cur)  {
            h.push({intervals[i][1] - intervals[i][0] + 1, intervals[i++][1]});
        }
        while (!h.empty() && cur > h.top().second) {
            h.pop();
        }
        if (!h.empty()) {
            out[Q[j].second] = h.top().first;
        }
    }
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}