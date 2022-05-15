class Solution {
public:
    int kthFactor(int n, int k) {
        int ans = -1;
        for(int i = 1; i <= n; ++i) {
            if(n%i == 0) {
                ans = i;
                --k;
            }
            
            if(!k) break;
        }
        
        if(k) return -1;
        return ans;
    }
};

// P.S.: I think this problem should be under easy label!!
