/////////////////////////////////////////////////////////////////////////////
// TIME LIMIT EXCEEDED (TLE)
#define vt vector
#define pb push_back
#define sz(x) (int)(x).size()

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int mxsz = 0;
        for(const auto &v: nums) mxsz = max(mxsz, sz(v));
        
        vt<int> ans;
        // traverse upper half triangle
        for(int r = 0; r < sz(nums); ++r) {
            int i = r, c = 0;
            while(~i) {
                if(sz(nums[i]) >= c+1) ans.pb(nums[i][c]);
                --i; ++c;
            }
        }
        
        // traverse lower half triangle
        for(int c = 1; c < mxsz; ++c) {
            int r = sz(nums)-1, j = c;
            while(~r) {
                if(sz(nums[r]) >= j+1) ans.pb(nums[r][j]);
                --r; ++j;
            }
        }
        
   
        return ans;
    }
};
