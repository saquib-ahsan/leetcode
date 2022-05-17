class Solution {
private:
    double solve(double x, int n) {
        if(n == 0) return 1;
        
        double y = solve(x, n/2);
        
        if(n&1) return y * y * x;
        return y * y;
    }
    
public:
    double myPow(double x, int n) {
        double ans = solve(x, n);
        
        if(n < 0) return 1 / ans;
        return ans;
    }
};


/**
An interesting fact: In line number 4, change the statement from "return 1;" to "return 1.0" and see the difference in runtime!!
**/
