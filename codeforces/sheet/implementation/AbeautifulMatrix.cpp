#include <iostream>
#include <vector>
#include <cmath>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r{};
    int c{};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                r = i;
                c = j;
                break;
            }
        }
    }

    int moves = 0;  
    moves += abs(r- 2);
    moves += abs(c - 2);
    cout << moves << '\n';

    return 0;   
}