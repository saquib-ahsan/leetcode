class Solution {
public:
    string greatestLetter(string s) {
        for(char c = 'z'; c >= 'a'; --c) {
            bool found1 = find(s.begin(), s.end(), c) != s.end();
            bool found2 = find(s.begin(), s.end(), toupper(c)) != s.end();
            
            if(found1 && found2) return string(1, toupper(c));
        }
        
        return "";
    }
};
