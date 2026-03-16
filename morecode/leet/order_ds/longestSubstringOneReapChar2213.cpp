#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct node {
    int l, r;
    int lmx, rmx, mx;
    node(int l, int r) : l(l), r(r), lmx(1), rmx(1), mx(1) {} 
};

class SegmentTree {
public:
    SegmentTree(const string& s) : s(s) {
        int n = s.size();
        tree.resize(n*4);
        build(1, 1, n);
    }

    void modify(int u, int x, char v) {
        if (tree[u]->l == x && tree[u]->r == x) {
            s[x-1] = v;
            return;
        }
        int mid = (tree[u]->l + tree[u]->r) >> 1;
        if (x <= mid) {
            modify(u<<1, x , v);
        } else {
            modify(u<<1|1, x, v);
        }
        pushup(u);
    }

    int query(int u, int l, int r) {
        if (tree[u]->l >= l && tree[u]->r <= r) {
            return tree[u]->mx;
        }
        int mid = (tree[u]->l + tree[u]->r) >> 1;
        int ans = 0;
        if (r <= mid) {
            ans = query(u<<1, l ,r);
        } else if (l > mid) {
            ans = max(ans, query(u<<1|1, l, r));
        }
        return ans;
    }

private:
    void build(int u, int l, int r) {
        tree[u] = new node(l, r);
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid+1, r);
        pushup(u);
    }

    void pushup(int u) {
        node* root = tree[u];
        node* left = tree[u<<1];
        node* right = tree[u<<1|1];
        root->mx = max(left->mx, right->mx);
        root->lmx = left->lmx;
        root->rmx = right->rmx;
        int a = left->r - left->l + 1;
        int b = right->r - right->l + 1;
        if (s[left->r -1 ] == s[right->l -1]) {
            if (left->lmx == a) {
                root->lmx += right->lmx;
            } 
            if (right->rmx == b) {
                root->rmx += left->rmx;
            }
            root->mx = max(root->mx, left->rmx + right->lmx);
        }
    }
    string s;
    vector<node*> tree;
};   

class Solution {
public: 
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegmentTree tree(s);
        int k = queryIndices.size();
        vector<int> ans(k);
        int n = s.size();
        for (int i = 0; i < k; i++) {
            int x = queryIndices[i] + 1;
            char v = queryCharacters[i];
            tree.modify(1, x, v);
            ans[i] = tree.query(1, 1, n);
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    Solution sol;
    
    string s = "babacc";
    string chars = "bcb";
    vector<int> ind{1, 3, 3} ;
    auto ans = sol.longestRepeating(s, chars, ind);
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << '\n';
    return 0;   
}