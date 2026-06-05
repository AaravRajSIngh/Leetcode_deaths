class Solution {
public:
    struct Node {
        long long cnt;
        long long wav;
        Node(long long c = 0, long long w = 0) : cnt(c), wav(w) {}
    };

    string s;
    Node dp[20][11][11][2][2];
    bool vis[20][11][11][2][2];

    Node dfs(int pos, int prev1, int prev2, bool started, bool tight) {
        if (pos == s.size())
            return Node(1, 0);

        if (!tight && vis[pos][prev1][prev2][started][0])
            return dp[pos][prev1][prev2][started][0];

        int lim = tight ? s[pos] - '0' : 9;

        Node res;

        for (int d = 0; d <= lim; d++) {
            bool ntight = tight && (d == lim);

            if (!started && d == 0) {
                Node nxt = dfs(pos + 1, 10, 10, false, ntight);
                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
            } else {
                int add = 0;

                if (started && prev2 != 10) {
                    if ((prev1 > prev2 && prev1 > d) ||
                        (prev1 < prev2 && prev1 < d))
                        add = 1;
                }

                Node nxt = dfs(
                    pos + 1,
                    d,
                    started ? prev1 : 10,
                    true,
                    ntight
                );

                res.cnt += nxt.cnt;
                res.wav += nxt.wav + nxt.cnt * add;
            }
        }

        if (!tight) {
            vis[pos][prev1][prev2][started][0] = true;
            dp[pos][prev1][prev2][started][0] = res;
        }

        return res;
    }

    long long solve(long long x) {
        if (x <= 0) return 0;

        memset(vis, 0, sizeof(vis));
        s = to_string(x);

        return dfs(0, 10, 10, false, true).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};