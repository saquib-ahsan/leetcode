// BRUTE FORCE - TIME LIMIT EXCEEDED (TLE)

#define vt vector
#define pb push_back
#define sz(x) (int)(x).size()

class Solution {
private:
    bool is_beautifully_arranged(const vt<int> &nums) {
        for(int i = 0; i < sz(nums); ++i) {
            int j = i + 1;
            if((nums[i]%j != 0) && (j%nums[i] != 0)) return false;
        }
        return true;
    }
    
public:
    int countArrangement(int n) {
        vt<int> nums;
        for(int i = 1; i <= n; ++i) nums.pb(i);
        
        int ans = 0;
        do {
            bool tmp = is_beautifully_arranged(nums);
            if(tmp) ++ans;
        } while(next_permutation(nums.begin(), nums.end()));
        
        return ans;
    }
};



///////////////////////////////////////////////////////////////////////////////////////////////////
