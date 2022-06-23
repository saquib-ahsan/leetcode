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

// SPACE OPTIMIZED SOLUTION



/////////////////////////////////////////////////////////////////////////
TreeNode *ans, *tail;

class Solution {
private:
    void solve(TreeNode *root) {
        if(!root) return;
        
        if(!ans) {
            ans = tail = new TreeNode(root->val);
        } else {
            tail->right = new TreeNode(root->val);
            tail = tail->right;
        }
        
        solve(root->left);
        solve(root->right);
    }
    
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        
        ans = tail = nullptr;
        solve(root);
        // root address must not change
        root->left = nullptr;
        root->right = ans->right;
        
    }
};
