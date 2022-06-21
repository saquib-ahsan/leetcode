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
    int length_ll(ListNode *p) {
        int ans = 0;
        while(p) {
            ans++;
            p = p->next;
        }
        return ans;
    }
    
    ListNode *solve(ListNode *s, ListNode *l) { // s=>smaller length
        ListNode *ans = l;
        ListNode *last = nullptr;
        
        int rem = 0;
        while(s) {
            int total = s->val + l->val + rem;
            l->val = total % 10;
            rem = total / 10;
            
            s = s->next;
            last = l;
            l = l->next;
        }
        
        while(l) {
            int total = l->val + rem;
            l->val = total % 10;
            rem = total / 10;
            
            last = l;
            l = l->next;
        }
        if(rem > 0) {
            last->next = new ListNode(rem);
        }
        return ans;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int x = length_ll(l1), y = length_ll(l2);
        if(x < y) return solve(l1, l2);
        return solve(l2, l1);
    }
};



////////////////////////////////////////////////////////////////////////////////////////////////////
// WITHOUT SPACE OPTIMIZATION
class Solution {
private:
    ListNode *reverse_linked_list(ListNode *head) {
        ListNode *p = head, *q, *r;
        q = r = nullptr;
        while(p) {
            r = q;
            q = p;
            p = p->next;
            
            q->next = r;
        }
        return q;
    }
    
    void left_part(ListNode *l, ListNode *last, int carry) {
        while(l) {
            int x = l->val + carry;
            last->next = new ListNode(x % 10);
            carry = x/10;
            
            last = last->next;
            l = l->next;
        }
        if(carry) last->next = new ListNode(carry);
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *ans = new ListNode((carry + l1->val + l2->val) % 10);
        carry = (carry + l1->val + l2->val) / 10;
        
        ListNode *last = ans;
        l1 = l1->next;
        l2 = l2->next;
        
        while(l1 && l2) {
            int x = (carry + l1->val + l2->val);
            last->next = new ListNode(x%10);
            carry = x / 10;
            
            last = last->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if(!l1 && !l2 && carry) {
            last->next = new ListNode(carry);
        } else if(l1) {
            left_part(l1, last, carry);
        } else {
            left_part(l2, last, carry);
        }
        return ans;
    }
};
