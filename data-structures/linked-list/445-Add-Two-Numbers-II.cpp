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
    
    void solve(ListNode *l, ListNode *tail, int carry) {
        while(l) {
            int x = l->val + carry;
            tail->next = new ListNode(x % 10);
            carry = x/10;
            
            tail = tail->next;
            l = l->next;
        }
        if(carry) tail->next = new ListNode(carry);
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse_linked_list(l1);
        l2 = reverse_linked_list(l2);
        
        int x = l1->val + l2->val;
        l1 = l1->next;
        l2 = l2->next;
        ListNode *ans = new ListNode(x % 10);
        int carry = x / 10;
        
        ListNode *tail = ans;
        // cout << tail->val << endl;
        while(l1 && l2) {
            x = l1->val + l2->val + carry;
            tail->next = new ListNode(x % 10);
            carry = x / 10;
            
            tail = tail->next;
            // cout << tail->val << endl;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if(l1) solve(l1, tail, carry);
        else solve(l2, tail, carry);
        
        ans = reverse_linked_list(ans);
        return ans;
    }
};
