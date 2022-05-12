/*
problem statement:
https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/
*/

/*
APPROACH:
    - We can easy to realise that is a DP problem
    - The naive dp has 3 variable parameters which is (l, r, cnt), time complexity = O(m^3), l and r can
      be picked up to m (size of the multipliers arr) numbers.
    - We can optimize to 2 parameters which is (l, cnt), time complexity = O(m^2), we can compute parameter
      r based on l and cnt
      
      
    - l, r is the index of the left side and the right side corresponding
    - cnt is the number of elements that we picked
    - left_picked: number of elements picked on the left side, left_picked = l
    - right_picked: nubmer of elements picked on the right side, right_picked = cnt - left_picked
                    ==> r = sz(xN) - (cnt - l) - 1
*/
                    
#define vt vector
#define sz(x) (int)(x).size()

class Solution {
private:
    int solve(vt<int> &nums, int l, vt<int> &xN, int cnt, vt<vt<int>> &dp) {
        if(cnt >= sz(xN)) return 0;
        if(dp[l][cnt] != -1) return dp[l][cnt];
        
        int pick_left = (nums[l] * xN[cnt]) + solve(nums, l+1, xN, cnt+1, dp);
        int pick_right = (nums[sz(nums)-(cnt-l)-1] * xN[cnt]) + solve(nums, l, xN, cnt+1, dp);
        
        return dp[l][cnt] = max(pick_left, pick_right);
    }
    
public:
    int maximumScore(vector<int>& nums, vector<int>& xN) {
        vt<vt<int>> dp(sz(xN), vt<int>(sz(xN), -1));
        return solve(nums, 0, xN, 0, dp);
    }
};
