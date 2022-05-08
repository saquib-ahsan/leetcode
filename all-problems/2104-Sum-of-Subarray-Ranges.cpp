typedef long long ll;
#define sz(x) (int)(x).size()

// TIME COMPLEXITY = O(N^2)
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        ll ans = 0;
        for(int i = 0; i < sz(nums); ++i) {
            int mx = INT_MIN, mn = INT_MAX;
            for(int j = i; j < sz(nums); ++j) {
                mx = max(mx, nums[j]);
                mn = min(mn, nums[j]);
                
                ans += ll(mx) - ll(mn);
            }
        }
        
        return ans;
    }
};
