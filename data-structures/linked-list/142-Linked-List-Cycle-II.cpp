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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;
        
        // check if the cycle exists
        ListNode *slow = head, *fast = head;
        do {
            slow = slow->next;
            fast = fast->next;
            
            if(fast) fast = fast->next;
        } while(slow && fast && slow != fast);
        
        if(!fast) return nullptr;
        
        ListNode *ans = head;
        while(ans != slow) {
            ans = ans->next;
            slow = slow->next;
        }
        return ans;
    }
};

// P.S: I have used Physics derivation to solve this question, LOL!
