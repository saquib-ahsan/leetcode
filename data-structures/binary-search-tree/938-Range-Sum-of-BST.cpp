/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

int ans, lo, hi;

class Solution {
private:
    void solve(TreeNode *root) {
        if(!root) return;
        
        int x = root->val;
        if(x>=lo && x<=hi) ans += x;
        
        solve(root->left);
        solve(root->right);
    }
    
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        ans = 0, lo = low, hi = high;
        
        solve(root);
        return ans;
    }
};
