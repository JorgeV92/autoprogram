#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    cout << s << endl;
    return 0;
}