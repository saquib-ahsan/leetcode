#define vt vector
#define sz(x) (int)(x).size()

class Solution {
public:
	int maxSumDivThree(vector<int>& nums) {
		vt<int> dp(3, 0);
		for(int i = 0; i < sz(nums); ++i) {
			vt<int> temp(dp);
			for(auto &x: dp) {
				int curr = x + nums[i];
				temp[curr%3] = max(temp[curr%3], curr);
			}
            
			dp = temp;
		}
        
		return dp[0];
	}
};
