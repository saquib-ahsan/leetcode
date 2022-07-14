class Solution {
private:
    bool is_operand(string s) {
        return !(s=="+" || s=="-" || s=="*" || s=="/");
    }
    
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(const auto &s: tokens) {
            if(is_operand(s)) {
                stk.push(stoi(s));
            } else {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                
                int res = 0;
                if(s == "/") res = a / b;
                else if(s == "*") res = a * b;
                else if(s == "+") res = a + b;
                else res = a - b;
                
                stk.push(res);
            }
        }
        
        return stk.top();
    }
};
