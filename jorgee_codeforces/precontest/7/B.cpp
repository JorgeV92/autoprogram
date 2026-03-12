#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <map>

using namespace std;

int main() {    
    ios::sync_with_stdio(0); cin.tie(0);
    int t, m;
    cin >> t >> m;
    
    vector<int> mem(m, 0);
    map<int, pair<int, int>> blocks;
    int nextId = 1;

    while (t--) {
        string op;
        cin >> op;

        if (op == "alloc") {
            int n ;
            cin >> n;
            int start = -1;
            for (int i = 0; i + n <= m; i++) {
                bool ok = true;
                for (int j = i; j < i + n; j++) {
                    if (mem[j] != 0) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    start = i;
                    break;
                }
            }

            if (start == -1) {
                cout << "NULL\n";
            } else {
                int id = nextId++;
                for (int i = start; i < start + n; i++) {
                    mem[i] = id;
                }
                blocks[id] = {start, n};
                cout << id << "\n";
            }
        } else if (op == "erase") {
            int x;
            cin >> x;

            if (!blocks.count(x)) {
                cout << "ILLEGAL_ERASE_ARGUMENT\n";
            } else {
                auto [start, len] = blocks[x];
                for (int i = start; i < start + len; i++) {
                    mem[i] = 0;
                }
                blocks.erase(x);
            }
        } else if (op == "defragment") {
            vector<int> new_mem(m, 0);
            int pos = 0;
            for (int i = 0; i < m;) {
                if (mem[i] == 0) {
                    i++;
                    continue;
                }
                int id = mem[i];
                int len = blocks[id].second;
                for (int j = 0; j < len; j++) {
                    new_mem[pos+j] = id;
                }
                blocks[id].first = pos;
                pos += len;
                i += len;
            }
            mem = new_mem;
        }
    }
    
    return 0;   
}