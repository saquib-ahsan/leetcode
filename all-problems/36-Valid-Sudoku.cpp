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
#define vt vector

static const int N = 9;
static const int n = 3;

class Solution {
private:
    bool num_placed_correctly(const vt<vt<char>> &board, int x, int y, char num) {
        // check row and column
        for(int k = 0; k < N; ++k) {
            if(board[x][k] == num || board[k][y] == num) return false;
        }
        
        // check sub-grid
        int sx = (x / n) * n;   // x-coordinate of subgrid
        int sy = (y / n) * n;   // y-coordinate of subgrid
        for(int i = sx; i < sx+n; ++i) {
            for(int j = sy; j < sy+n; ++j) {
                if(board[i][j] == num) return false;
            }
        }
        
        // hurray, num placed correctly
        return true;
    }
    
    bool solve(vt<vt<char>> &board, int i, int j) {
        if(i >= N) return true;
        
        // check if we crossed last column
        if(j == N) return solve(board, i+1, 0);
        
        // check if current cell is empty
        if(board[i][j] == '.') return solve(board, i, j+1);
        
        char tmp = board[i][j];
        board[i][j] = '.';
        bool placed_correctly = num_placed_correctly(board, i, j, tmp);
        board[i][j] = tmp;
        
        bool check_next_cell = solve(board, i, j+1);
        return (placed_correctly && check_next_cell);
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans = solve(board, 0, 0);
        return ans;
    }
};
