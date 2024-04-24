class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<edges.size();++i){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<int> dist(n+1,1e9);
        dist[k]=0;
        q.push({0,k});
        while(!q.empty()){
            int node=q.top().second;

            int wt=q.top().first;
            q.pop();
            for(auto x:adj[node]){
                if(wt+x.second<dist[x.first]){
                    dist[x.first]=wt+x.second;
                    q.push({dist[x.first],x.first});
                }
            }
        }
        int ans=-1;
        for(int i=1;i<=n;++i){
            if(dist[i]==1e9){
                return -1;
            }
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};
