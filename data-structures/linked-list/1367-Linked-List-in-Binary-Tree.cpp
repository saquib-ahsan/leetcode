/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
class Solution {
private:
    bool find_linked_list(ListNode *head, TreeNode *root) {
        if(!head) return true;
        if(!root || (head->val != root->val)) return false;
        
        bool check_left_side = find_linked_list(head->next, root->left);
        bool check_right_side = find_linked_list(head->next, root->right);
        
        return (check_left_side || check_right_side);
    }
    
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return false;
        if(head->val == root->val) {
            bool found = find_linked_list(head, root);
            if(found) return true;
        }
        
        bool left_side = isSubPath(head, root->left);
        bool right_side = isSubPath(head, root->right);
        return (left_side || right_side);
    }
};



/////////////////////////////////////////////////////////////////////////////////////////////
vector<TreeNode *> head_nodes;

class Solution {
private:
    // find all the tree nodes where root->val == head->val
    // sp = starting point
    void find_all_sp(TreeNode *root, int x) {
        if(root == nullptr) return;
        
        if(root->val == x) head_nodes.push_back(root);
        
        find_all_sp(root->left, x);
        find_all_sp(root->right, x);
    }
    
    bool find_linked_list(TreeNode *root, ListNode *head) {
        if(!head) return true;
        if(!root || (root->val != head->val)) return false;
        
        bool check_left_side = find_linked_list(root->left, head->next);
        bool check_right_side = find_linked_list(root->right, head->next);
        
        return (check_left_side || check_right_side);
    }
    
    
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        head_nodes.clear();
        find_all_sp(root, head->val);
        
        int n = (int)head_nodes.size();
        for(int i = 0; i < n; ++i) {
            bool found = find_linked_list(head_nodes[i], head);
            if(found) return true;
        }
        return false;
    }
};
