#define vt vector
#define pb push_back
#define sz(x) (int)(x).size()

class Solution {
private:
    bool queen_can_be_placed(const vt<string> &board, int x, int y) {
        // check column
        for(int i = 0; i < sz(board); ++i) {
            if(board[i][y] == 'Q') return false;
        }
        
        // check left diagonal
        int i = x, j = y;
        while(~i && ~j) {
            if(board[i][j] == 'Q') return false;
            --i; --j;
        }
        
        // check right diagonal
        i = x, j = y;
        while(~i && j<sz(board)) {
            if(board[i][j] == 'Q') return false;
            --i; ++j;
        }
        
        return true;
    }
    
    int solve(vt<string> &board, int i) {
        if(i >= sz(board)) {
            return 1;
        }
        
        int cnt = 0;
        for(int j = 0; j < sz(board); ++j) {
            bool can_place = queen_can_be_placed(board, i, j);
            if(can_place) {
                board[i][j] = 'Q';
                cnt += solve(board, i+1);
                
                board[i][j] = '.';  // backtrack
            }
        }
        
        return cnt;
    }
    
public:
    int totalNQueens(int n) {
        vt<string> board(n, string(n, '.'));
        
        int ans = solve(board, 0);
        return ans;
    }
};
