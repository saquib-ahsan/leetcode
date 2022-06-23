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

// merge sort, time complexity = O(NlogN)
// verdict = accepted




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// insertion sort, time complexity = O(N^2)
// TLE
class Solution {
private:
    ListNode *insert_in_linked_list(ListNode *head, ListNode *node) {
        if(!head) return (new ListNode(node->val));
        if(node->val <= head->val) {
            node->next = head;
            return node;
        }
        
        ListNode *pos = head, *pos_follower = nullptr;   //pos = first position where head->val >= node->val
        while(pos && (pos->val < node->val)) {
            pos_follower = pos;
            pos = pos->next;
        }
        pos_follower->next = node;
        node->next = pos;
        return head;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        ListNode *ans = nullptr;
        
        while(head) {
            ListNode *node = head;
            head = head->next;
            node->next = nullptr;
            
            ans = insert_in_linked_list(ans, node);
        }
        return ans;
    }
};
