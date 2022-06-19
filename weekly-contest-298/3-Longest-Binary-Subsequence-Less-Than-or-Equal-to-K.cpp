class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = (int)s.size();
        reverse(s.begin(), s.end());
        
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '0') {
                ++ans;
            } else if(i < 31) {     // !important condition (i < 31)
                if(k >= (1<<i)) {
                    ++ans;
                    k -= (1<<i);
                }
            }
        }
        
        return ans;
    }
};
