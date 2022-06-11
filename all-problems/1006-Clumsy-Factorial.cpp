/*
problem statement:
https://leetcode.com/problems/clumsy-factorial/
*/

/*
APPROACH:
    - Generate an infix expression from the number
    - Convert infix notation to postfix notation
    - Evaluate the postfix notation
*/

#define vt vector
#define pb push_back
#define sz(x) (int)(x).size()

class Solution {
private:
    bool is_operand(string s) {
        return !((s == "/") || (s == "*") || (s == "+") || (s == "-"));
    }
    
    vt<string> num_to_infix(int n) {
        bitset<4> bs(0);    // multiply, division, addition, subtraction
        bs[0] = 1;
        
        vt<string> infix = {to_string(n)};
        while(--n) {
            if(bs[0]) {
                infix.pb("*");
                bs[0] = 0, bs[1] = 1;
            } else if(bs[1]) {
                infix.pb("/");
                bs[1] = 0, bs[2] = 1;
            } else if(bs[2]) {
                infix.pb("+");
                bs[2] = 0, bs[3] = 1;
            } else if(bs[3]) {
                infix.pb("-");
                bs[3] = 0, bs[0] = 1;
            }
            
            infix.pb(to_string(n));
        }
        
        return infix;
    }
    
    vt<string> num_to_postfix(int n) {
        vt<string> infix = num_to_infix(n);
        
        vt<string> postfix;
        stack<string> stk;
        for(const auto &s: infix) {
            if(is_operand(s)) {
                postfix.pb(s);
            } else {
                if(s=="/" || s=="*") {
                    while(sz(stk) && (stk.top()=="/" || stk.top()=="*")) {
                        postfix.pb(stk.top());
                        stk.pop();
                    }
                } else {
                    while(sz(stk)) {
                        postfix.pb(stk.top());
                        stk.pop();
                    }
                }
                
                stk.push(s);
            }
        }
        while(sz(stk)) {
            postfix.pb(stk.top());
            stk.pop();
        }
        
        return postfix;
    }
    
    int evaluate(int n) {
        vt<string> postfix = num_to_postfix(n);
        stack<int> stk;
        
        for(const auto &s: postfix) {
            if(is_operand(s)) {
                stk.push(stoi(s));
            } else {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                
                int tmp = 0;
                if(s == "/") tmp = a / b;
                else if(s == "*") tmp = a * b;
                else if(s == "+") tmp = a + b;
                else tmp = a - b;
                
                stk.push(tmp);
            }
        }
        
        return stk.top();
    }
    
public:
    int clumsy(int n) {
        int ans = evaluate(n);
        return ans;
    }
};
