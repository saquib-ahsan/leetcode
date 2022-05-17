class Solution {
private:
    void solve(vector<char> &s, int i, int j) {
        if (i >= j) return;

        std::swap(s[i], s[j]);
        solve(s, i + 1, j - 1);
    }

public:
    void reverseString(vector<char>& s) {
        int i = 0, j = (int)s.size() - 1;
        solve(s, i, j);
    }
};