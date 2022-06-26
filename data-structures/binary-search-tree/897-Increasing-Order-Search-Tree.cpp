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

// OPTIMIZED SOLUTION




/////////////////////////////////////////////////////////////////////////////////////////
vector<int> nodes;

class Solution {
private:
    void inorder(TreeNode *root) {
        if(!root) return;
        
        inorder(root->left);
        nodes.push_back(root->val);
        inorder(root->right);
    }
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        nodes.clear();
        inorder(root);
        TreeNode *ans = new TreeNode(nodes[0]);
        
        TreeNode *last = ans;
        int n = (int)nodes.size();
        for(int i = 1; i < n; ++i) {
            last->right = new TreeNode(nodes[i]);
            last = last->right;
        }
        
        return ans;
    }
};
