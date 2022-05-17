/**
THIS PROBLEM IS ALMOST FIBONACCI SEQUENCE, IF YOU THINK REVERSE OF THE STATEMENT
**/

class Solution {
private:
    int solve(int n, unordered_map<int, int> &dp) {
        if(n < 0) return 0;
        if(dp[n]) return dp[n];
        
        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }
    
public:
    int climbStairs(int n) {
        unordered_map<int, int> dp;
        dp[0] = 1;
        
        return solve(n, dp);
    }
};
