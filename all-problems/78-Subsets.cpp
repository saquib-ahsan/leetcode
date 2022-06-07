#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back


// BIT MANUPULATION
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int N = sz(nums);
        
        vt<vt<int>> subsets;
        for(int i = 0; i < pow(2, N); ++i) {
            bitset<10> bs(i);
            vt<int> subset;
            for(int j = 0; j < N; ++j) {
                if(bs[j]) subset.pb(nums[j]);
            }
            
            subsets.pb(subset);
        }
        
        return subsets;
    }
};
