// C++ STL
#define vt vector
#define pb push_back

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        map<vt<int>, int> kv;
        do {
            ++kv[nums];
        } while(next_permutation(nums.begin(), nums.end()));
        
        vt<vt<int>> ans;
        for(auto &p: kv) ans.pb(p.first);
        return ans;
    }
};



////////////////////////////////////////////////////////////////////////////////////////
// BACKTRACKING - I THINK, WE CAN MORE OPTIMIZED IN TERMS OF SPACE
#define vt vector
#define pb push_back
#define sz(x) (int)(x).size()

class Solution {
private:
    void solve(vt<int> &nums, int i, map<vt<int>, bool> &kv) {
        if(i == sz(nums)-1) {
            kv[nums] = true;
            return;
        }
        
        for(int j = i; j < sz(nums); ++j) {
            if((i != j) && (nums[i] == nums[j])) continue;
            
            swap(nums[i], nums[j]);
            solve(nums, i+1, kv);
            swap(nums[i], nums[j]);
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<vt<int>, bool> kv;
        solve(nums, 0, kv);
        
        vt<vt<int>> ans;
        for(auto &p: kv) ans.pb(p.first);
        return ans;
    }
};
