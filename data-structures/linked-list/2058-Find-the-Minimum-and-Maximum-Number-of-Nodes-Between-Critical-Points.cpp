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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next) return {-1, -1};
        
        vector<int> positions;
        ListNode *p = head, *c = head->next, *n = head->next->next;
        int i = 2;
        while(n) {
            int x = p->val, y = c->val, z = n->val;
            // local maxima
            if(y>x && y>z) positions.push_back(i);
            // local minima
            if(y<x && y<z) positions.push_back(i);
            
            p = c;
            c = n;
            n = n->next;
            
            ++i;
        }
        
        int sz = (int)positions.size();
        if(sz < 2) return {-1, -1};
                
        int mx = positions.back()-positions.front(), mn = INT_MAX;
        for(int i = 1; i < sz; ++i) {
            int diff = positions[i] - positions[i-1];
            mn = min(mn, diff);
        }
        return vector<int>{mn, mx};
    }
};
