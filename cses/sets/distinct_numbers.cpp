#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    set<int> se;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        se.insert(a);
    }

    cout << se.size() << endl;

    return 0;
}