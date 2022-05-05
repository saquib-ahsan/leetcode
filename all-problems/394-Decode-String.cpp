#define pb push_back
#define sz(x) (int)(x).size()

class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;
        for(auto &c : s) {
            if(c == ']') {
                string t;
                while(stk.top() != '[') {
                    t.pb(stk.top());
                    stk.pop();
                }
                stk.pop();
                
                // extract k
                string temp;
                while(!stk.empty() && isdigit(stk.top())) {
                    temp.pb(stk.top());
                    stk.pop();
                }
                std::reverse(temp.begin(), temp.end());
                int k = stoi(temp);
                
                while(k--) {
                    for(int i = sz(t)-1; ~i; --i) stk.push(t[i]);
                }
            } else {
                stk.push(c);
            }
        }
        
        string ans;
        while(!stk.empty()) {
            ans.pb(stk.top());
            stk.pop();
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
