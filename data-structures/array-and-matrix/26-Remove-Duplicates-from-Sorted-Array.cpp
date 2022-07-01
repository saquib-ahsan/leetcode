// TIME COMPLEXITY = O(N)
// SPACE COMPLEXTIY = O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = (int)nums.size();
        if(n < 2) return 1;
        
        int i = 0, j = 1;
        while(j < n) {
            if(nums[j] == nums[i]) {
                nums[j] = INT_MIN;
                ++j;
            } else {
                i = j;
                ++j;
            }
        }
        
        i = 0;
        while(i < n) {
            while(i<n && nums[i] != INT_MIN) ++i;
            
            j = i;
            while(j<n && nums[j] == INT_MIN) ++j;
            
            if(j < n) swap(nums[i], nums[j]);
            else break;
        }
        return i;
    }
};



////////////////////////////////////////////////////////////////////////////
// SPACE COMPLEXITY = O(1)
// TIME COMPLEXITY = O(NLOGN)

#define sz(x) (int)(x).size()
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0;    // count number of duplicates elements
        for(int i = 1; i < sz(nums); ++i) {
            if(nums[i] == nums[i-1]) {
                nums[i-1] = INT_MAX;
                ++cnt;
            }
        }
        
        sort(nums.begin(), nums.end());
        return sz(nums) - cnt;
    }
};
