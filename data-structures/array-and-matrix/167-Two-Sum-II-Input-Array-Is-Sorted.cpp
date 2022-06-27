// BINARY SEARCH
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = (int)nums.size();
        
        for(int i = 0; i < n-1; ++i) {
            int y = target - nums[i];
            
            int a = i+1, b = n-1;
            while(a <= b) {
                int mid = (a + b) / 2;
                if(y == nums[mid]) return {i+1, mid+1};
                
                if(y > nums[mid]) a = mid + 1;
                else b = mid - 1;
            }
        }
        
        return {-1, -1};
    }
};



//////////////////////////////////////////////////////////////////////////////////
// TWO POINTERS
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = (int)nums.size()-1;
        while(i < j) {
            int tmp = nums[i] + nums[j];
            if(target == tmp) return {i+1, j+1};
            
            if(target > tmp) ++i;
            else --j;
        }
        
        return {-1, -1};
    }
};
