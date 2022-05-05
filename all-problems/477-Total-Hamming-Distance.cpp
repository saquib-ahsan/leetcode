/*
problem statement:
https://leetcode.com/problems/total-hamming-distance/
*/

// APPROACH: A SIMPLE APPLICATION OF PERMUTATION AND COMBINATION
//       - For any ith bit, of all the numbers, count all number of set bits and unset bits. For example,
//         nums = [4, 14, 2], their binary representations are, bnums = [0100, 1110, 0010]
//         for i = 0:
//             number of set bits = 0, and number of unset bits = 3 ==> total hamming distance = no. of set bits * no. of unset bits
//         for i = 1:
//             number of set bits = 2, and number of unset bits = 1 ==> total hamming distance = no. of set bits * no. of unset bits
//
//       - Note: Indexing of binary representation of a number = [....3, 2, 1, 0] ==> [most significant bit.....least significant bit]

typedef long long ll;
#define sz(x) (int)(x).size()

class Solution {
private:
    // check ith bit of a number (0 - indexed)
    bool check_bit(int n, int i) {
        return (n&(1<<i));
    }
    
public:
    int totalHammingDistance(vector<int>& nums) {
        ll ans = 0;
        for(int i = 0; i < 32; ++i) {
            ll cnt_1s = 0, cnt_0s = 0;
            for(int j = 0; j < sz(nums); ++j) {
                if(check_bit(nums[j], i)) ++cnt_1s;
                else ++cnt_0s;
            }
            
            ans += (cnt_1s * cnt_0s);
        }
        
        return int(ans);
    }
};
