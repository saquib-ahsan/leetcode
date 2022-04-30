#define sz(x) (int)(x).size()

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int, vector<int>, greater<int>> hp;
        hp.push(a);
        hp.push(b);
        hp.push(c);

        int ans = 0;
        while (sz(hp) > 0) {
            int x = hp.top(); hp.pop();
            int y = hp.top(); hp.pop();
            int z = hp.top(); hp.pop();

            if (x == 0 || y == 0) {
                ans += max(x, y);
            } else if (x + y > z) {
                --x;
                --y;
                ++ans;

                hp.push(x);
                hp.push(y);
                hp.push(z);
            } else {
                ans += (x + y);
            }
        }
        return ans;
    }
};