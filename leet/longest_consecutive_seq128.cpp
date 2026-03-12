#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int lcs(vector<int>& a) {
    unordered_set<int> st(a.begin(), a.end());
    int mx = 0;
    for (int x : a) {
        if (st.find(x) != st.end() && st.find(x-1) == st.end()) {
            int curr = x;
            int cnt = 0;
            while (st.find(curr) != st.end()) {
                st.erase(curr);
                curr++;
                cnt++;
            }
            mx = max(mx, cnt);
        }
    }
    return mx;
}   


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}