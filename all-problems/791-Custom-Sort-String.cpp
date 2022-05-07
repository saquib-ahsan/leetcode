#define sz(x) (int)(x).size()

class Solution {
public:
    string customSortString(string o, string s) {
        unordered_map<char, int> kv;
        for(int i = 0; i < sz(o); ++i) kv[o[i]] = i;
        
        sort(s.begin(), s.end(), [&kv](const char &c1, const char &c2){
            int i1 = kv[c1], i2 = kv[c2];
            return i1 < i2;
        });
        return s;
    }
};
