#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back

static unordered_map<char, string> kv = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};

class Solution {
private:
    void solve(const string &digits, int i, string &s, vt<string> &ans) {
        if(i >= sz(digits) && sz(s)) {
            ans.pb(s);
            return;
        }
        
        string tmp = kv[digits[i]];
        for(auto &c: tmp) {
            s[i] = c;
            solve(digits, i+1, s, ans);
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        string s(sz(digits), 'x');
        vt<string> ans;
        
        solve(digits, 0, s, ans);
        return ans;
    }
};
