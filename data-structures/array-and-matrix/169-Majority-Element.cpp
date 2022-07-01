// Boyer-Moore Voting Algorithm



///////////////////////////////////////////////////////////////////////////////////////
// TIME COMPLEXITY: O(NlogN)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = (int)nums.size();
        
        sort(nums.begin(), nums.end());
        
        int i = 1, cnt = 1, curr = nums[0];
        while(i <= n) {
            if(i<n && nums[i] == curr) {
                ++cnt;
            } else {
                if(cnt > n/2) {
                    return curr;
                }
                
                cnt = 1;
                curr = nums[i];
            }
            
            ++i;
        }
        
        return -1;
    }
};
