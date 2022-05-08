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

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back

class Solution {
private:
    ListNode *reverse_ll(ListNode *head) {
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
        head = reverse_ll(head);
        
        vt<int> ans;
        stack<int> stk;
        while(head) {
            while(sz(stk) && head->val >= stk.top()) stk.pop();
            
            if(sz(stk)) ans.pb(stk.top());
            else ans.pb(0);
            
            stk.push(head->val);
            head = head->next;
        }
        
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
