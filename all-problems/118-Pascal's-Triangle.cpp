class Solution {
public:
    vector<vector<int>> generate(int num_rows) {
        vector<vector<int>> ans = {{1}};
        if(num_rows == 1) return ans;
        
        for(int row = 1; row < num_rows; ++row) {
            vector<int> v = {1};
            int n = (int)ans[row-1].size();
            for(int j = 0; j < n-1; ++j) {
                v.push_back(ans[row-1][j] + ans[row-1][j+1]);
            }
            v.push_back(1);
            
            ans.push_back(v);
        }
        
        return ans;
    }
};
