#define vt vector
#define pb push_back
#define sz(x) (int)(x).size()

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int, int> kv;
        for(int i = sz(nums2)-1; ~i; --i) {
            while(sz(stk) && nums2[i] >= stk.top()) stk.pop();
            
            if(sz(stk)) kv[nums2[i]] = stk.top();
            else kv[nums2[i]] = -1;
            
            stk.push(nums2[i]);
        }
        
        vt<int> ans;
        for(int i = 0; i < sz(nums1); ++i) ans.pb(kv[nums1[i]]);
        return ans;
    }
};
