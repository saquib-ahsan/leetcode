// ITERATION IMPLEMENTATION METHOD
#define vt vector
#define sz(x) (int)(x).size()

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = sz(board);
        vt<bool> is_taken(n+1, false);
        
        // rows validation
        for(int i = 0; i < n; ++i) {
            vt<bool> temp = is_taken;
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == '.') continue;
                
                if(temp[board[i][j] - '0']) return false;
                temp[board[i][j] - '0'] = true;
            }
        }
        
        // columns validation
        for(int j = 0; j < n; ++j) {
            vt<bool> temp = is_taken;
            for(int i = 0; i < n; i++) {
                if(board[i][j] == '.') continue;
                
                if(temp[board[i][j] - '0']) return false;
                temp[board[i][j] - '0'] = true;
            }
        }
        
        // 3x3 sub-grid validation
        for(int i = 0; i < n; i+=3) { // jump row by 3 steps
            for(int j = 0; j < n; j+=3) { // jump column by 3 steps
                vt<bool> temp = is_taken;
                for(int k = i; k < i+3; ++k) {
                    for(int l = j; l < j+3; ++l) {
                        if(board[k][l] == '.') continue;
                        if(temp[board[k][l] - '0']) return false;
                        temp[board[k][l] - '0'] = true;
                    }
                }
                
            }
        }
        
        
        return true;
    }
};



/////////////////////////////////////////////////////////////////////////////////////////////////
// RECURSION IMPLEMENTATION METHOD
