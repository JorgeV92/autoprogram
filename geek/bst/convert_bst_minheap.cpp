#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <string_view>
#include <map>
#include <set>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define OUT(x) cout << x << '\n'
#define all(x) (x).begin(), (x).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++) 
#define FORE(i,a,b) for(int i = (a); i <= (b); i++)
#define ROF(i,a,b) for(int i = (a); i >= (b); i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return false;}
template<class T> inline bool chmin(T& a, T b) { if ( a > b) { a = b; return 1;} return false;}

using ll = long long;
using pii = pair<int,int>;


struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val{x}, left{nullptr}, right{nullptr} {}
};

void inorder_traversal(Node* root, vector<int>& order) {
    if (!root) return;
    inorder_traversal(root->left, order);
    order.push_back(root->val);
    inorder_traversal(root->right, order);
}

void preorder(Node* root, vector<int>& order, int& idx) {
    if (!root) return;
    root->val = order[idx++];
    preorder(root->left, order, idx);
    preorder(root->right, order, idx);
}

void convert_bst_minheap(Node* root) {
    vector<int> inorder;
    inorder_traversal(root, inorder);
    int i = 0;
    preorder(root, inorder, i);
}

void Pre(Node* root) {
    if (!root) return;
    cout << root->val << ' ';
    Pre(root->left);
    Pre(root->right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

     // Constructing the Binary Search Tree (BST)
    //          4
    //        /   \
    //       2     6
    //      / \   / \
    //     1   3 5   7
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    convert_bst_minheap(root);
    Pre(root) << endl;

    return 0;
}