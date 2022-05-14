#define vt vector
#define pb push_back
#define sz(x) (int)(x).size()

class Solution {
private:
    int dgts_to_num(vt<int> &dgts) {
        long long ans = 0;
        for(auto &d: dgts) ans = ans * 10 + d;
        return int(ans);
    }
    
    int dgts_to_num(vt<int> dgts, int x, int y) {
        for(int i = 0; i < sz(dgts); ++i) {
            if(dgts[i] == x) dgts[i] = y;
        }
        return dgts_to_num(dgts);
    }
    
public:
    int maxDiff(int n) {
        vt<int> dgts;
        while(n) {
            dgts.pb(n % 10);
            n /= 10;
        }
        std::reverse(dgts.begin(), dgts.end());
        
        // determine x1, y1, x2, y2
        int x1 = -1, y1 = 9, x2 = -1, y2 = 0;
        bool found_x1 = false, found_x2 = false;
        if(dgts[0] > 1) {
            x2 = dgts[0];
            y2 = 1;
            found_x2 = true;
        }
        
        for(auto &d: dgts) {
            if(!found_x1 && d != y1) {
                x1 = d;
                found_x1 = true;
            }
            
            if(!found_x2 && d != y2) {
                if(d == dgts[0]) continue;
                x2 = d;
                found_x2 = true;
            }
            
            if(found_x1 && found_x2) break;
        }
        
        // get maximum number
        int mx = dgts_to_num(dgts, x1, y1);
        // get minimum number
        int mn = dgts_to_num(dgts, x2, y2);
        
        return mx - mn;
    }
};
