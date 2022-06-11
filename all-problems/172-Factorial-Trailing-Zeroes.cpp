/*
problem statement:
https://leetcode.com/problems/factorial-trailing-zeroes/
*/

/*
APPROACH:
    - Compute prime factorization of the factorial n i.e. n!
    - For example, n! = (2, x1) * (3, x2) * (5, x3) * ....   
                         where (2, x1) denotes pow(2, x1)
    
    - We know that 2 * 5 = 10, and in any n!, x3(number of 5s) is always less than
      x1(number of 2s). So we only need to find x3.
      
    - Mathematically, we can find power of a prime number in any n! as below:
        GIF(n / (5, 1)) + GIF(n / (5, 2)) + GIF(n / (5, 3)) + ... + GIF(n / (5, t))
        where GIF(n / (5, t)) = 0;
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        int N = 5;
        
        int tmp = n / N;
        while(tmp) {
            ans += tmp;
            
            N *= 5;
            tmp = n / N;
        }
        
        return ans;
    }
};

// TIME COMPLEXITY == O(LOGN)
// SPACE COMPLEXITY = O(1)
