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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *odd = head, *even = head->next;
        head = even->next;
        odd->next = nullptr;
        even->next = nullptr;
        
        ListNode *odd_tail = odd, *even_tail = even;
        int i = 1;
        while(head) {
            if(i) {
                odd_tail->next = head;
                head = head->next;
                odd_tail = odd_tail->next;
                odd_tail->next = nullptr;
            } else {
                even_tail->next = head;
                head = head->next;
                even_tail = even_tail->next;
                even_tail->next = nullptr;
            }
            
            i ^= 1;
        }
        
        odd_tail->next = even;
        return odd;
    }
};
