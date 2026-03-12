#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>


using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};


int pathSum(TreeNode* root, int target) {
    if (!root) return 0;

    // Do a prefix sum solution 
    // key - is the current prefix sum and the 
    // number of times we achieve this sum as the value 

    /*
        A way to calculate prefix sums is the following 
        
        vector<int> A(n);
            
        vector<int> prefix(n+1, 0);
        for (int i = 1; i <=  n; i++) {
            prefix[i] = preifx[i-1] + A[i-1];
        }
        
    */  
    unordered_map<int, int> prefixToCount;  
    prefixToCount[0] = 1;
    int total = 0;
    
    function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int curr_sum) {
        if (!node) return;
        
        curr_sum += node->val;
        int diff = target - curr_sum;
        if (prefixToCount.find(diff) != prefixToCount.end()) {
            ans += prefixToCount[diff];    
        } 

        prefixToCount[curr_sum]++;
        dfs(node->left, curr_sum);
        dfs(node->right, curr_sum);
        prefixToCount[curr_sum]--;
    }

    dfs(root, 0);
    return ans;
}
