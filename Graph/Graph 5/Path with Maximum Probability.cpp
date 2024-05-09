class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& e, vector<double>& s, int sn, int en) {
        vector<pair<int,double>> adj[n]; // node,wt
        for(int i=0;i<e.size();++i){
            adj[e[i][0]].push_back({e[i][1],s[i]});
            adj[e[i][1]].push_back({e[i][0],s[i]});
        }
        priority_queue<pair<double,int>> pq; // dist,node
        vector<int> vis(n,0);
        vector<double> dist(n,0);
        pq.push({1,sn});
        while(!pq.empty()){
            auto node=pq.top();
            pq.pop();
            double dist_u=node.first;
            int node_u=node.second;
            if(vis[node_u]) continue;
            vis[node_u]=1;
            if(node_u==en){
                return dist_u;
            }
            cout<<node_u<<endl;
            for(auto x:adj[node_u]){
                int v=x.first;
                double wt=x.second;
                if(vis[v]==0){
                    if(dist_u*wt>dist[v]){
                        dist[v]=dist_u*wt;
                        pq.push({dist[v],v});
                    }
                }
            }
        }
        return 0;
    }
};
