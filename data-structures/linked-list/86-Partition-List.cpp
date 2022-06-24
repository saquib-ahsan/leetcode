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
    ListNode* partition(ListNode* head, int x) {
        ListNode *partition_first, *tail_first;
        partition_first = tail_first = new ListNode;
        ListNode *partition_second, *tail_second;
        partition_second = tail_second = new ListNode;
        
        while(head) {
            if(head->val < x) {
                tail_first->next = head;
                tail_first = tail_first->next;
                head = head->next;
                tail_first->next = nullptr;
            } else {
                tail_second->next = head;
                tail_second = tail_second->next;
                head = head->next;
                tail_second->next = nullptr;
            }
        }
        
        tail_first->next = partition_second->next;
        return partition_first->next;
    }
};
