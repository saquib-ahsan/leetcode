class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = (int)nums.size();
        stack<int> stk;
        vector<int> ans;
        
        for(int i = 2*n-1; ~i; --i) {
            while(!stk.empty() && nums[i%n] >= stk.top()) stk.pop();
            
            if(i < n) {
                if(!stk.empty()) ans.push_back(stk.top());
                else ans.push_back(-1);
            }
            
            stk.push(nums[i%n]);
        }
        
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
