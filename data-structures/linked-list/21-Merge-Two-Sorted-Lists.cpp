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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        
        ListNode *ans = nullptr;
        if(list1->val < list2->val) {
            ans = new ListNode(list1->val);
            list1 = list1->next;
        } else {
            ans = new ListNode(list2->val);
            list2 = list2->next;
        }
        ans->next = nullptr;
        
        ListNode *last = ans;
        while(list1 && list2) {
            if(list1->val < list2->val) {
                last->next = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                last->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            
            last = last->next;
            last->next = nullptr;
        }
        
        if(list1) last->next = list1;
        else last->next = list2;
        return ans;
    }
};
