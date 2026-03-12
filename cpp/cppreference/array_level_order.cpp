#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <string_view>
#include <map>
#include <set>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define OUT(x) cout << x << '\n'
#define all(x) (x).begin(), (x).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++) 
#define FORE(i,a,b) for(int i = (a); i <= (b); i++)
#define ROF(i,a,b) for(int i = (a); i >= (b); i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return false;}
template<class T> inline bool chmin(T& a, T b) { if ( a > b) { a = b; return 1;} return false;}

using ll = long long;
using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {7, 4, 12, 3, 6, 8, 1, 5, 10};    

    auto levelOrderIsOfBST = [&](const vector<int>& a) {
        int n= a.size();
        if (n == 0) return true;
        queue<tuple<int,int,int>> q;
        q.push({a[0], INT_MIN, INT_MAX});
        int idx = 1;
        while (idx != n && !q.empty()) {
            auto tmp = q.front();
            q.pop();
            int node,start,end;
            tie(node,start,end) = tmp;
            if (start <= a[idx] && a[idx] < node) {
                q.push({a[idx], start, node-1});
                idx++;
            }
            if (idx < n && node < a[idx] && a[idx] <= end) {
                q.push({a[idx],node+1,end});
                idx++;
            }
        }
        if (idx == n) {
            return true;
        } else {
            return false;
        }
    };
 
    if (levelOrderIsOfBST(arr))
        cout << "True";
    else
        cout << "False";  
    return 0;
}