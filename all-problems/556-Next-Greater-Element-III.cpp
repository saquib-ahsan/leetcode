#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back

class Solution {
public:
    int nextGreaterElement(int n) {
        vt<int> digits;
        while(n) {
            digits.pb(n%10);
            n /= 10;
        }
        std::reverse(digits.begin(), digits.end());
        
        bool is_possible = std::next_permutation(digits.begin(), digits.end());
        if(!is_possible) return -1;
        
        int ans = 0;
        for(int i = 0; i < sz(digits); ++i) {
            if(ans > INT_MAX/10 || (ans==INT_MAX/10 && digits[i] > 7)) return -1;
            
            ans = ans * 10 + digits[i];
        }
        return ans;
    }
};
