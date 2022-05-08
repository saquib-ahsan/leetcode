#define vt vector
#define eb emplace_back
#define sz(x) (int)(x).size()

class Solution {
private:
    vt<int> next_greater_elements(const vt<int> &nums) {
        vt<int> ans;
        stack<int> stk;
        for(int i = sz(nums)-1; ~i; --i) {
            while(sz(stk) && nums[i] >= stk.top()) stk.pop();
            
            if(sz(stk) == 0) ans.eb(-1);
            else ans.eb(stk.top());
            
            stk.push(nums[i]);
        }
        
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
    
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // next greater elements for nums2
        vt<int> nges = next_greater_elements(nums2);
        unordered_map<int, int> kv;
        for(int i = 0; i < sz(nums2); ++i) kv[nums2[i]] = nges[i];
        
        vt<int> ans;
        for(int i = 0; i < sz(nums1); ++i) ans.eb(kv[nums1[i]]);
        return ans;
    }
};
