#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back

static const int mxN = 501;
static vt<vt<int>> ans;

class Solution {
private:
    void solve(const vt<int> &c, int start, vt<int> &out, int j, int sum, int target) {
        if(sum == target) {
            ans.pb(vt<int>(out.begin(), out.begin()+j));
            return;
        }
        if(sum > target) return;
        
        for(int i = start; i < sz(c); ++i) {
            out[j] = c[i];
            solve(c, i, out, j+1, sum+c[i], target);
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        ans.clear();
        
        vt<int> out(mxN, 0);
        solve(c, 0, out, 0, 0, target);
        return ans;
    }
};
