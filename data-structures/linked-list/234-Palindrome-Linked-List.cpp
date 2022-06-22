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
    
public:
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        
        ListNode *fast = head, *mid = head, *mid_follower = nullptr;
        while(fast) {
            fast = fast->next;
            if(fast) {
                fast = fast->next;
                mid_follower = mid;
                mid = mid->next;
            }
        }
        
        mid_follower->next = nullptr;
        ListNode *first_to_half = head, *last_to_half = reverse_linked_list(mid);
        while(first_to_half) {
            if(first_to_half->val != last_to_half->val) return false;
            
            first_to_half = first_to_half->next;
            last_to_half = last_to_half->next;
        }
        return true;
    }
};
