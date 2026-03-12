#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

void sort2(int& a, int& b) {
    if (a > b) {
        int tmp {a};
        a = b;
        b = tmp;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x {7};
    int y {5};
    cout << x << " " << y << endl;
    sort2(x, y);
    cout << x << " " << y << endl;
    sort2(x, y);
    cout << x << " " << y << endl;
    return 0;
}