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
private:
    ListNode *reverse_linked_list(ListNode *head) {
        ListNode *p = head, *q, *r;
        q = r = nullptr;
        while(p) {
            r = q;
            q = p;
            p = p->next;
            
            q->next = r;
        }
        return q;
    }
    
public:
    int pairSum(ListNode* head) {
        // find out middle of the list
        ListNode *fast = head, *mid = head, *mid_prev = nullptr;
        while(fast) {
            fast = fast->next;
            if(fast) {
                fast = fast->next;
                mid_prev = mid;
                mid = mid->next;
            }
        }
        if(!mid_prev) return (head->val + head->next->val);
        
        mid_prev->next = nullptr;
        ListNode *twin = reverse_linked_list(mid);
        int ans = 0;
        while(head) {
            int tmp = head->val + twin->val;
            ans = max(ans, tmp);
            
            head = head->next;
            twin = twin->next;
        }
        return ans;
    }
};
