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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        
        ListNode *p = head, *p_follower = nullptr;
        while(p) {
            if(p->val != val) {
                p_follower = p;
                p = p->next;
            } else {
                if(p == head) {
                    head = head->next;
                    p->next = nullptr;
                    p = head;
                } else {
                    p_follower->next = p->next;
                    p->next = nullptr;
                    p = p_follower->next;
                }
            }
        }
        
        return head;
    }
};
