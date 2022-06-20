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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *fast = head, *mid = head, *mid_prev = nullptr;
        while(fast) {
            fast = fast->next;
            if(fast) {
                fast = fast->next;
                
                mid_prev = mid;
                mid = mid->next;
            }
        }
        if(!mid_prev) return nullptr;
        
        mid_prev->next = mid->next;
        mid->next = nullptr;
        delete mid;
        
        return head;
    }
};
