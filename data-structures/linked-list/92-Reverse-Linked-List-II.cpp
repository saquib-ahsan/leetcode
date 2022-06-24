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

// OPTIMIZATION ==> IN SINGLE PASS (FOLLOW UP)




/////////////////////////////////////////////////////////////////////////////
class Solution {
private:
    ListNode *reverse_linked_list(ListNode *p) {
        ListNode *q, *r;
        q = r = nullptr;
        while(p) {
            r = q;
            q = p;
            p = p->next;
            
            q->next = r;
        }
        return q;
    }
    
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *a, *b, *pre_a, *post_b;
        a = b = head;
        pre_a = post_b = nullptr;
        
        while(--right) {
            b = b->next;
            
            if(--left > 0) {
                pre_a = a;
                a = a->next;
            }
        }
        
        // separation of segment
        post_b = b->next;
        b->next = nullptr;
        if(pre_a) pre_a->next = nullptr;
        
        // insertion of segment (after reversion)
        b = a;
        a = reverse_linked_list(a);
        b->next = post_b;
        if(pre_a) pre_a->next = a;
        else head = a;
        
        return head;
    }
};
