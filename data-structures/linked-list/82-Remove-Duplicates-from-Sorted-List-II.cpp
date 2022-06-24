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
        bool contains_duplicate = false;
        ListNode *prev_p = nullptr, *prev_q = head;
        while(q) {
            if(q->val == p->val) {
                contains_duplicate = true;
            } else {
                if(contains_duplicate) {
                    if(head == p) {
                        head = p = q;
                        prev_q->next = nullptr;
                    } else {
                        prev_p->next = q;
                        prev_q->next = nullptr;
                        p = q;
                    }
                    
                    contains_duplicate = false;
                } else {
                    prev_p = p;
                    p = p->next;
                }
            }
            
            prev_q = q;
            q = q->next;
        }
        
        if(contains_duplicate) {
            if(head == p) return nullptr;
            prev_p->next = nullptr;
        }
        return head;
    }
};
