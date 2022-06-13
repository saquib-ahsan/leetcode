// BINARY SEARCH
typedef long long ll;

class Solution {
private:
    bool children_can_have_x_candies(vector<int> &candies, int x, ll k) {
        ll cnt = 0;
        for(auto &candy: candies) cnt += ll(candy) / ll(x);
        
        return (cnt >= k);
    }
    
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int lo = 1, hi = INT_MIN;
        for(auto &candy: candies) hi = max(hi, candy);
        
        int ans = 0;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            bool success = children_can_have_x_candies(candies, mid, k);
            
            if(success) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return ans;
    }
};



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// BRUTE FORCE
