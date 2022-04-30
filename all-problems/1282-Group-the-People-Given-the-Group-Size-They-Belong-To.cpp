#define vt vector
#define eb emplace_back
#define sz(x) (int)(x).size()

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        map<int, vt<int>> kv;
        for (int i = 0; i < sz(gs); ++i) kv[gs[i]].eb(i);

        vt<vt<int>> ans;
        for (auto &p : kv) {
            int gp_sz = p.first;
            vt<int> gi = p.second;  // grouped indices

            for (int i = 0; i < sz(gi); i += gp_sz) {
                int n = gp_sz, j = i;
                vt<int> temp;
                while (n--) {
                    temp.eb(gi[j]);
                    ++j;
                }

                ans.eb(temp);
            }
        }

        return ans;
    }
};