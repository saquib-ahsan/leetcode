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
// ITERATIVE IMPLEMENTATION
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while(head) {
            ans = (ans * 2) + head->val; // ans = (ans << 1) + head->val :: bit manupulation
            head = head->next;
        }
        
        return ans;
    }
};



/////////////////////////////////////////////////////////////
// RECURSIVE IMPLEMENTATION
int ans, p;

class Solution {
private:
    void solve(ListNode *head) {
        if(head == nullptr) return;
        
        solve(head->next);
        ans += (head->val) * pow(2, p);
        ++p;
    }
    
public:
    int getDecimalValue(ListNode* head) {
        ans = p = 0;
        solve(head);
        return ans;
    }
};
