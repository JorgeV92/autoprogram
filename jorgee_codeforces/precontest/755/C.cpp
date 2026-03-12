#include <iostream>
#include <vector>
#include <set>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    set<int> end;
    int trees = 0;
    for (int i =1 ; i <= n; i++) {
        int a;
        cin >> a;

        if (a == i) {
            trees++;
        } else {
            end.insert(a);
        }
    }

    cout << trees + end.size() / 2 << endl;

    return 0;
}