#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct trie_node {
    trie_node* children[26];
    bool is_word;
    
    trie_node() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        is_word = false;
    }
};

class Trie {
public:
    Trie() { root = new trie_node(); }

    void insert(string word) {
        trie_node* node = root;
        for (char c : word) {
            if (!node->children[c -'a']) {
                node->children[c-'a'] = new trie_node();
            }
            node = node->children[c-'a'];
        } 
        node->is_word = true;
    }

    bool search(string word) {
        trie_node* node = root;
        for (char c : word) {
            if (!node->children[c-'a']) {
                return false;
            }
            node = node->children[c-'a'];
        }
        return node->is_word;
    }

    bool startsWith(string prefix) {
        trie_node* node = root;
        for (char c : prefix) {
            if (!node->children[c-'a']) {
                return false;
            }
            node = node->children[c-'a'];
        }
        return true;
    }
private:
    trie_node* root;
};

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool is_word;
};

class _Trie {
public:
    _Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->is_word = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node->is_word;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return true;
    }

private:
    TrieNode* root;
};

// class Trie {
// public:
//     Trie() {
        
//     }
    
//     void insert(string word) {
        
//     }
    
//     bool search(string word) {
        
//     }
    
//     bool startsWith(string prefix) {
        
//     }
// };


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}