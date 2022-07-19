#define sz(x) (int)(x).size()

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> stk;
        for(int i = 0; i < sz(a); ++i) {
            if(a[i]>0 || stk.empty()) {
                stk.push(a[i]);
                continue;
            }
            
            while(sz(stk) && stk.top()>0 && abs(a[i])>stk.top()) stk.pop();
            
            if(stk.empty() || stk.top()<0) stk.push(a[i]);
            else if(abs(a[i]) == stk.top()) stk.pop();
        }
        
        vector<int> ans;
        while(sz(stk)) {
            ans.push_back(stk.top());
            stk.pop();
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
