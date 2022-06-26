// OPTIMIZED SOLUTION
/* 
EXPLANATION:
    - Traverse the array and store and sum achieved so far in variable called curr_sum (we can refer as prefix sum)
    - Store all the prefix sum in a map, later we will need it
    - Check if the curr_sum equals desired sum (i will explain later why)
        
    - Suppose our curr_sum over come desired by 'tmp' amount i.e., tmp = curr_sum - desired_sum
    - Search the 'tmp' in map: what it tells is that we have a subarray ([0,....,i]) having sum = curr_sum, and we want to 
      find the subarray ([0,....,j] and j < i) that must have sum = tmp. In other words, desired_sum([j+1,....,i]) = curr_sum([0,...,i]) - tmp([0,...,j])
        
        
    - If curr_sum == desired_sum, because tmp = curr_sum - desired = 0, so 0 may or may or stored in the map.
*/
// verdict: accepted
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = (int)nums.size();
        
        int curr_sum = 0;
        unordered_map<int, int> kv;
        
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            curr_sum += nums[i];
            if(curr_sum == k) ++ans;
            
            int tmp = curr_sum - k;
            if(kv.find(tmp) != kv.end()) ans += kv[tmp];
            
            ++kv[curr_sum];
        }
        
        return ans;
    }
};



///////////////////////////////////////////////////////////////////
// NAIVE SOLUTION
// EXPLANATION:
//     - Calculate sum of every subarray
//     - Check if the subarray sum equals desired sum
//
// verdict: TLE
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = (int)nums.size();
        
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            int sum = 0;
            for(int j = i; j < n; ++j) {
                sum += nums[j];
                
                if(sum == k) ++ans;
            }
        }
        
        return ans;
    }
};
