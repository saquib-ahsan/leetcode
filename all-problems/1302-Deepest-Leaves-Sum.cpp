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
