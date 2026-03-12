#include <iostream>
#include <vector>
#include <set>

using namespace std; 

int dx[4] = {-1,1,-1,1};
int dy[4] ={-1,-1,1,1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        set<pair<int,int>> st1, st2;
        for (int i= 0 ; i < 4; i++) {
            st1.insert({x1+dx[i]*a, y1+dy[i]*b});
            st2.insert({x2+dx[i]*a, y2+dy[i]*b});
            st1.insert({x1+dx[i]*b, y1+dy[i]*a});
            st2.insert({x2+dx[i]*b, y2+dy[i]*a});
        }

        int ans = 0;
        for (auto x : st1) {
            if (st2.find(x) != st2.end()) 
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}

