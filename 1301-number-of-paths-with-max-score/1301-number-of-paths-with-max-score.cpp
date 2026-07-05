class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        const int MOD = 1e9 + 7;
        int n = board.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        vector<vector<int>> ways(n + 1, vector<int>(n + 1, 0));

        dp[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        int dirs[3][2] = {{1, 0}, {0, 1}, {1, 1}};

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (board[i][j] == 'X' || board[i][j] == 'S')
                    continue;

                int best = -1;
                long long cnt = 0;

                for (auto &d : dirs) {
                    int ni = i + d[0];
                    int nj = j + d[1];

                    if (ni >= n || nj >= n || dp[ni][nj] == -1)
                        continue;

                    if (dp[ni][nj] > best) {
                        best = dp[ni][nj];
                        cnt = ways[ni][nj];
                    } else if (dp[ni][nj] == best) {
                        cnt = (cnt + ways[ni][nj]) % MOD;
                    }
                }

                if (best == -1)
                    continue;

                dp[i][j] = best;
                ways[i][j] = cnt % MOD;

                if (board[i][j] != 'E')
                    dp[i][j] += board[i][j] - '0';
            }
        }

        if (dp[0][0] == -1)
            return {0, 0};

        return {dp[0][0], ways[0][0]};
    }
};