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

// follow up: processed in a single pass
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head;
        while(n--) p = p->next;
        
        ListNode *q = head; // node that needs to be deleted
        ListNode *q_follower = nullptr;
        while(p) {
            p = p->next;
            q_follower = q;
            q = q->next;
        }
        
        if(q == head) { // if head is to be deleted i.e., n = length of linked list
            head = head->next;
            q->next = nullptr;
        } else {
            q_follower->next = q->next;
            q->next = nullptr;
        }
        return head;
    }
};
