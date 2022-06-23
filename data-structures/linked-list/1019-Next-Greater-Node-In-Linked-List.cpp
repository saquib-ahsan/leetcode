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
    vector<int> nextLargerNodes(ListNode* head) {
        head = reverse_linked_list(head);
        
        stack<int> stk;
        vector<int> ans;
        while(head) {
            int x = head->val;
            while(!stk.empty() && x >= stk.top()) stk.pop();
            
            if(!stk.empty()) ans.push_back(stk.top());
            else ans.push_back(0);
            
            stk.push(x);
            head = head->next;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
