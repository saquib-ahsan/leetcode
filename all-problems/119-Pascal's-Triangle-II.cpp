class Solution {
public:
    vector<int> getRow(int row_index) {
        vector<int> ans;
        for(int i = 0; i <= row_index; ++i) {
            int n = (int)ans.size();
            int prev = 0;
            for(int j = 0; j < n; ++j) {
                int tmp = ans[j];
                ans[j] = prev + ans[j];
                prev = tmp;
            }
            ans.push_back(1);
        }
        
        return ans;
    }
};



////////////////////////////////////////////////////////////////////////////////////////////////////////////
// RECURSIVE IMPLEMENTATION
class Solution {
private:
    void solve(vector<int> &ans, int i, int row_index) {
        if(i > row_index) return;
        
        int n = (int)(ans).size();
        int prev = 0;
        for(int j = 0; j < n; ++j) {
            int tmp = ans[j];
            ans[j] = prev + ans[j];
            prev = tmp;
        }
        ans.push_back(1);
        
        solve(ans, i+1, row_index);
    }
    
public:
    vector<int> getRow(int row_index) {
        vector<int> ans;
        int i = 0;
        
        solve(ans, i, row_index);
        return ans;
    }
};
