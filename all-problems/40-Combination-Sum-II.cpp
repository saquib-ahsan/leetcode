// BACKTRACKING WITH COUNTERS
#define vt vector
#define pb push_back
#define sz(x) (int)(x).size()

unordered_map<int, int> kv;
vt<vt<int>> ans;

class Solution {
private:
    // rs = remaining sum
    void solve(vt<int> &uvals, int start, int rs, vt<int> &out, int j) {
        if(rs <= 0) {
            if(rs == 0) ans.pb(vt<int>(out.begin(), out.begin()+j));
            return;
        }
        
        for(int i = start; i < sz(uvals); ++i) {
            if(kv[uvals[i]] == 0) continue;
            
            out[j] = uvals[i];
            --kv[uvals[i]];
            solve(uvals, i, rs-uvals[i], out, j+1);
            
            ++kv[uvals[i]];  // backtrack
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& cs, int target) {
        kv.clear();
        for(int i = 0; i < sz(cs); ++i) kv[cs[i]]++;
        vt<int> uvals;
        for(auto &p: kv) uvals.pb(p.first);
        
        ans.clear();
        vt<int> out(sz(cs), 0);
        solve(uvals, 0, target, out, 0);
        return ans;
    }
};



//////////////////////////////////////////////////////////////////////////////////////
// BACKTRACKING WITH INDEX
