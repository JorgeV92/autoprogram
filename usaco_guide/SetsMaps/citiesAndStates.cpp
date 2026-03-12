#include <iostream>
#include <map>
#include <string>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    map<string,long long> seen;
    long long total = 0;

    for (int i = 0; i < n; i++) {
        string city, state;
        cin >> city >> state;
        string prefix = city.substr(0, 2);
        if (prefix != state) {
            string mycode = prefix + state;
            string target = state + prefix;
            total += seen[target];
            seen[mycode]++;
        }
    }
    
    cout << total << endl;

    return 0;
}   