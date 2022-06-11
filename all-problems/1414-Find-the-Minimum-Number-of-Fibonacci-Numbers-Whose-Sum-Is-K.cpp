#define vt vector
#define pb push_back
#define sz(x) (int)(x).size()

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vt<int> dp = {1, 1};
        int prev = dp[0], curr = dp[1];
        
        int sum = prev + curr;
        while(sum <= k) {
            dp.pb(sum);
            
            prev = curr;
            curr = sum;
            
            sum = prev + curr;
        }
        
        
        int ans = 0;
        for(int i = sz(dp)-1; ~i && k; --i) {
            if(k >= dp[i]) {
                ++ans;
                k -= dp[i];
            }
        }
        return ans;
    }
};
