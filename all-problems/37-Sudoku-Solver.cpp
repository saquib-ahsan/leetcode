#define vt vector
#define pb push_back
#define sz(x) (int)(x).size()

static const int N = 9;
static const int n = 3;

class Solution {
private:
    bool num_can_be_placed(const vt<vt<char>> &board, int x, int y, int num) {
        // check row and column
        for(int k = 0; k < N; ++k) {
            if((board[x][k] == num+'0') || (board[k][y] == num+'0')) return false;
        }
        
        // check subgrid
        int sx = (x / n) * n;   // x-coordinate of subgrid
        int sy = (y / n) * n;   // y-coordinate of subgrid
        for(int i = sx; i < sx+n; ++i) {
            for(int j = sy; j < sy+n; ++j) {
                if(board[i][j] == num+'0') return false;
            }
        }
        
        // hurray, we can place the number
        return true;
    }
    
    bool solve(vt<vt<char>> &board, int i, int j) {
        // base case
        if(i >= N) return true;
        
        // RECURSIVE CASES
        // check if we crossed the last column
        if(j == N) return solve(board, i+1, 0);
        
        // check if the cell is prefilled
        if(board[i][j] != '.') return solve(board, i, j+1);
        
        // check out all possibilities for empty cell
        for(int x = 1; x <= N; ++x) {
            // check if the curr number (x) can be placed
            bool can_place = num_can_be_placed(board, i, j, x);
            if(can_place) {
                board[i][j] = x + '0';
                
                bool check_next_cell = solve(board, i, j+1);
                if(check_next_cell) return true;
            }
        }
        board[i][j] = '.';  // backtrack
        return false;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};
