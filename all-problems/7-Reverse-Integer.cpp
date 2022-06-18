class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x != 0) {
            int d = x % 10;
            
            // integer overflow conditions
            int t1 = INT_MAX/10, t2 = INT_MIN/10;
            if(ans > t1 || (ans == t1 && d > 7)) return 0;
            if(ans < t2 || (ans == t2 && d < -8)) return 0;
            
            ans = ans * 10 + d;
            x /= 10;
        }
        
        return ans;
    }
};
