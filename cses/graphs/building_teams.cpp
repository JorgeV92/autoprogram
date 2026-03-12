#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
int N, M;
vector<int> color;

bool dfs(int v) {
    int color_u = color[v] == 1 ? 2 : 1;
    for (int u : adj[v]) {
        if (color[u] != 0) {
            if (color[u] != color_u) {
                return false;
            }
        } else {
            color[u] = color_u;
            if (!dfs(u)) {
                return false;
            }
        }
    }
    return true;
}

bool bfs() {
    bool valid = true;
    for (int i = 0; i < N; i++) {
        if (color[i] == 0) {
            color[i] = 1;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int v = q.front(); q.pop();
                int color_u = color[v] == 1 ? 2 : 1;
                for (int u : adj[v]) {
                    if (color[u] != 0) {
                        if (color[u] != color_u) {
                            valid = false;
                            goto end;
                        }
                    } else {
                        color[u] = color_u;
                        q.push(u);
                    }
                }
            }
        }
    }

end:;
    return valid;
}


int main() { 

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    adj = vector<vector<int>>(N, vector<int>(M));
    color = vector<int>(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool valid = true;
    for (int i = 0; i < N; i++) {
        if (color[i] == 0) {
            color[i] = 1;
            if (!dfs(i)) {
                valid = false;
                break;
            }
        }
    }

    if (valid) {
        for (int i = 0; i < color.size(); i++) {
            cout << color[i] << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE\n";
    }


    return 0;
}
