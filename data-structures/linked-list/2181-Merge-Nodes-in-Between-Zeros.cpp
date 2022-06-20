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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *ans, *last;
        ans = last = nullptr;
        
        int sum = 0;
        while(head) {
            head = head->next;
            if(head == nullptr) break;
            
            sum += head->val;
            if(head->val == 0) {
                if(!ans) {
                    ans = last = new ListNode(sum);
                } else {
                    last->next = new ListNode(sum);
                    last = last->next;
                }
                
                sum = 0;
            }
        }
        
        return ans;
    }
};
