class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = (int)nums.size();
        
        int i = 0, cnt = 0, curr = -1;
        int tmp = 0;    // number of duplicate elmeents
        while(i < n) {
            if(cnt == 0) {
                curr = nums[i];
                ++cnt;
                ++i;
                continue;
            }
            
            if(nums[i] == curr) {
                if(cnt == 2) {
                    nums[i] = INT_MAX;
                    ++tmp;
                } else {
                    ++cnt;
                }
                
                ++i;
            } else {
                cnt = 0;
                curr = -1;
            }
        }
        
        // sorting
        i = 0;
        int j = 0;
        while(i < n) {
            while(i<n && nums[i]!=INT_MAX) ++i;
            j = i;
            while(j<n && nums[j]==INT_MAX) ++j;
            
            if(j < n) swap(nums[i], nums[j]);
            ++i;
        }
        
        return n - tmp;
    }
};
