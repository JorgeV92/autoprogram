#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s{};
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> out{};
    do {
        out.push_back(s);
    } while(next_permutation(s.begin(), s.end()));
    cout << out.size() << endl;
    for (const string& str : out) {
        cout << str << endl;
    }
    
    return 0;
}