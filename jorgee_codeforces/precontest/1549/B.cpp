#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> board(2);
    for (int i = 0; i < 2; i++) {
        cin >> board[i];
    } 
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (board[1][i] == '0') {
            continue;
        } 
        if (i > 0 && board[0][i-1] == '1') {
            ans++;
            board[0][i-1] = '2';
        } else if (board[0][i] == '0') {
            ans++;
            board[0][i] = '2';
        } else if (i < n-1 && board[0][i+1] == '1') {
            ans++;
            board[0][i+1] = '2';
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

/*
        001010
        000100
*/  