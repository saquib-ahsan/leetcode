/*
problem statement:
https://leetcode.com/problems/clumsy-factorial/
*/

/*
APPROACH:
    - MAKE AN EXPRESSION(INFIX) FROM THE NUMBER
    - CONVERT THE INFIX NOATION TO POSTFIX NOTATION
    - EVALUATE THE POSTFIX NOTATION
*/

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define repe(a, x) for(auto &a: x)

class Solution {
private:
    bool is_operand(string s) {
        return !((s == "/") || (s == "*") || (s == "+") || (s == "-"));
    }

    // infix to postfix conversion
    vt<string> if_to_pf(const vt<string> &vs) {
        vt<string> expr;
        stack<string> stk;
        repe(s, vs) {
            if (is_operand(s)) {
                expr.pb(s);
            } else {
                if (s == "/" || s == "*") {
                    while (sz(stk) && (stk.top() == "/" || stk.top() == "*")) {
                        expr.pb(stk.top());
                        stk.pop();
                    }
                } else {
                    while (sz(stk) && (stk.top() != "+" || stk.top() != "-")) {
                        expr.pb(stk.top());
                        stk.pop();
                    }
                }

                stk.push(s);
            }

        }
        while (sz(stk)) {
            expr.pb(stk.top());
            stk.pop();
        }

        // repe(s, expr) cout << s;
        // cout << nl;

        return expr;
    }

    int eval_expr(const vt<string> &vs) {
        vt<string> expr = if_to_pf(vs);
        stack<int> stk;
        repe(s, expr) {
            if (is_operand(s)) {
                stk.push(stoi(s));
            } else {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();

                int res = 0;
                if (s == "/") res = a / b;
                else if (s == "*") res = a * b;
                else if (s == "+") res = a + b;
                else res = a - b;

                stk.push(res);
            }
        }

        return stk.top();
    }
    
public:
    int clumsy(int n) {
        bitset<4> bs(0);    // multiply, division, addition, subtraction
        bs[0] = 1;
        vt<string> expr;
        expr.pb(to_string(n));
        --n;
        while (n) {
            if (bs[0]) {
                expr.pb("*");
                expr.pb(to_string(n));
                bs[0] = 0; bs[1] = 1;
            } else if (bs[1]) {
                expr.pb("/");
                expr.pb(to_string(n));
                bs[1] = 0; bs[2] = 1;
            } else if (bs[2]) {
                expr.pb("+");
                expr.pb(to_string(n));
                bs[2] = 0; bs[3] = 1;
            } else {
                expr.pb("-");
                expr.pb(to_string(n));
                bs[3] = 0; bs[0] = 1;
            }

            --n;
        }
        
        return eval_expr(expr);
    }
};

// P.S.: Code became longer than thought, so i think optimization is needed!!
