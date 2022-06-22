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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *head_kth_node = head;
        while(--k) head_kth_node = head_kth_node->next;
        
        ListNode *tail_kth_node = head, *tmp = head_kth_node;
        while(tmp->next) {
            tmp = tmp->next;
            tail_kth_node = tail_kth_node->next;
        }
        
        std::swap(head_kth_node->val, tail_kth_node->val);
        return head;
    }
};
