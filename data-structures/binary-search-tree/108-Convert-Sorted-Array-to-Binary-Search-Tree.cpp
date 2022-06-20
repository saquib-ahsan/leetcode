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
class Solution {
private:
    TreeNode *solve(vector<int> &nums, int lo, int hi) {
        if(lo > hi) return nullptr;
        if(lo == hi) return (new TreeNode(nums[lo]));
        
        int mid = (lo + hi) / 2;
        TreeNode *temp = new TreeNode(nums[mid]);
        temp->left = solve(nums, lo, mid-1);
        temp->right = solve(nums, mid+1, hi);
        
        return temp;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = solve(nums, 0, (int)nums.size()-1);
        return root;
    }
};