/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// SPACE OPTIMIZED SOLUTION
// SPACE COMPLEXITY = O(N)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        
        ListNode *slow = head, *fast = head;
        do {
            slow = slow->next;
            
            fast = fast->next;
            if(fast) fast = fast->next;
        } while(slow && fast && slow != fast);
        
        return (fast != nullptr);
    }
};



////////////////////////////////////////////////////////////////////////////////////////////////////
