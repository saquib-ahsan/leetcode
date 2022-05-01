/*
problem statement:
https://leetcode.com/problems/removing-minimum-and-maximum-from-array/
*/

// APPROACH
//      - X: Remove both from left (front) side
//      - Y: Remove both from right (back) side
//      - Z: Remove one from left side and one from right side
//
//      - ans = minimum(X, Y, Z)

#define sz(x) (int)(x).size()

class Solution {
public:
    int minimumDeletions(vector<int>& nums) { 
        int mx_i, mn_i; // indices of max element and min element
        int mx = INT_MIN, mn = INT_MAX;
        for(int i = 0; i < sz(nums); ++i) {
            if(nums[i] > mx) {
                mx = nums[i];
                mx_i = i;
            }
            if(nums[i] < mn) {
                mn = nums[i];
                mn_i = i;
            }
        }
        
        int ans = INT_MAX;
        if(mx_i < mn_i) {
            int x = (mx_i + 1) + (mn_i - mx_i);
            int y = (sz(nums) - mn_i) + (mn_i - mx_i);
            int z = (mx_i + 1) + (sz(nums) - mn_i);
            
            ans = min(x, min(y, z));
        } else {
            int x = (mn_i + 1) + (mx_i - mn_i);
            int y = (sz(nums) - mx_i) + (mx_i - mn_i);
            int z = (mn_i + 1) + (sz(nums) - mx_i);
            
            ans = min(x, min(y, z));
        }
        return ans;
    }
};
