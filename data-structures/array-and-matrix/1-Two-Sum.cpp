class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = (int)nums.size();
        
        unordered_map<int, int> kv;
        for(int i = 0; i < n; ++i) {
            int y = target - nums[i];
            if(kv.find(y) != kv.end()) return {kv[y], i};
            
            kv[nums[i]] = i;
        }
        
        return {-1, -1};
    }
};
