class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> v = {1, 1};
        int tmp = 2;
        while(tmp <= k) {
            v.push_back(tmp);
            
            int n = (int)v.size();
            tmp = v[n-1] + v[n-2];
        }
        
        int cnt = 0;
        int j = (int)v.size() - 1;
        while(k > 0) {
            if(k >= v[j]) {
                k -= v[j];
                ++cnt;
            }
            
            --j;
        }
        return cnt;
    }
};
