// VERY SIMILAR TO TWO SUM PROBLEM
// https://leetcode.com/problems/two-sum/

// APPROACH
//      X + Y = TARGET
//      FIND THE ELEMENT, Y = TARGET - X, IN THE HASHMAP
//      ADD X IN THE HASHMAP
//
// ADDITIONAL ACTIVITY
//      TARGET IS IN THE FORM, 2^n, which we need find by ourselves
//      CATCH - PRE CALCULATE, 2^i : i = 0, to i = 21 (both inclusive, 2^20 + 2^20 <- mx)
//
//
// DRY RUN FOR d => [1, 1, 1, 3, 3, 3, 7], (d ==> deliciousness)
//      i = 0:
//          NOTHING IN THE HASHMAP, ADD 1: 1 TO IT (ELEM: FREQ)
//
//      i = 1:
//          FIND Y = 2^1 - D[i] = 2^1 - 1 = 1
//          VERDICT = FOUND 
//          FREQ(1) = 1, THERE EXIST A PAIR, I.E, ('1', 1), ONE PAIR
//          ANS  += FREQ(1)
//          {note: '1' represents already present in the hashmap}
//          ++HM[D[i]] (HASHMAP ==> 1: 2)
//
//      i = 2:
//          FIND Y = 2^1 - D[i] = 2^1 - 1 = 1
//          VERDICT = FOUND
//          FREQ(1) = 2, SO THERE EXIST TWO PAIRS OF ('1', 1), ('1', 1)
//          ANS += FREQ(1);
//          ++HM[D[i]] (HASHMAP ==> 1: 3)
//


const int MOD = 1e9 + 7;

class Solution {
public:
    int countPairs(vector<int>& d) {
        // generate all possible powers of 2
        vector<int> targets(22);
        for(int i = 0; i <= 21; ++i) {
            targets[i] = pow(2, i);     // shows TLE, if i use left shift operator in order to calculate power of 2
        }
        
        unordered_map<int, int> kv;
        int ans = 0;
        for(const auto &x: d) {
            for(const auto &target: targets) {
                int y = target - x;
                ans += kv[y];
            }
            
            ++kv[x];
            ans %= MOD;
        }
        
        return ans;
    }
};
