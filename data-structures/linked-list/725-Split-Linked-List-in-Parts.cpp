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
    int ll_len(ListNode *head) {
        int cnt = 0;
        while(head) {
            ++cnt;
            head = head->next;
        }
        return cnt;
    }
    
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = ll_len(head);
        int gpsz = len/k, extras = len%k;
        
        vector<ListNode *> ans;
        while(head) {
            ListNode *p, *q;
            int x = gpsz;
            if(x > 0) {
                p = q = head;
                --x;    // iterate till last node of the current group reached
                while(x > 0) {
                q = q->next;
                --x;
                }

                if(extras > 0) {
                    q = q->next;
                    --extras;
                }
            } else if(extras > 0) {
                p = q = head;
                --extras;
            }
            
            head = q->next;
            q->next = nullptr;
            ans.push_back(p);
        }
        
        while(ans.size() < k) ans.push_back(nullptr);
        return ans;
    }
};
