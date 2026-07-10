class Solution {
public:
    int minJumps(vector<vector<int>>& jump, int start, int end, int level) {
        if (start == end) return 0;
        if (jump[start][0] >= end) return 1;
        if (jump[start][level] < end) return INT_MAX;

        int j = level;
        while (j >= 0 && jump[start][j] >= end) j--;
        return (1 << j) + minJumps(jump, jump[start][j], end, j);
    }

    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {
        vector<pair<int,int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({nums[i], i});

        sort(v.begin(), v.end());

        vector<int> sortedNums;
        vector<int> idx(n);

        for (int i = 0; i < n; i++) {
            sortedNums.push_back(v[i].first);
            idx[v[i].second] = i;
        }

        int LOG = 32 - __builtin_clz(n) + 1;
        vector<vector<int>> jump(n, vector<int>(LOG));

        int r = 0;
        for (int i = 0; i < n; i++) {
            while (r + 1 < n && sortedNums[r + 1] - sortedNums[i] <= maxDiff)
                r++;
            jump[i][0] = r;
        }

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                jump[i][k] = jump[jump[i][k - 1]][k - 1];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = idx[q[0]];
            int v = idx[q[1]];

            int l = min(u, v);
            int rr = max(u, v);

            int res = minJumps(jump, l, rr, LOG - 1);
            ans.push_back(res == INT_MAX ? -1 : res);
        }

        return ans;
    }
};