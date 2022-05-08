// THE BELOW ALGORITHM NEEDS AN OPTIMIZATION

#define vt vector
#define eb emplace_back
#define sz(x) (int)(x).size()

class Solution {
private:
    bool is_valid_paren(const string &s) {
        stack<char> stk;
        for(const auto &c: s) {
            if(c == '(') {
                stk.push(c);
            } else {
                if(stk.empty()) return false;
                stk.pop();
            }
        }
        return (sz(stk) == 0);
    }
    
    void solve(int n, string s, vt<string> &ans) {
        if(n < 0) return;
        if(n == 0) {
            ans.eb(s);
            return;
        }
        
        solve(n-1, s+"(", ans);
        solve(n-1, s+")", ans);
    }
    
public:
    vector<string> generateParenthesis(int n) {
        n *= 2;
        vt<string> all_possible;
        solve(n, "", all_possible);
        
        vt<string> ans;
        for(int i = 0; i < sz(all_possible); ++i) {
            if(is_valid_paren(all_possible[i])) ans.eb(all_possible[i]);
        }
        return ans;
    }
};
