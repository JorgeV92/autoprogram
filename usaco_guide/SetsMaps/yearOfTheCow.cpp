#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    map<string, int> mp;
    mp["Ox"] = 0;
    mp["Tiger"] = 1;
    mp["Rabbit"] = 2;
    mp["Dragon"] = 3;
    mp["Snake"] = 4;
    mp["Horse"] = 5;
    mp["Goat"] = 6;
    mp["Monkey"] = 7;
    mp["Rooster"] = 8;
    mp["Dog"] = 9;
    mp["Pig"] = 10;
    mp["Rat"] = 11;


    map<string, int> B;
    B["Bessie"] = 0;

    for (int i = 0; i < n; i++) {
        string cowA, born, in, relation, animal, year, from, cowB;
        cin >> cowA >> born >> in >> relation >> animal >> year >> from >> cowB;

        int b_year = B[cowB];
        int b_zodiac = ((b_year % 12) + 12) % 12;
        int t = mp[animal];

        int diff;
        if (relation == "previous") {
            diff = (b_zodiac - t + 12) % 12;
            if (diff == 0) diff = 12;
            B[cowA] = b_year - diff;
        } else {
            diff = (t - b_zodiac + 12) % 12;
            if (diff == 0) diff = 12;
            B[cowA] = b_year + diff;
        }
    }

    cout << abs(B["Elsie"]) << endl;

    return 0;
}