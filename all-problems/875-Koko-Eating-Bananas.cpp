#define sz(x) (int)(x).size()

class Solution {
private:
    bool can_eat_bananas(vector<int> &piles, int h, int k) {
        for(auto &x: piles) {
            h -= ceil(static_cast<double>(x) / k);
        }
        return h >= 0;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = INT_MIN;
        for(int i = 0; i < sz(piles); ++i) hi = max(hi, piles[i]);
        
        int ans = 0;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            
            bool ok = can_eat_bananas(piles, h, mid);
            if(ok) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};
