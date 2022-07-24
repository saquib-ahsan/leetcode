// Total number of subarrays = N * (N + 1) / 2;
// N = Number of elements present in the array

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = (int)nums.size();
        long long ans = 0, cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(nums[i] == 0) {
                ++cnt;
            } else {
                ans += cnt * (cnt + 1) / 2;
                cnt = 0;
            }
        }
        
        ans += cnt * (cnt + 1) / 2;
        return ans;
    }
};
