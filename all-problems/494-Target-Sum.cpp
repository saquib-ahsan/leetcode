#define vt vector
#define sz(x) (int)(x).size()

static int target_sum;

// BRUTE FORCE SOLUTION
class Solution {
private:
    int solve(vt<int> &nums, int i, int curr_sum) {
        if (i >= sz(nums)) {
            if (curr_sum == target_sum) return 1;
            return 0;
        }

        int pos_sign = solve(nums, i + 1, curr_sum + nums[i]);
        int neg_sign = solve(nums, i + 1, curr_sum - nums[i]);
        return pos_sign + neg_sign;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        target_sum = target;
        return solve(nums, 0, 0);
    }
};