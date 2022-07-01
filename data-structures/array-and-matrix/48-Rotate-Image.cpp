class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        
        // reverse rows of the matrix
        for(int i = 0; i < n/2; ++i) std::swap(matrix[i], matrix[n-i-1]);
        
        // reverse elements along diagonals
        for(int i = 0; i < n-1; ++i) {
            for(int j = i+1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};



/////////////////////////////////////////////////////////////////////////////////
