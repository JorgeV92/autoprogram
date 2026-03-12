#include <iostream>
#include <vector>

using namespace std; 

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> cs, maths, pe;
    for (int i = 0; i < n;i++) {
        int x;
        cin >> x;
        if (x == 1) {
            cs.push_back({x, i+1});
        } else if (x==2) {
            maths.push_back({x, i+1});
        } else { 
            pe.push_back({x, i+1});
        }
    }

    int mn = min(cs.size(), min(maths.size(), pe.size()));
    cout << mn << '\n';
    for (int i = 0; i < mn; i++) {
        cout << cs[i].second << ' ' << maths[i].second << ' ' << pe[i].second << '\n';
    }
 
    return 0;
}

/*
int n, m;
vector<int> a[4];
 
int main(){
     //freopen("a.in", "r", stdin);
     //freopen("a.out", "w", stdout);
     scanf("%d", &n);
     for (int i = 0; i < 4; i++) a[i].clear();
     for (int i = 1; i <= n; i++)
     {
          int x;
          scanf("%d", &x);
          a[x].push_back(i);
     }
     int m = min(min(a[1].size(), a[2].size()), a[3].size());
     printf("%d\n", m);
     for (int i = 0; i < m; i++) printf("%d %d %d\n", a[1][i], a[2][i], a[3][i]);
}
*/