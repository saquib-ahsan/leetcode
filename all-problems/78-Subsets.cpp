#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back

// BIT MANUPULATION
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int N = sz(nums);
        
        vt<vt<int>> subsets;
        for(int i = 0; i < pow(2, N); ++i) {
            bitset<10> bs(i);
            vt<int> subset;
            for(int j = 0; j < N; ++j) {
                if(bs[j]) subset.pb(nums[j]);
            }
            
            subsets.pb(subset);
        }
        
        return subsets;
    }
};



// BACKTRACKING
class Solution {
private:
    void solve(vt<int> &nums, int i, vt<int> &output, int j, vt<vt<int>> &ans) {
        if(i >= sz(nums)) {
            vt<int> subset(output.begin(), output.begin()+j);
            ans.pb(subset);
            return;
        }
        
        // include ith character
        output[j] = nums[i];
        solve(nums, i+1, output, j+1, ans);
        
        // exclude ith character
        solve(nums, i+1, output, j, ans);
    }
    
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vt<vt<int>> ans;
        vt<int> output(sz(nums), -1);
        solve(nums, 0, output, 0, ans);
        return ans;
    }
};
