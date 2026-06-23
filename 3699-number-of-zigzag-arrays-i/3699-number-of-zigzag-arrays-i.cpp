class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<long long> up(m, 0), down(m, 0);

        for (int i = 0; i < m; i++) {
            up[i] = m - i - 1; // larger values available
            down[i] = i;       // smaller values available
        }

        for (int len = 3; len <= n; len++) {
            vector<long long> newUp(m, 0), newDown(m, 0);

            long long suf = 0;
            for (int i = m - 1; i >= 0; i--) {
                if (i + 1 < m)
                    suf = (suf + down[i + 1]) % MOD;
                newUp[i] = suf;
            }

            long long pre = 0;
            for (int i = 0; i < m; i++) {
                if (i - 1 >= 0)
                    pre = (pre + up[i - 1]) % MOD;
                newDown[i] = pre;
            }

            up = move(newUp);
            down = move(newDown);
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return (int)ans;
    }
};
