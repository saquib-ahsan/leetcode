#define vt vector
#define pb push_back

static int N;
static vt<vt<string>> boards;

class Solution {
private:
    bool can_place(const vt<string> &board, int x, int y) {
        // check column
        for(int i = 0; i < x; ++i) {
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
        while(~i && j<N) {
            if(board[i][j] == 'Q') return false;
            
            --i; ++j;
        }
        
        
        return true;
    }
    
    void solve(int i, vt<string> &board) {
        if(i >= N) {
            boards.pb(board);
            return;
        }
        
        for(int j = 0; j < N; ++j) {
            if(can_place(board, i, j)) {
                board[i][j] = 'Q';
                solve(i+1, board);
                
                board[i][j] = '.'; // backtrack
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vt<string> board(n, string(n, '.'));
        
        boards.clear();
        solve(0, board);
        return boards;   
    }
};
