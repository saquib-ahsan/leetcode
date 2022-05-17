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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode *ans = nullptr, *last = nullptr;
        while(head && head->next) {
            ListNode *a = head, *b = head->next;
            head = b->next;
            
            b->next = a;
            a->next = nullptr;
            
            if(ans) {
                last->next = b;
                last = a;
            } else {
                ans = b;
                last = a;
            }
        }
        
        last->next = head;
        return ans;
    }
};
