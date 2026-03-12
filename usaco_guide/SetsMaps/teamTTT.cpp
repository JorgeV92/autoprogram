#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> b(3);
    for (int i = 0 ; i < 3; i++) cin >> b[i];

    set<char> X;    // single winners;
    set<pair<int,int>> Y;   // team winners

    auto check = [&](char a, char b, char c) {
        set<char> D;
        D.insert(a);
        D.insert(b);
        D.insert(c);

        if (D.size() == 1) {
            X.insert(*D.begin());
        } else if (D.size() == 2) {
            auto it = D.begin();
            char f = *it;
            it = next(it);
            char s = *it;
            Y.insert({f, s});
        }
         
    };

    for (int i = 0; i < 3 ; i++) {
        check(b[i][0], b[i][1], b[i][2]);
    }

    for (int j = 0; j < 3; j++) {
        check(b[0][j], b[1][j], b[2][j]);
    }

    for (int k = 0; k < 3; k++) {
        check(b[0][0], b[1][1], b[2][2]);
    }

    for (int k = 0; k < 3; k++) {
        check(b[0][2], b[1][1], b[2][0]);
    }

    cout << X.size() << endl;
    cout << Y.size() << endl;


    return 0;   
}