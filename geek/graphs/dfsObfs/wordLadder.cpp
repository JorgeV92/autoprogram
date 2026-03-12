#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std; 

int wordLadder(string start, string target, vector<string>& arr)  {
    unordered_set<string> se(arr.begin(), arr.end());
    if (se.find(target) == se.end()) return 0;
    queue<string> q;
    q.push(start);
    if (se.count(start)) {
        se.erase(start);
    }
    int t = 1;
    while (!q.empty()) {
        int sz = q.size();
        for (int j = 0; j < sz; j++) {
            string w = q.front();
            if (w == target) return t;
            q.pop();
            for (int i = 0; i < w.size(); i++) {
                char tmp = w[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == tmp) continue;
                    w[i] = c;
                    if (se.find(w) != se.end()) {
                        q.push(w);
                        se.erase(w);
                    }
                }
                w[i] = tmp;
            }
        }
        t++;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string start = "toon"; 
    string target = "plea"; 
    vector<string>arr ={"poon", "plee", "same", "poie", "plea", "plie", "poin"};
    cout << wordLadder(start, target, arr) << endl;
    return 0;
}
