// RIGHT ROTATION(SHIFT) BY K STEPS = LEFT ROTATION(SHIFT) BY (N - K) STEPS
// C++ STL
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = (int)nums.size();
        k %= n;
        
        std::rotate(nums.begin(), nums.begin()+n-k, nums.end());
    }
};



///////////////////////////////////////////////////////////////////////////////
// Reversal Algorithm
/*
EXPLANATION:
Let AB are the two parts of the input array where A = arr[0..d-1]
and B = arr[d..n-1]. The idea of the algorithm is:
    - Reverse A to get ArB, where Ar is the reverse of A
    - Reverse B to get ArBr, where Br is the reverse of B
    - Reverse all to get (ArBr)r = BA

Note: the above algorithm describes the left rotation (LEFT SHIFT)
*/
// verdict: accepted
class Solution {
private:
    void rev_arr(vector<int> &nums, int i, int j) {
        while(i < j) {
            std::swap(nums[i], nums[j]);
            ++i;
            --j;
        }
    }
    
public:
    void rotate(vector<int>& nums, int k) {
        int n = (int)nums.size();
        k %= n;
        int d = n - k;  // the above algorithm describes the left rotation
        
        // reverse nums[0...d-1]
        rev_arr(nums, 0, d-1);
        
        // reverse nums[d...n-1]
        rev_arr(nums, d, n-1);
        
        // reverse entire array
        rev_arr(nums, 0, n-1);
    }
};



///////////////////////////////////////////////////////////////////////////////
// Juggling Algorithm: Extension of Cyclic Rotation (Rotate one by one)



///////////////////////////////////////////////////////////////////////////////
// cyclically rotate an array by one (Rotate one by one)
/*
EXPLANATION:
    - Store last element in variable say x
    - Shift all elements one position right
    - Replace first element of array with x
*/
// verdict: TLE
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = (int)nums.size();
        k %= n;
        
        while(k--) {
            int x = nums[n-1];
            for(int i = n-1; i > 0; --i) nums[i] = nums[i-1];
            
            nums.front() = x;
        }
    }
};



///////////////////////////////////////////////////////////////////////////////
// Using Auxiliary Array
/*
EXPLANATION:
    - Store last k elements in auxiliary array
    - Store first (n - k) elements in same auxiliary array
    - Copy back to original array
*/
// verdict: accepted
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = (int)nums.size();
        k %= n;
        
        vector<int> aux(n);
        int j = 0;
        // store last k elements
        for(int i = n-k; i < n; ++i) aux[j++] = nums[i];
        
        // store first n-k elements
        for(int i = 0; i < n-k; ++i) aux[j++] = nums[i];
        
        // copy back to original array
        for(int i = 0; i < n; ++i) nums[i] = aux[i];
    }
};
