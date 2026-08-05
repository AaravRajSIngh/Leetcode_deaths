class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> g(n);

        for (auto &e : invocations)
            g[e[0]].push_back(e[1]);

        vector<int> vis(n, 0);

        function<void(int)> dfs = [&](int u) {
            vis[u] = 1;
            for (int v : g[u])
                if (!vis[v]) dfs(v);
        };

        dfs(k);

        // If a non-suspicious method invokes a suspicious one,
        // removal is impossible.
        for (auto &e : invocations) {
            if (!vis[e[0]] && vis[e[1]]) {
                vector<int> ans(n);
                iota(ans.begin(), ans.end(), 0);
                return ans;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (!vis[i]) ans.push_back(i);

        return ans;
    }
};