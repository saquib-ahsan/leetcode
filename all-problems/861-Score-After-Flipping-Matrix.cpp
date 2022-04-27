// APPROACH
//     - AS EVERY ROW OF THE MATRIX IS REPRESENTED AS A NUMBER. SO THE NUMBER TO BE MAXIMUM, THE
//       MOST SIGNIFICANT BIT MUST BE SET (TOGGLE THAT ROW IF NOT SET)
//     - FOR EVERY COLOUMN, COUNT NUMBER OF SET AND UNSET BIT. IF NUMBER OF SET BITS IS LESS THAN
//       THE NUMBER OF UNSET BITS, THEN TOGGLE THAT COLOUMN

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();

        // check row if most significant bit is set or not
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 1) continue;

            // if not set, then toggle the row
            for (int j = 0; j < n; ++j) grid[i][j] = 1 - grid[i][j];
        }

        // check every coloumn
        for (int j = 0; j < n; ++j) {
            int cnt_1s = 0; // count number of set bits
            int cnt_0s = 0; // count number of unset bits
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] == 1) cnt_1s++;
                else cnt_0s++;
            }

            // if no. of set bits is less than unset bits
            // then toggle the coloumn
            if (cnt_1s < cnt_0s) {
                for (int i = 0; i < m; ++i) grid[i][j] = 1 - grid[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            int p = 0;
            for (int j = n - 1; ~j; --j) {
                ans += grid[i][j] * pow(2, p);
                ++p;
            }
        }
        return ans;
    }
};
