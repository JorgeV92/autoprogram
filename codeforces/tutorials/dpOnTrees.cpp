#include <iostream>
#include <vector>

using namespace std;

/*
    The first problem we solve is as follows: Given a tree T of N nodes, 
    where each node i has Ci coins attached with it. You have to choose a 
    subset of nodes such that no two adjacent nodes(i.e. nodes connected 
    directly by an edge) are chosen and sum of coins attached with nodes 
    in chosen subset is maximum.
*/
const int N = 100;
vector<int> adj[N];

int dp1[N], dp2[N]; // dp1 take current node v but not its children
// dp2 dont take v but can take v's children so max(dp1(u), dp2(u))

vector<int> C(N);

void dfs(int v, int p) {
    int sum1 = 0;
    int sum2 = 0;

    for (auto u : adj[v]) {
        if (u == p) continue;
        dfs(u, v);
        sum1 += dp2[u];
        sum2 += max(dp1[u], dp2[u]);
    }

    dp1[v] = C[v] + sum1;
    dp2[v] = sum2;
}


/*
    Given a tree T of N nodes, calculate longest path between any two nodes(also known as diameter of tree).
*/
vector<int> adj2[N];

int f[N];  // the length of the longest path starting at node N and going down.
int g[N];   //  the length of the path passing through N connecting two deepest sub-branches.
int diameter; //maximum path found

void dfs_longest_path(int v, int p) {
    vector<int> fValues;

    for (auto u : adj2[v]) {
        if (u == p) continue;
        dfs(u, v);
        fValues.push_back(f[u]); // store the data from child
    }

    // we need the two longest branches coming from children now they 
    // are in the last two elements in fValues
    sort(fValues.begin(), fValues.end()); 

    f[v] = 1; // path start with v
    if (!fValues.empty()) {
        f[v] += fValues.back(); // single longest branch
    }    

    if (fValues.size() >= 2) { // has at least 2 children, we can form a V shape path
        // take the longest and second longest branch 
        // + 2 for the edges connecting v to child 1 and v to child 2.
        g[v] = 2 + fValues.back() + fValues[fValues.size() - 2]; 
    }
    diameter = max(diameter, max(f[v], g[v]));
}

// Given a tree T of N nodes and an integer K, find number of different sub trees of size less than or equal to K.
vector<int> adj3[N];
const int K = 50;

int dp[N][K]; // dp[u][k] - subtrees rooted at u with size k
int ans = 0;

void dfs(int u, int p) {
    dp[u][1] = 1; // Base case: the node itself forms a subtree of size 1

    for (int v : adj[u]) {
        if (v == p)  continue;
        dfs(v, u);

        vector<int> next_dp(K+1, 0);

        for (int i = 1; i <= K; i++) {
            // skip impossible sizes
            if (dp[u][i] == 0) continue;

            // dont attach child v to u
            next_dp[i] += dp[u][i];

            // attach child v to u
            for (int j = 1; j <= K; j++) {
                if (dp[v][j] == 0) continue;

                if (i + j > K) break;

                next_dp[i+j] += dp[u][i] * dp[v][j];
            }
        }

        for (int i = 1; i <= K; i++) {
            dp[u][i] = next_dp[i];
        }
    }
    for (int i = 1; i <= K; i++) {
        ans += dp[u][i];
    }

    // call with dfs(1, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto tree_subset_sum = [&]() {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, 0);
        int ans = max(dp1[1], dp2[1]);
        cout << ans << endl;
    };



    return 0;
}