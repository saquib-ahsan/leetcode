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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // if there are no common elements means no intersection
        // check memory address for common elments
        ListNode *p = headA;
        while(p->next) p = p->next;
        ListNode *q = headB;
        while(q->next) q = q->next;
        if(p != q) return nullptr;
        
        p = headA, q = headB;
        while(p != q) {
            p = p->next;
            q = q->next;
            
            if(!p) p = headA;
            if(!q) q = headB;
        }
        return p;   
    }
};

// P.S.: more optimization needed
