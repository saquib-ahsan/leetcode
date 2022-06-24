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
// MERGE SORT, TC = O(NlogN)
class Solution {
public:
    ListNode *merge_two_ll(ListNode *l1, ListNode *l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode *ans, *last;
        if(l1->val < l2->val) {
            ans = last = l1;
            l1 = l1->next;
        } else {
            ans = last = l2;
            l2 = l2->next;
        }
        last->next = nullptr;
        
        while(l1 && l2) {
            if(l1->val < l2->val) {
                last->next = l1;
                l1 = l1->next;
            } else {
                last->next = l2;
                l2 = l2->next;
            }
            
            last = last->next;
            last->next = nullptr;
        }
        if(l1) last->next = l1;
        if(l2) last->next = l2;
        
        return ans;
    }
    
    ListNode *get_mid(ListNode *head) {
        ListNode *fast = head, *mid = head, *mid_follower = nullptr;
        while(fast) {
            fast = fast->next;
            if(fast) {
                fast = fast->next;
                mid_follower = mid;
                mid = mid->next;
            }
        }
        
        mid_follower->next = nullptr;
        return mid;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *mid = get_mid(head);
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        
        return merge_two_ll(left, right);
    }
};
