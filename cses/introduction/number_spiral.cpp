#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto run_test = [&]() {

        int row, col;
        cin >> row >> col;
        
        int layer = max(row, col);
        if (layer & 1) {
            swap(row, col);
        }

        if (col == layer) {
            // vertical part
            cout << (long long) (layer-1) * (layer-1) + 1 + row-1 << "\n";
        } else {
            assert(row == layer);
            cout << (long long) layer * layer - (col-1) << "\n";
        }
    };

    
    int T; 
    cin >> T;
    for (int i = 0; i < T; i++) {
        run_test();
    }
    
    return 0;
}
