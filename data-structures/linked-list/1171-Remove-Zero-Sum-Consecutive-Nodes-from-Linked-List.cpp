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
 
 // SIMPLE SUBARRAY PROBLEM
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *p = head, *p_follower = nullptr;
        while(p) {
            ListNode *q = p;
            bool found_zero_sum = false;
            
            int sum = 0;
            while(q) {
                sum += q->val;
                
                if(sum == 0) {
                    if(p_follower == nullptr) {
                        p = q->next;
                        q->next = nullptr;
                        head = p;
                    } else {
                        p_follower->next = q->next;
                        q->next = nullptr;
                        p = p_follower;
                    }
                    
                    found_zero_sum = true;
                    break;
                }
                
                q = q->next;
            }
            
            if(!found_zero_sum) {
                p_follower = p;
                p = p->next;
            }
        }
        
        return head;
    }
};
