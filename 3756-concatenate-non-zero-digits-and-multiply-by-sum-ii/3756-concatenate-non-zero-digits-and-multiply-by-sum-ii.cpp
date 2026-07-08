class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> prefNum(n + 1, 0), pow10(n + 1, 1);
        vector<int> prefSum(n + 1, 0), prefCnt(n + 1, 0);

        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';

            prefSum[i + 1] = prefSum[i] + d;
            prefCnt[i + 1] = prefCnt[i];
            prefNum[i + 1] = prefNum[i];

            if (d != 0) {
                prefCnt[i + 1]++;
                prefNum[i + 1] = (prefNum[i] * 10 + d) % MOD;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int cnt = prefCnt[r + 1] - prefCnt[l];

            long long num = (prefNum[r + 1]
                            - prefNum[l] * pow10[cnt] % MOD
                            + MOD) % MOD;

            long long sum = prefSum[r + 1] - prefSum[l];

            ans.push_back((num * sum) % MOD);
        }

        return ans;
    }
};