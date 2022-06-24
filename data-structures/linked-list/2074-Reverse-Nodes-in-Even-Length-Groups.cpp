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
    
    ListNode *reverse_linked_list(ListNode *p) {
        ListNode *q, *r;
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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode *ans, *tail;
        ans = tail = new ListNode;  // dummy head
        
        int gpsz = 1;
        while(head) {
            int x = gpsz-1;
            ListNode *p, *q;
            p = q = head;
            while(x>0 && q) {
                q = q->next;
                --x;
            }
            if(q) {
                head = q->next;
                q->next = nullptr;
            } else head = nullptr;
                        
            int len = ll_len(p);
            if(!(len&1)) {
                q = p;
                p = reverse_linked_list(p);
            }
                        
            tail->next = p;
            tail = q;

            ++gpsz;
        }

        return ans->next;
    }
};
