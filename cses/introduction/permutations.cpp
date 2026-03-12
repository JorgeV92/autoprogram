#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    
    vector<int> ans;
    for (int i = 1; i <= n; i += 2) {
        ans.push_back(i);
    }  

    for (int i = 2; i <= n; i += 2) {
        ans.push_back(i);
    }

    if (n == 4) {
        ans = {2, 4, 1 , 3};
    }

    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    
    

    return 0;
}
