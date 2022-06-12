#define sz(x) (int)(x).size()

// SLIDING WINDOW
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> uvals;   // unique values
        int ans = 0, curr_sum = 0;
        
        int i = 0, j = 0;
        while(j < sz(nums)) {
            // check the element if it is already encountered
            while(uvals.count(nums[j]) > 0) {
                uvals.erase(nums[i]);  // removing the ith element until we remove repeated element
                
                curr_sum -= nums[i];
                ++i;
            }
            
            // add current element
            curr_sum += nums[j];
            uvals.insert(nums[j]);
            
            ans = max(ans, curr_sum);
            ++j;
        }
        
        return ans;
    }
};
