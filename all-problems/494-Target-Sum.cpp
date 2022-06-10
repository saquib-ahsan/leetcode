#define vt vector
#define sz(x) (int)(x).size()

// BRUTE FORCE SOLUTION (BACKTRACKING)
class Solution {
private:
    int solve(const vt<int> &nums, int i, int curr_sum, const int &target) {
        if (i >= sz(nums)) {
            if (curr_sum == target) return 1;
            return 0;
        }

        int pos_sign = solve(nums, i + 1, curr_sum + nums[i], target);
        int neg_sign = solve(nums, i + 1, curr_sum - nums[i], target);
        
        return pos_sign + neg_sign;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, 0, 0, target);
    }
};



///////////////////////////////////////////////////////////////////////////////////
// DYNAMIC PROGRAMMING
