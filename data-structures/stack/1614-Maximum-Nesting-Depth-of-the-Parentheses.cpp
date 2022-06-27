#define sz(x) (int)(x).size()

class Solution {
public:
    int maxDepth(string s) {
        stack<char> stk;
        int ans = 0;
        for(const auto &c: s) {
            if(c == '(') {
                stk.push('(');
                ans = max(ans, sz(stk));
            } else if(c == ')') {
                stk.pop();
            }
        }
        
        return ans;
    }
};
