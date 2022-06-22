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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *p = head, *q = head->next;
        while(q) {
            if(q->val == p->val) {
                p->next = q->next;
                q = p->next;
            } else {
                q = q->next;
                p = p->next;
            }
        }
        
        return head;
    }
};
