// C++ STL
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        do {
            ans.push_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));
        
        return ans;
    }
};


// BACKTRACKING
#define vt vector
#define pb push_back
#define sz(x) (int)(x).size()

class Solution {
    void solve(vt<int> &nums, int i, vt<vt<int>> &ans) {
        if(i == sz(nums)-1) {
            ans.pb(nums);
            return;
        }
        
        for(int j = i; j < sz(nums); ++j) {
            swap(nums[i], nums[j]);
            
            solve(nums, i+1, ans);
            
            swap(nums[i], nums[j]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vt<vt<int>> ans;
        solve(nums, 0, ans);
        return ans;
    }
};
