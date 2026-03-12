#include <iostream>
#include <vector>

using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;

    BstNode(int d) : data(d), left(nullptr), right(nullptr) {}
};

BstNode* getNode(int data) {
    BstNode* node = new BstNode(data);
    return node;
}


BstNode* levelOrder(BstNode* root, int data) {
    if (!root) {
        root = getNode(data);
        return root;
    }

    if (data <= root->data) {
        root->left = levelOrder(root->left, data);
    } else {
        root->right = levelOrder(root->right, data);
    }
    return root;
}

BstNode* gen(vector<int>& arr, int n) {
    if (n == 0) {
        return nullptr;
    }

    BstNode* root = nullptr;
    for (int i = 0; i < n; i++) {
        root = levelOrder(root, arr[i]);
    }
    return root;
}

BstNode* lca(BstNode* root, int v1, int v2) {
    if (!root) return nullptr;

    if (root->data == v1 || root->data == v2) {
        return root;
    }

    BstNode* left_lca = lca(root->left, v1, v2);
    BstNode* right_lca = lca(root->right, v1, v2);

    if (left_lca && right_lca) {
        return root;
    }

    return left_lca ? left_lca : right_lca;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    BstNode* root = gen(arr, n);

    int v1, v2;
    cin >> v1 >> v2;

    cout << lca(root, v1, v2)->data << endl;

    return 0;
}