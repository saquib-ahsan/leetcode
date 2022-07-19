typedef long long ll;
#define sz(x) (int)(x).size()

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        ll m = (ll)mass;
        sort(a.begin(), a.end());
        for(int i = 0; i < sz(a); ++i) {
            if(a[i] > m) return false;
            
            m += (ll)a[i];
        }
        
        return true;
    }
};
