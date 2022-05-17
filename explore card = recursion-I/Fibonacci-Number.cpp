class Solution {
private:
    int solve(int n, unordered_map<int, int> &dp) {
        if(n <= 1) return n;
        if(dp[n]) return dp[n];
        
        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }
    
public:
    int fib(int n) {
        unordered_map<int, int> dp;
        return solve(n, dp);
    }
};
