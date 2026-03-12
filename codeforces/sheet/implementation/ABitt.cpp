#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n{};
    cin >> n;
    int x =0;
    for (int i =0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "X++" || s == "++X") {
            x++;
        } else {
            x--;
        }
    }
    cout << x << '\n';
    return 0;   
}