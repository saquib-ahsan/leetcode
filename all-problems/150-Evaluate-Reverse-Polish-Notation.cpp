#define sz(x) (int)(x).size()

class Solution {
private:
    bool is_operator(string s) {
        return ((s == "/") || (s == "*") || (s == "+") || (s == "-"));
    }
    
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(auto &s: tokens) {
            if(is_operator(s)) {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                int res = 0;
                
                if(s == "/") res = a / b;
                else if(s == "*") res = a * b;
                else if(s == "+") res = a + b;
                else if(s == "-") res = a - b;
                
                stk.push(res);
            } else {
                stk.push(stoi(s));
            }
        }
        
        return stk.top();
    }
};
