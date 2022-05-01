/* 
problem statement:
https://leetcode.com/problems/add-minimum-number-of-rungs/
*/
#define sz(x) (int)(x).size()

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int ans = 0, prev = 0;
        for(int i = 0; i < sz(rungs); ++i) {
            if(rungs[i] - prev > dist) {
                ans += (rungs[i] - prev - 1) / dist;
            }
            
            prev = rungs[i];
        }
        
        return ans;
    }
};
