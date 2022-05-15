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

#define sz(x) (int)(x).size()

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode *> p, q;
        p.push(root);
        
        int ans, sum = 0;
        while(sz(p) || sz(q)) {
            TreeNode *tmp = p.front();
            p.pop();
            sum += tmp->val;
            
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
            
            if(p.empty()) {
                ans = sum;
                sum = 0;
                while(sz(q)) {
                    p.push(q.front());
                    q.pop();
                }
            }
        }
        
        return ans;
    }
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ANOTHER APPROACH - RECURSIVE IMPLEMENTATION
class Solution {
private:
    // function to calculate the tree height
    int th(TreeNode *r) {
        if(r == nullptr) return 0;
        
        return 1 + max(th(r->left), th(r->right));
    }
    
    int solve(TreeNode *r, int curr_height) {
        if(r == nullptr) return 0;
        if(curr_height == 1) return r->val;
        
        int x = solve(r->left, curr_height-1);
        int y = solve(r->right, curr_height-1);
        return x + y;
    }

public:
    int deepestLeavesSum(TreeNode* root) {
        int tree_height = th(root);
        int ans = solve(root, tree_height);
        
        return ans;
    }
};
