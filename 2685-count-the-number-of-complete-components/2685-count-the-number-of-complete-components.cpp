class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            vector<int> comp;
            stack<int> st;
            st.push(i);
            vis[i] = 1;

            while (!st.empty()) {
                int u = st.top();
                st.pop();
                comp.push_back(u);

                for (int v : adj[u]) {
                    if (!vis[v]) {
                        vis[v] = 1;
                        st.push(v);
                    }
                }
            }

            long long edgeCnt = 0;
            for (int u : comp)
                edgeCnt += adj[u].size();

            edgeCnt /= 2;

            long long k = comp.size();
            if (edgeCnt == k * (k - 1) / 2)
                ans++;
        }

        return ans;
    }
};