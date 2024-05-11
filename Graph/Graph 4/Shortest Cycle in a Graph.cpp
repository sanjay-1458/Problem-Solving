class Solution {
private:
    unordered_map<int, vector<int>> adj;
    unordered_set<int> vis;
    int ans;

    void dfs(int node, vector<int> path) {
        if (vis.count(node) || !adj.count(node)) return;

        for (int i = path.size() - 2; i >= 0; --i) {
            if (find(adj[node].begin(), adj[node].end(), path[i]) != adj[node].end()) {
                ans = min(ans, (int)(path.size()) - i + 1);
                return;
            }
        }

        path.push_back(node);
        if (path.size() >= ans) return;

        vis.insert(node);
        for (int neighbor : adj[node]) {
            if (find(path.begin(), path.end(), neighbor) == path.end()) {
                dfs(neighbor, path);
            }
        }
        vis.erase(node);
    }

public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        ans = INT_MAX;
        adj.clear();
        vis.clear();
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for (int node = 0; node < n; ++node) {
            dfs(node, {});
            vis.insert(node);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
