#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <queue>

using namespace std; 

unordered_map<string, vector<string>> adj;

int dfs(string v) {
    int depth = 0;
    for (string& u : adj[v]) {
        depth = max(depth, dfs(u));
    } 
    return depth + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0 ;i < n; i++) {
        string first, middle, second;
        cin >> first >> middle >> second;
        transform(first.begin(), first.end(), first.begin(), ::tolower);
        transform(second.begin(), second.end(), second.begin(), ::tolower);
        adj[second].push_back(first);
    }   

    cout << dfs("polycarp") << endl;
    return 0;   
}