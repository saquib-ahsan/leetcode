// TWO POINTERS
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = (int)nums.size();
        
        int i = 0;
        for(int j = 0; j < n; ++j) {
            if(nums[j] != val) {
                nums[i] = nums[j];
                ++i;
            }
        }
        
        return i;
    }
};



///////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = (int)nums.size();
        
        int cnt = 0;    // count number of occurrences of val
        for(int i = 0; i < n; ++i) {
            if(nums[i] == val) {
                ++cnt;
                nums[i] = INT_MAX;
            }
        }
        
        sort(nums.begin(), nums.end());
        return n - cnt;
    }
};
