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
class Solution {
private:
    ListNode *find_mid(ListNode *head) {
        ListNode *fast, *mid, *mid_follower = nullptr;
        mid = fast = head;
        while(fast) {
            fast = fast->next;
            if(fast) {
                fast = fast->next;
                mid_follower = mid;
                mid = mid->next;
            }
        }
        
        mid_follower->next = nullptr;
        return mid;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        if(head && !head->next) return (new TreeNode(head->val));
        
        ListNode *mid = find_mid(head);
        TreeNode *root = new TreeNode(mid->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        
        return root;
    }
};
