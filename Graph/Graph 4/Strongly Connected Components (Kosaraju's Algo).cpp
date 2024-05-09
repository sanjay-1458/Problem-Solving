oid dfs(int node, vector<int> &vis, vector<int> adj[]) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj);
            }
        }
    }
    void fun(int node, vector<int> &vis, vector<vector<int>> graph,stack<int> &st) {
        vis[node] = 1;
        for (auto it : graph[node]) {
            if (!vis[it]) {
                fun(it, vis, graph, st);
            }
        }
        st.push(node);
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& graph)
    {
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                fun(i, vis, graph, st);
            }
        }

        vector<int> adj[V];
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (auto it : graph[i]) {
                adj[it].push_back(i);
            }
        }
        int scc = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                scc++;
                dfs(node, vis, adj);
            }
        }
        return scc;
