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
