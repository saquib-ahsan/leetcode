class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = (int)nums.size();
        if(n < 3) return {};
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n-2; ++i) {
            // check for duplicates (ith elements)
            if(i && (nums[i] == nums[i-1])) continue;
            
            int j = i+1, k = n-1;
            while(j < k) {
                // check for duplicates (jth elements)
                if(j>i+1 && (nums[j] == nums[j-1])) {
                    ++j;
                    continue;
                }
                
                int tmp = nums[i] + nums[j] + nums[k];
                if(tmp == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                } else if(tmp > 0) {
                    --k;
                } else {
                    ++j;
                }
            }
        }
        
        return ans;
    }
};

/* 
P.S.: We don't need to check for duplicates of kth elements. Suppose we fixed the value for ith element and kth element(fixed ==> duplicate), 
and we are avoiding jth duplicate elements. So there won't be any other value(s) of jth elments for which it will satisfy the condition
nums[i] + nums[j] + nums[k] = 0.
*/
