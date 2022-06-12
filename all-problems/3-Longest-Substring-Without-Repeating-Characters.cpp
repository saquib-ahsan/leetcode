#define sz(x) (int)(x).size()

// SLIDING WINDOW
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uchars;     // unique characters
        int ans = 0, curr_len = 0;
        
        int i = 0, j = 0;
        while(j < sz(s)) {
            // check if we already encountered the current character
            while(uchars.count(s[j]) > 0) {
                uchars.erase(s[i]); // remove chars until we remove repeated char
                
                --curr_len;
                ++i;
            }
            
            // add the current char
            uchars.insert(s[j]);
            ++curr_len;
            
            ans = max(ans, curr_len);
            ++j;
        }
        
        return ans;
    }
};
