#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7;
typedef long long ll;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(all(hc)); hc.insert(hc.begin(), 0); hc.pb(h);
        sort(all(vc)); vc.insert(vc.begin(), 0); vc.pb(w);
        
        ll dx, dy;
        dx = dy = -1;
        for(int i = 0; i < sz(vc)-1; ++i) dx = max(dx, ll(vc[i+1]-vc[i]));
        for(int i = 0; i < sz(hc)-1; ++i) dy = max(dy, ll(hc[i+1]-hc[i]));
        
        return (int)(((dx%MOD) * (dy%MOD)) % MOD);
    }
};
