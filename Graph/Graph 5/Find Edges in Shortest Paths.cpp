class Solution {
    vector<int> Dijkstra(int src,vector<pair<int,int>>adj[],int n){
        vector<int> dist(n,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            int node_u=x.second;
            int dist_u=x.first;
            if(dist[node_u]<dist_u){
                continue;
            }
            for(auto e:adj[node_u]){
                int v=e.first,wt=e.second;
                if(dist_u+wt<dist[v]){
                    dist[v]=dist_u+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<edges.size();++i){
            int u=edges[i][0],v=edges[i][1],wt=edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int> dij=Dijkstra(0,adj,n);
        vector<int> rev=Dijkstra(n-1,adj,n);
        int mini=dij[n-1];
        int m=edges.size();
        vector<bool> ans(m,false);
        for(int i=0;i<m;++i){
            int u=edges[i][0],v=edges[i][1],wt=edges[i][2];
            if((dij[u]+wt+rev[v]==mini) || (dij[v]+wt+rev[u]==mini)){
                ans[i]=true;
            }
        }
        return ans;
    }
};
