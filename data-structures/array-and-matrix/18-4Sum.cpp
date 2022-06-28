typedef long long ll;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if(n < 4) return {};
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        for(int i = 0; i < n-3; ++i) {
            // check duplcates for ith element
            if(i && (nums[i] == nums[i-1])) continue;
            
            for(int j = i+1; j < n-2; ++j) {
                // check duplicates for jth element
                if(j>i+1 && (nums[j] == nums[j-1])) continue;
                
                int p = j+1, q = n-1;
                while(p < q) {
                    // check duplicates for pth element
                    if(p>j+1 && (nums[p] == nums[p-1])) {
                        ++p;
                        continue;
                    }
                    
                    ll tmp = ll(nums[i]) + ll(nums[j]) + ll(nums[p]) + ll(nums[q]);     // integer overflow
                    if(tmp == ll(target)) {
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        ++p;
                        --q;
                    } else if(tmp < ll(target)) {
                        ++p;
                    } else {
                        --q;
                    }
                }
            }
        }
        
        return ans;
    }
};
