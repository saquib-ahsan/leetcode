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
BACKTRACKING
