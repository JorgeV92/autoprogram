#include <iostream>
#include <vector>

using namespace std;

struct TrieNode {
    TrieNode* children[26];
    string* w;
    TrieNode() {
        w = nullptr;
        memset(children, 0, sizeof(children));
    }
};

class Trie {
public:
    Trie(vector<string>& words, vector<vector<char>>& board) {
        b = board;
        root = new TrieNode();

        for (auto& w : words) {
            insert(w);
        }
    }

    void insert(string& s) {
        TrieNode* node = root;
        for (char c : s) {
            if (!node->children[c-'a']) {
                node->children[c-'a'] = new TrieNode();
            }
            node = node->children[ch-'a'];
        }
        node->w = &s;
    }

    bool valid(int r, int c) {
        return (0 <= r && r < b.size() && 0 <= c && c < b[0].size());
    }

    void dfs(int r, int c,  TrieNode* node) {
        char ch = b[r][c];
        if (ch == '#' || !node->children[ch-'a']) return;
        node = node->children[c-'a'];
        
        if (node->w) {
            res.push_back(*node->w);
            node->w = nullptr;
        }
        b[r][c] = '#';
        for (int k = 0; k < 4; k++) {
            int nr = r + dx[k];
            int nc = c + dy[k];
            if (valid(nr, nc)) {
                dfs(nr, nc, node);
            }
        }

        b[r][c] = ch;
    } 

    void search(int r, int c) {
        dfs(r, c, root);
    }

    vector<string> get() {
        return res;
    }

private:
    TrieNode* root;
    vector<vector<char>> b;
    vector<string> res;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
};

vector<string> findWords(vector<string>& words, vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();
    Trie* trie = new Trie(words, board);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            trie->search(i, j);
        }
    }

    return trie->get();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}