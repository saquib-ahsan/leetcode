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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *p, *q, *p_follower = nullptr;
        p = q = list1;
        while(b--) {
            q = q->next;
            if(a-- > 0) {
                p_follower = p;
                p = p->next;
            }
        }
        
        ListNode *list2_tail = list2;
        while(list2_tail->next) list2_tail = list2_tail->next;
        
        p_follower->next = list2;
        list2_tail->next = q->next;
        q->next = nullptr;
        
        return list1;
    }
};
