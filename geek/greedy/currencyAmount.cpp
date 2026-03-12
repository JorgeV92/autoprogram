#include <iostream>
#include <vector>

using namespace std;

void countCurrency(int amount) {
    vector<int> notes {2000, 500, 200, 
                        100, 50, 20, 10, 5, 1};
    vector<int> counter(9,0);
    for (int i =0 ; i < 9; i++) {
        if (amount >= notes[i]) {
            counter[i] = amount / notes[i];
            amount = amount % notes[i];
        }
    }

    for (int i = 0; i < 9; i++) {
        if (counter[i] > 0) {
            cout << notes[i] << ": " << counter[i] << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}