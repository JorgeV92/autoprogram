#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std; 

int mostBooked(int n, vector<vector<int>>& meetings) {
    vector<int64_t> rooms(n);
    vector<int> cnt(n);
    sort(meetings.begin(), meetings.end());
    for(const auto& mee : meetings)  {
        int64_t s = mee[0], e = mee[1];
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (rooms[i] <= s) {
                rooms[i] = e;
                cnt[i]++;
                found = true;
                break;
            }
        }
        if (!found) {
            int idx = min_element(rooms.begin(), rooms.end()) - rooms.begin();
            rooms[idx] += (e - s);
            cnt[idx]++;
        }
    }

    int i = max_element(cnt.begin(), cnt.end()) - cnt.begin();
    return i;
}

int mostBookedPQ(int n, vector<vector<int>>& meetings) {
    using pli = pair<long long, int>;
    priority_queue<pli, vector<pli>, greater<pli>> usedR;
    priority_queue<int, vector<int>, greater<int>> notUsed;
    vector<int> cnt(n);
    for (int i =0 ;i < n; i++) {
        notUsed.push(i);
    }
    sort(meetings.begin(), meetings.end());
    for (const auto& m : meetings) {
        long long s = m[0], e = m[1];
        while (!usedR.empty() && usedR.top().first <= s) {
            notUsed.push(usedR.top().second);
            usedR.pop();
        }
        if (!notUsed.empty()) {
            int room = notUsed.top();
            notUsed.pop();
            usedR.push({e, room});
            cnt[room]++;
        } else {
            auto [time, room] = usedR.top();
            usedR.pop();
            usedR.push({time + e - s, room});
            cnt[room]++;
        }
    }
    int idx = max_element(cnt.begin(), cnt.end()) - cnt.begin();
    return idx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}