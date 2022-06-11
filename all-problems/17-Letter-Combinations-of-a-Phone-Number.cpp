#define vt vector
#define pb push_back
#define sz(x) (int)(x).size()

static unordered_map<char, string> kv;
static vt<string> ans;

class Solution {
    void solve(const string &d, int i, string &s) {
        if(i >= sz(d)) {
            if(sz(s)) ans.pb(s);
            return;
        }
        
        string tmp = kv[d[i]];
        for(const auto &c: tmp) {
            s[i] = c;
            solve(d, i+1, s);
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        kv = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        
        ans.clear();
        string s(sz(digits), 'x');
        
        solve(digits, 0, s);
        return ans;
    }
};
