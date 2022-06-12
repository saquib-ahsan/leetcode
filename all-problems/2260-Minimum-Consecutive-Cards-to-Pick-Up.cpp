#define sz(x) (int)(x).size()

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_set<int> ucards;  // unique cards
        int ans = INT_MAX, curr_sz = 0;
        
        int i = 0, j = 0;
        while(j < sz(cards)) {
            if(ucards.count(cards[j]) > 0) {
                while(ucards.count(cards[j]) > 0) {
                    ucards.erase(cards[i]);
                    --curr_sz;
                    
                    ++i;
                }
                
                ans = min(ans, curr_sz+2);
            }
            
            ucards.insert(cards[j]);
            ++curr_sz;
            ++j;
        }
        
        if(ans == INT_MAX) return -1;
        return ans;
    }
};
