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
        
        b->next = a;
        a->next = swapPairs(head);
        return b;
    }
};



// ITERATIVE IMPLEMENTATION
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *a = head, *b = head->next;
        head = head->next->next;
        b->next = a;
        a->next = nullptr;
        
        ListNode *ans = b, *last = a;
        while(head && head->next) {
            a = head;
            b = head->next;
            head = head->next->next;
            
            b->next = a;
            a->next = nullptr;
            
            last->next = b;
            last = a;
        }
        
        if(head) last->next = head;
        return ans;
    }
};
