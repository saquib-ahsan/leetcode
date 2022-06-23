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
    int numComponents(ListNode* head, vector<int>& nums) {
        set<int> keys;
        for(int i = 0; i < (int)nums.size(); ++i) keys.insert(nums[i]);
        
        int ans = 0;
        bool new_component = true;
        while(head) {
            if(keys.find(head->val) != keys.end()) {
                if(new_component) {
                    ++ans;
                }
                
                new_component = false;
            } else {
                new_component = true;
            }
            
            head = head->next;
        }
        
        return ans;
    }
};
