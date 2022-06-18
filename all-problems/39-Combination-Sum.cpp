#define vt vector
#define pb push_back
#define sz(x) (int)(x).size()

const int mxN = 500;
vt<vt<int>> ans;

class Solution {
private:
    void solve(const vt<int> &c, int start, int remain_sum, vt<int> &out, int j) {
        if(remain_sum <= 0 || start >= sz(c)) {
            if(!remain_sum) ans.pb(vt<int>(out.begin(), out.begin()+j));
            return;
        }
        
        for(int i = start; i < sz(c); ++i) {
            out[j] = c[i];
            solve(c, i, remain_sum - c[i], out, j+1);
        }
    }
    
    
public:
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        ans.clear();
        
        vt<int> out(mxN, 0);
        solve(c, 0, target, out, 0);
        return ans;
    }
};
