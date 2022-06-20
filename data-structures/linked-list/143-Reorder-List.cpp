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

/*
APPROACH:
    - HALF THE LINKED LIST
    - REVERSE THE HALF LINKED LIST
    - GENERATE THE LINKED LIST BY TAKING ALTERNATIVE NODES FROM FIRST AND SECOND HALF.
*/

class Solution {
private:
    ListNode *reverse_linked_list(ListNode *head) {
        ListNode *p = head, *q, *r;
        r = q = nullptr;
        
        while(p) {
            r = q;
            q = p;
            p = p->next;
            
            q->next = r;
        }
        return q;
    }
    
public:
    void reorderList(ListNode* head) {
        ListNode *mid, *fast, *mid_prev = nullptr;
        mid = fast = head;
        while(fast) {
            fast = fast->next;
            if(fast) {
                fast = fast->next;
                mid_prev = mid;
                mid = mid->next;
            }
        }
        if(!mid_prev) return;
        
        mid_prev->next = nullptr;
        ListNode *first_half = head, *second_half = reverse_linked_list(mid);
        ListNode *ans, *last;
        ans = last = first_half;
        first_half = first_half->next;
        last->next = nullptr;
        
        int flip = 0;
        while(first_half && second_half) {
            if(flip) {
                last->next = first_half;
                first_half = first_half->next;
                last = last->next;
                last->next = nullptr;
            } else {
                last->next = second_half;
                second_half = second_half->next;
                last = last->next;
                last->next = nullptr;
            }
            
            flip ^= 1;
        }
        
        if(first_half) last->next = first_half;
        else last->next = second_half;
        head = ans;
    }
};
