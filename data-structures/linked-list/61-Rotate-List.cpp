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
    int len_ll(ListNode *head) {
        int cnt = 0;
        while(head) {
            ++cnt;
            head = head->next;
        }
        return cnt;
    }
    
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int len = len_ll(head);
        k %= len;
        if(!k) return head;
        
        int tmp = len - k - 1;
        ListNode *p, *q;
        p = q = head;
        while(q->next) {
            if(tmp) {
                p = p->next;
                --tmp;
            }
            q = q->next;
        }
        
        ListNode *ans = p->next;
        p->next = nullptr;
        q->next = head;
        return ans;
    }
};
