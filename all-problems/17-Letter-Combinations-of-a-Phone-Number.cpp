#define vt vector
#define pb push_back
#define sz(x) (int)(x).size()

static unordered_map<char, string> kv;

class Solution {
private:
    void solve(string &digits, int i, string s, vt<string> &ans) {
        if(i >= sz(digits)) {
            if(sz(s)) ans.pb(s);
            return;
        }
        
        string tmp = kv[digits[i]];
        for(int j = 0; j < sz(tmp); ++j) {
            string t = s;
            t.pb(tmp[j]);
            
            solve(digits, i+1, t, ans);
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        for(const auto &c: digits) {
            if(c == '2') kv[c] = "abc";
            else if(c == '3') kv[c] = "def";
            else if(c == '4') kv[c] = "ghi";
            else if(c == '5') kv[c] = "jkl";
            else if(c == '6') kv[c] = "mno";
            else if(c == '7') kv[c] = "pqrs";
            else if(c == '8') kv[c] = "tuv";
            else if(c == '9') kv[c] = "wxyz";
        }
        
        vt<string> ans;
        solve(digits, 0, "", ans);
        return ans;
    }
};
