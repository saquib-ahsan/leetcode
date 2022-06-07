#define vt vector
#define pb push_back
#define sz(x) (int)(x).size()

static unordered_map<int, string> kv;

class Solution {
private:
    void solve(string &digits, int i, string s, vt<string> &ans) {
        if(i >= sz(digits)) {
            if(sz(s)) ans.pb(s);
            return;
        }
        
        string tmp = kv[digits[i] - '0'];
        for(int j = 0; j < sz(tmp); ++j) {
            string t = s;
            t.pb(tmp[j]);
            
            solve(digits, i+1, t, ans);
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        for(const auto &c: digits) {
            if(c == '2') kv[c - '0'] = "abc";
            else if(c == '3') kv[c - '0'] = "def";
            else if(c == '4') kv[c - '0'] = "ghi";
            else if(c == '5') kv[c - '0'] = "jkl";
            else if(c == '6') kv[c - '0'] = "mno";
            else if(c == '7') kv[c - '0'] = "pqrs";
            else if(c == '8') kv[c - '0'] = "tuv";
            else if(c == '9') kv[c - '0'] = "wxyz";
        }
        
        vt<string> ans;
        solve(digits, 0, "", ans);
        return ans;
    }
};
