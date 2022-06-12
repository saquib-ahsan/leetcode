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
        
        // make all rows equal in size
        for(auto &v: nums) {
            while(sz(v) < mxsz) v.pb(0);
        }
        
        vt<int> ans;
        // traverse upper half triagle
        for(int r = 0; r < sz(nums); ++r) {
            int i = r, c = 0;
            while(~i && c < mxsz) {
                if(nums[i][c]) ans.pb(nums[i][c]);
                
                --i; ++c;
            }
        }
        
        // traverse lower half triangle
        for(int c = 1; c < mxsz; ++c) {
            int r = sz(nums)-1, j = c;
            while(~r && j<mxsz) {
                if(nums[r][j]) ans.pb(nums[r][j]);
                
                --r; ++j;
            }
        }
        
        return ans;
    }
};
