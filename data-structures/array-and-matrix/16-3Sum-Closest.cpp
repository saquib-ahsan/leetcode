class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        
        int ans = 0, diff = INT_MAX;
        for(int i = 0; i < n-2; ++i) {
            if(i && (nums[i] == nums[i-1])) continue;
            
            int j = i+1, k = n-1;
            while(j < k) {
                if(j>i+1 && (nums[j] == nums[j-1])) {
                    ++j;
                    continue;
                }
                
                int tmp = nums[i] + nums[j] + nums[k];
                if(diff > abs(target - tmp)) {
                    ans = tmp;
                    diff = abs(target - tmp);
                } else if(target > tmp) {
                    ++j;
                } else {
                    --k;
                }
            }
        }
        
        return ans;
    }
};
