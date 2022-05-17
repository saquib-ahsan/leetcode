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
    ListNode* reverseList(ListNode* head) {
        ListNode *p = head, *q = nullptr, *r = nullptr;
        while(p) {
            r = q;
            q = p;
            p = p->next;
            
            q->next = r;
        }
        return q;
    }
};



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// RECURSIVE APPROACH
static ListNode *ans;

class Solution {
private:
    void solve(ListNode *head) {
        if(head->next == nullptr) {
            ans = head;
            return;
        }
        
        solve(head->next);
        
        ListNode *p = head->next;
        head->next = nullptr;
        p->next = head;
    }
    
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;
        
        solve(head);
        return ans;
    }
};
