#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

int minPlatformPQ(vector<int>& arr, vector<int>& dep) {
    int n = arr.size();
    using pii = pair<int,int>;
    vector<pii> v;
    for (int i = 0; i < n; i++) {
        v.push_back({arr[i], dep[i]});
    }
    sort(v.begin(), v.end());
    priority_queue<int,vector<int>,greater<int>> h;
    int mn = 0;
    for (int i = 0; i < n; i++) {
        while (!h.empty() && h.top() < v[i].first) {
            h.pop();
        }
        h.push(v[i].second);
        mn = max(mn, (int)h.size());
    }
    return mn;
}

int minPlatformSweepLine(vector<int>& arr, vector<int>& dep) {
    int n = arr.size();
    int mn = 0;
    int mx = *max_element(dep.begin(), dep.end());
    vector<int> v(mx+2, 0);

    for (int i =0 ; i <n; i++) {
        v[arr[i]]++;
        v[dep[i]+1]--;
    } 
    int cnt = 0;
    for (int i = 0; i <= mx+1; i++) {
        cnt += v[i];
        mn = max(mn, cnt);
    }
    return mn;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}