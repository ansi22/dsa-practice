class Solution {
public:
    vector<vector<pair<int, int>>> adj;
    vector<int> ans;

    int dfs1(int u, int p) {
        int total_cost = 0;
        for (auto& [v, weight] : adj[u]) {
            if (v != p) {
                total_cost += weight + dfs1(v, u);
            }
        }
        return total_cost;
    }

    void dfs2(int u, int p) {
        for (auto& [v, weight] : adj[u]) {
            if (v != p) {
                ans[v] = ans[u] + (weight == 0 ? 1 : -1);
                dfs2(v, u);
            }
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        adj.assign(n, vector<pair<int, int>>());
        ans.assign(n, 0);

        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }

        ans[0] = dfs1(0, -1);

        dfs2(0, -1);

        return ans;
    }
};