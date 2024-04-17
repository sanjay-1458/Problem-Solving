class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination) return true;
        vector<int> adj[n];
        for(int i=0;i<edges.size();++i){
            int u=edges[i][0],v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n);
        queue<int> q;
        q.push(source);
        vis[source]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto x:adj[node]){
                if(vis[x]==0){
                    vis[x]=1;
                    q.push(x);
                    if(x==destination) return true;
                }
            }
        }
        return false;
    }
};
