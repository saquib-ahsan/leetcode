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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode *a = head, *b = head->next;
        head = b->next;
        b->next = nullptr;
        
        b->next = a;
        a->next = swapPairs(head);
        return b;
    }
};



// ITERATIVE IMPLEMENTATION
