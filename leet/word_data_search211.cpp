#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool is_word;
    TrieNode() {
        is_word = false;
        memset(children, 0, sizeof(children));
    }
};

class Trie {
public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c-'a']) {
                node->children[c-'a'] = new TrieNode();
            }
            node = node->children[c-'a'];
        }
        node->is_word = true;
    }

    bool match(const string& w, int idx, TrieNode* node) {
        if (idx == w.length()) {
            return node->is_word;
        }
        char c = w[idx];
        if (c == '.' ) {
            for (int i = 0; i < 26; i++) {
                if (node->children[i]) {
                    if (match(w, idx+1, node->children[i])) {
                        return true;
                    }
                } 
            }
            return false;
        } else {
            if (!node->children[c-'a']) {
                return false;
            }
            return match(w, idx+1, node->children[c-'a']);
        }
    }

    bool search(string word) {
        return match(word, 0, root);
    }



private:
    TrieNode* root;
};


int main() {

    return 0;
}