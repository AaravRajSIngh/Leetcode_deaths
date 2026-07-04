class Solution {
public:
    int ans = INT_MAX;

    void dfs(int u, vector<vector<pair<int,int>>>& adj, vector<int>& vis) {
        vis[u] = 1;

        for (auto &[v, w] : adj[u]) {
            ans = min(ans, w);
            if (!vis[v])
                dfs(v, adj, vis);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        vector<int> vis(n + 1, 0);
        dfs(1, adj, vis);

        return ans;
    }
};