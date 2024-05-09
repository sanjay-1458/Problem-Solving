class Solution {
public:
    int flag = 0;
    double res = 1;
    
    void dfs(unordered_map<string, vector<pair<string, double>>>& graph, string s, string t, map<pair<string, string>, int>& vis, double ans) {
        if (graph[s].empty() || graph[t].empty()) {
            res = -1;
            return;
        }
        if (s == t) {
            flag = 1;
            res = ans;
            return;
        }
        int n = graph[s].size();
        for (int i = 0; i < n; i++) {
            if (!flag) {
                if (!vis[{s, graph[s][i].first}]) {
                    vis[{s, graph[s][i].first}] = 1;
                    dfs(graph, graph[s][i].first, t, vis, ans * graph[s][i].second);
                }
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
        unordered_map<string, vector<pair<string, double>>> graph;
        int n = e.size();
        for (int i = 0; i < n; i++) {
            graph[e[i][0]].push_back({ e[i][1], v[i] });
            graph[e[i][1]].push_back({ e[i][0], 1 / v[i] });
        }
        int nq = q.size();
        map<pair<string, string>, int> vis;
        vector<double> anss;
        for (int i = 0; i < nq; i++) {
            dfs(graph, q[i][0], q[i][1], vis, 1);
            if (res == 1 && flag == 0)
                anss.push_back(-1);
            else
                anss.push_back(res);
            vis.clear();
            flag = 0;
            res = 1;
        }
        return anss;
    }        
};
