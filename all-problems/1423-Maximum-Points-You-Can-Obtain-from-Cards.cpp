/*
APPROACH
    - let's see how we can choose from left and right end
    -               LEFT    ||     RIGHT
                      0     ||       k
                      1     ||       k-1
                      2     ||       k-2
                            ... 
                      k     ||       0
    
    - for example, arr = [1, 2, 3, 4, 5, 6, 1], k = 3
                   left = [0, 1, 1+2, 1+2+3] ==> values when we extract from left end, no element,
                                                 one element, two element, and three element respectively
                                                 (from l --> r)
                                                 
                   right = [5+6+1, 6+1, 1, 0] ==> values when we extract from right end, no element,
                                                  one element, two element, and three element respectively
                                                  (from r --> l)
                   
                                                      
                   our options: {0        +     (5+6+1)} ===> 0 left element and 3 right elements
                              : {1        +     (6+1)}  ===> 1 left element and 2 right elements
                              : {1+2      +     (1)}  ===> 2 left elements and 1 right element
                              : {1+2+3    +      0}  ===> 3 left elements and 0 right element
                              
                   answer = maximum of all the options
*/

#define vt vector
#define sz(x) (int)(x).size()

class Solution {
public:
    int maxScore(vector<int>& cps, int k) {     // cps = cardPoints
        vt<int> left(k+1, 0);
        for(int i = 1; i <= k; ++i) left[i] = left[i-1] + cps[i-1];
        
        vt<int> right(k+1, 0);
        int j = sz(cps) - 1;
        for(int i = k-1; ~i; --i) right[i] = right[i+1] + cps[j--];
        
        
        int ans = 0;
        for(int i = 0; i < sz(left); ++i) {
            int temp = left[i] + right[i];
            ans = max(ans, temp);
        }
        return ans;
    }
};
