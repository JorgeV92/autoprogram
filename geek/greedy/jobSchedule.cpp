#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    int n = deadline.size();
    vector<int> ans{0,0};
    using pii = pair<int,int>;
    vector<pii> jobs;
    for (int i = 0;i < n; i++) {
        jobs.emplace_back(deadline[i], profit[i]);
    } 
    sort(jobs.begin(), jobs.end());
    priority_queue<int, vector<int>, greater<int>> h;
    for (int i = 0; i< n; i++) {
        if (jobs[i].first > h.size()) {
            h.push(jobs[i].second);
        } else {
            if (!h.empty() && h.top() < jobs[i].second) {
                h.pop();
                h.push(jobs[i].second);
            }
        }
    }
    while (!h.empty()) {
        ans[0]++;
        ans[1] += h.top();
        h.pop();
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> deadline = {2, 1, 2, 1, 1};
    vector<int> profit = {100, 19, 27, 25, 15};
    vector<int> ans = jobSequencing(deadline, profit);
    cout<< ans[0] << " " << ans[1] << endl;

    return 0;
}