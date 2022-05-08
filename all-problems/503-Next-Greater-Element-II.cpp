#define vt vector
#define sz(x) (int)(x).size()
#define eb emplace_back

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        vt<int> vi;
        for(int i = 2 * sz(nums)-1; ~i; --i) {
            int j = i % sz(nums);
            while(sz(stk) && nums[j]>=stk.top()) stk.pop();
            
            if(sz(stk)) vi.eb(stk.top());
            else vi.eb(-1);
            
            stk.push(nums[j]);
        }
        std::reverse(vi.begin(), vi.end());
        
        vt<int> ans(vi.begin(), vi.begin()+sz(nums));
        return ans;
    }
};
