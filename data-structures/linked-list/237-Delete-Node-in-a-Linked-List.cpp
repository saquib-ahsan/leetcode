/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *tmp = node->next;
        while(tmp->next) {
            node->val = tmp->val;
            
            tmp = tmp->next;
            node = node->next;
        }
        
        node->val = tmp->val;
        node->next = nullptr;
        delete tmp;
    }
};
